mkdir -p build
cd build
pwd
cmake CMAKE_PREFIX_PATH="/Users/DaZzz/Qt/5.3/clang_64/" CMAKE_CXX_FLAGS="-std=c++0x -stdlib=libc++ -g3 -Wall -O0 -Wc++11-extensions" ../sources
make
./lab03