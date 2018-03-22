#!/bin/sh
set -eu

# TEST KERAS MNIST SHORT SH

# USER SETTINGS START
# Change these for your system
MPIEXEC=mpiexec.mpich
# USER SETTINGS END

THIS=$( cd $( dirname $0 ) ; /bin/pwd )
cd $THIS/..
make tests/test-keras_mnist_short.x
cd $THIS

HOROVOD=$( cd $THIS/../.. ; /bin/pwd )
EXAMPLE_MNIST=$HOROVOD/examples/keras_mnist_short.py

if ! $MPIEXEC -n 2 ./test-keras_mnist_short.x $EXAMPLE_MNIST
then
  echo "TEST FAIL"
  exit 1
fi

echo "TEST OK"
exit 0
