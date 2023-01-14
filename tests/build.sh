#!/bin/bash

PROJECT_NAME="cmath_tests"
OUTPUT_NAME="./build/$PROJECT_NAME"

if [[ "$OSTYPE" == "linux-gnu"* ]];
then

    OUTPUT_NAME+=".a"
    
elif [[ "$OSTYPE" == "msys"* ]];
then
    
    OUTPUT_NAME+=".exe"
else

    echo $OSTYPE
    echo "unknown os"
    exit 1
fi


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

gcc $PREPROCESSOR $COMPILER_FLAGS $WARNINGS $INCLUDE_FOLDERS "./src/test_main.c" -lm -o $OUTPUT_NAME

popd

exit 0
exit 1

