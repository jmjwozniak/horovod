
/*
  TEST KERAS MNIST SHORT C

  Example of how to run a Horovod program using the controller
  Reads a Horovod Python program as a string,
  creates a child communicator,
  and passes that communicator and program to the Horovod controller.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include <mpi.h>

#include <controller.h>

static void usage(void);
static char* slurp(const char* filename);
static int do_controller(char* code);

int
main(int argc, char* argv[]) {

  // Check arguments
  if (argc != 2) {
    usage();
    exit(1);
  }

  // Read code
  char* code = slurp(argv[1]);
  if (code == NULL)
    exit(1);

  // Run it
  int rc = do_controller(code);

  // Clean up and return
  free(code);
  if (rc == 0)
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}

static int do_controller(char* code) {
  MPI_Init(0, 0);
  MPI_Comm child;
  MPI_Comm_dup(MPI_COMM_WORLD, &child);

  // Call to controller library
  int rc = controller(child, code);

  MPI_Finalize();
  return rc;
}

static void
usage() {
  printf("usage: test-controller.x <FILE>\n");
}

/**
   slurp(): Utility function to read a file
   @return File contents in freshly allocated memory
*/
static char*
slurp(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("slurp(): could not read from: %s\n", filename);
    return NULL;
  }

  struct stat s;
  int rc = stat(filename, &s);
  if (rc != 0) {
    printf("slurp(): could not stat: %s\n", filename);
    return NULL;
  }

  off_t length = s.st_size;
  char* result = malloc((size_t)length+1);
  if (result == NULL) {
    printf("slurp(): could not allocate memory for: %s\n", filename);
    return NULL;
  }

  char* p = result;
  int actual = (int)fread(p, sizeof(char), (size_t)length, file);
  if (actual != length) {
    printf("could not read all %li bytes from file: %s\n",
           (long) length, filename);
    free(result);
    return NULL;
  }
  result[length] = '\0';

  fclose(file);
  return result;
}
