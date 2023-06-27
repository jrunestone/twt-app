sudo apt update &&
sudo apt install -y g++ gcc build-essential libsystemd-dev libxrender-dev bison libdbus-1-dev libxi-dev libxtst-dev libxrandr-dev libx11-dev libxtst-dev libxt-dev libxinerama-dev libx11-xcb-dev libxkbcommon-dev libxkbcommon-x11-dev libxkbfile-dev &&

git clone https://github.com/Microsoft/vcpkg.git &&
./vcpkg/bootstrap-vcpkg.sh &&
./vcpkg/vcpkg install &&

mkdir -p lib
git clone https://github.com/kwhat/libuiohook lib/libuiohook &&
mkdir -p lib/libuiohook/build &&
cmake -B ./lib/libuiohook/build -S ./lib/libuiohook -D BUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=./lib/libuiohook/dist &&
cmake --build ./lib/libuiohook/build --parallel 2 --target install &&

mkdir -p build &&
cmake -B ./build -S ./