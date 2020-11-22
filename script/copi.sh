#!/bin/bash

#     ____            _    #
#    / ___|___  _ __ (_)   #
#   | |   / _ \| '_ \| |   #
#   | |__| (_) | |_) | |   #
#    \____\___/| .__/|_|   #
#              |_|         #
#      Made by NULLCT      #

if type "clip.exe" > /dev/null 2>&1; then
  'cat' | clip.exe
  echo "Copy by clip"
  exit
fi

if type "pbcopy" > /dev/null 2>&1; then
  'cat' | pbcopy
  echo "Copy by pbcopy"
  exit
fi

if type "xclip" > /dev/null 2>&1; then
  'cat' | xclip -in -sel clip
  echo "Copy by xclip"
  exit
fi

echo "Not found command for copy" >&2 # 404