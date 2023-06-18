## Dependencies
libsystemd-dev
libxrender-dev
bison
libdbus-1-dev libxi-dev libxtst-dev
lixrandr-dev

## Build
```
./vcpkg/vcpkg install
mkdir -p ./build && cd build
cmake ..
cmake --build .
```