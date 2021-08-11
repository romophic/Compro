#!/bin/bash

function copy () {
  if type "clip.exe" > /dev/null 2>&1; then
    'cat' | clip.exe
    exit
  fi

  if type "pbcopy" > /dev/null 2>&1; then
    'cat' | pbcopy
    exit
  fi

  if type "xclip" > /dev/null 2>&1; then
    'cat' | xclip -in -sel clip
    exit
  fi

  echo "Not found command for copy" >&2
}

copy < ./src/main.cpp &
mkdir build > /dev/null 2>&1
g++ -std=gnu++17 -O2 -g -pipe -D DEBUG ./src/main.cpp -o ./build/main

echo "////////// build/main //////////"
./build/main
