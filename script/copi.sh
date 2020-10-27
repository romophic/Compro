#!/bin/sh

stdin=`cat`

if [ "$(uname)" = 'Darwin' ]; then #Mac
  echo $stdin | pbcopy
else #Linux
  echo $stdin | xclip -in -sel clip
fi
