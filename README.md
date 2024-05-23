# Build Instructions

```bash
mkdir build
cd build
conan install ../ --build=missing -of .
cmake --preset=conan-2 ../

```