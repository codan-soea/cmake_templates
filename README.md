# cmake_templates
Cmake templates

Folder structure

cmake_templates
|-main
| |-include
| | '-main.h
| |-source
| | |-main.cpp
| | '-CMakeLists.txt
| '-CMakeLists.txt 
|-lib
| |-include
| | '-io.h
| |-source
| | |-io.cpp
| | '-CMakeLists.txt
| '-CMakeLists.txt
'-CMakeLists.txt

Building

mkdir build
cd build
cmake ../
build

Running 
cd build/main/source/
ls -al
./main

Installing
sudo apt-get install libzmq3-dev
