###
# Make build
###
cd task13
pwd
make
../_build/test-sort


###
# Cmake build
###

cd _build
mkdir -p cmake-build
cd cmake-build
cmake ../../task13/
make
./test-sort/test-sort