### Unit test of mmath

* [googletest](https://github.com/google/googletest) is required.
* gcc is required.
* This library is intents to run on microcontrollers, unit-testing with msvc is meaningless unless using Windows system.

#### Steps

1. create directory `mkdir build`
2. change to build directory `cd build`
3. run cmake `cmake ..`, or `cmake .. -G"MinGW Makefiles"` for MinGW, or `cmake .. -G"MSYS Makefiles"` for MSYS on Windows
4. make unit test project `make`
5. run all unit test `make test`, or run single test like `mmath-util.exe`
