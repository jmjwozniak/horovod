
CC = mpicc.mpich

PYTHON = /usr/include/python2.7
TCL = /usr/include/tcl8.6

INCLUDES = -I $(PYTHON) -I $(TCL)

CPPFLAGS = $(INCLUDES)
CFLAGS = -fPIC

all: libcontroller.so

libcontroller.so: controller.o
	$(CC) -shared -o $(@) $(<)

clean:
	@rm -fv *.so *.o
