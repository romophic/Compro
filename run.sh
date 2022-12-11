#!/bin/bash

rm main
make main
g++ -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover -fstack-protector -pipe -DDEBUG  -std=c++17 -O3 ./src/main.cpp
