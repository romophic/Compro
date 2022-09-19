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
rm a.out
g++ -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover -fstack-protector -pipe -DDEBUG  -std=c++17 -O3 ./src/main.cpp
