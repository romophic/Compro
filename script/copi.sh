#!/bin/sh

if [ "$(uname)" = 'Darwin' ]; then #Mac
  'cat' | pbcopy
else                               #Linux
  'cat' | xclip -in -sel clip
fi
