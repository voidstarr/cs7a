#!/bin/bash
# because I'm tired of typing this over and over
TO_COMP=`find . -name '*.cpp' | xargs`
clang++-3.8 -std=c++14 -o $1 $TO_COMP
