#!/bin/sh
set -eu

# TEST KERAS MNIST SHORT SH

THIS=$( cd $( dirname $0 ) ; /bin/pwd )
cd $THIS/..
make
cd $THIS

make test-keras_mnist_short.x
if mpiexec.mpich -n 2 ./test-keras_mnist_short.x
then
  echo "TEST OK"
else
  echo "TEST FAIL"
fi
