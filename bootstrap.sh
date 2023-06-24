sudo apt update
sudo apt install -y libsystemd-dev libxrender-dev bison libdbus-1-dev libxi-dev libxtst-dev libxrandr-dev g++ gcc build-essential
#git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install
mkdir build
cmake -B./build -S./