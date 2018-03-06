#!/bin/sh
set -eu

mpiexec.mpich -l -n 2 py-eval -v controller/start.py 0
