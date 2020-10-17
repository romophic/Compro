if [ "$(uname)" = 'Darwin' ]; then #Mac
  cat src/main.cpp | pbcopy
else #Linux
  cat src/main.cpp | xclip -in -sel clip
fi
