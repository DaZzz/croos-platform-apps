#!/bin/bash

ROOT_PATH=`pwd`

###
# Make build
###
cd $ROOT_PATH
cd task13
pwd
make
../_build/make-build/test-sort


###
# Cmake build
###
cd $ROOT_PATH
cd _build
mkdir -p cmake-build
cd cmake-build
cmake ../../task13/
make
./test-sort/test-sort