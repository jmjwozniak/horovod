
CC = mpicc.mpich

HOROVOD = ${HOME}/proj/horovod
CONTROLLER = $(HOROVOD)/controller

INCLUDE_CONTROLLER = -I$(CONTROLLER)

INCLUDES = $(INCLUDE_CONTROLLER)

CPPFLAGS = $(INCLUDES)
CFLAGS = -fPIC

LIB_PYTHON = -L /usr/lib/python2.7/config-x86_64-linux-gnu -l python2.7

LINKFLAGS = -L$(CONTROLLER) -l controller \
		$(LIB_PYTHON)

RPATHS = -Wl,-rpath -Wl,$(CONTROLLER)

all: Makefile
	echo "No target for all"

test-keras_mnist_short.x: test-keras_mnist_short.o
	$(CC) -o $(@) $(<) $(CFLAGS) \
		$(LIB_PYTHON) \
		$(RPATHS)
