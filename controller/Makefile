
# HOROVOD CONTROLLER MAKEFILE

# USER SETTINGS START
# Change these for your system
CC             = mpicc.mpich
HOROVOD        = ${HOME}/proj/horovod
CONTROLLER     = $(HOROVOD)/controller
# PYTHON_VERSION = 2.7
# PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
# PYTHON_LIB     = /usr/lib/python$(PYTHON_VERSION)/config-x86_64-linux-gnu
PYTHON_VERSION = 3.6m
PYTHON_INCLUDE = /usb1/sfw/anaconda3/include/python$(PYTHON_VERSION)
PYTHON_LIB     = /usb1/sfw/anaconda3/lib
TCL_INCLUDE    = /usr/include/tcl8.6
# USER SETTINGS END

INCLUDES = -I $(PYTHON_INCLUDE) -I $(TCL_INCLUDE) -I $(CONTROLLER)

CPPFLAGS = $(INCLUDES)
CFLAGS = -fPIC -fmax-errors=1

INCLUDE_CONTROLLER = -I$(CONTROLLER)

LIBS = -L $(PYTHON_LIB) -l python$(PYTHON_VERSION)

include tests/module.mk

all: libcontroller.so

controller.o: Makefile

libcontroller.so: controller.o Makefile
	$(CC) -shared -o $(@) $(<)

clean:
	@rm -fv *.so *.o
