#!/bin/sh
set -eu

THIS=$( dirname $0 )

mpiexec.mpich -l -n 2 py-eval -v $THIS/start.py 0
