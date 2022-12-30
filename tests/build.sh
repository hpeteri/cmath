#!/bin/bash

PROJECT_NAME="cmath_tests"

WARNINGS="-Wformat=2 
          -Wmain 
          -Wparentheses 
          -Wuninitialized
          -Wsign-compare 
          -Werror"

COMPILER_FLAGS=""
INCLUDE_FOLDERS="-I ../ "

pushd "$(dirname ${BASH_SOURCE[0]})"

if [ ! -d "build" ]
then
    mkdir build
fi

# command line arguments
if [[ $1 == "debug" ]]
then
    echo "debug build"
    COMPILER_FLAGS="-O0 $COMPILER_FLAGS"
    PREPROCESSOR="-g"
else
    echo "release build"
    COMPILER_FLAGS="-O3 $COMPILER_FLAGS"
    PREPROCESSOR="-s"
fi

gcc $PREPROCESSOR $COMPILER_FLAGS $WARNINGS $INCLUDE_FOLDERS "./src/test_main.c" -lm -o "./build/tests.a"

popd

exit 0
