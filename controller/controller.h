
/**
   CONTROLLER H
*/

#pragma once

/**
   comm: The communicator to run on
   code: The Python code (the Horovod program)
*/
int controller(MPI_Comm comm, char* code);
