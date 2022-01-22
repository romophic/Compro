#!/bin/bash

function copy () {
  tr=false

  if type "clip.exe" > /dev/null 2>&1; then
    'cat' | clip.exe
    tr=true
  fi

  if type "pbcopy" > /dev/null 2>&1; then
    'cat' | pbcopy
    tr=true
  fi

  if type "xclip" > /dev/null 2>&1; then
    'cat' | xclip -in -sel clip
    tr=true
  fi

  if "${tr}";then
    return 0
  else
    return 1
  fi
}

copy < ./src/main.cpp && echo "👍"
mkdir build &> /dev/null
rm -v ./build/main
clang++ -std=c++17 -Og -g -pipe -D DEBUG ./src/main.cpp -o ./build/main && lldb ./build/main
