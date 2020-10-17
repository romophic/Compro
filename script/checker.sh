#!/bin/bash

noerror=true

if [ ! -d "build" ]; then
  noerror=false
  echo "ERROR: build folder not found"
  mkdir build
fi

if $noerror ; then
  echo "No error!"
fi

echo "Check is over"
