#!/bin/bash

EMSDK="$HOME/emsdk"

SCRIPT_PATH="$(cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P)"

SOURCE_PATH="$SCRIPT_PATH"
BUILD_PATH="$SCRIPT_PATH/build"

source "$EMSDK/emsdk_env.sh"

rm -rf "$BUILD_PATH"
mkdir -p "$BUILD_PATH"

cd "$BUILD_PATH"

emcmake cmake \
    -D CMAKE_BUILD_TYPE=Release \
    ..

cmake \
    --build .

if [ "$1" == "" ] || [ $# -gt 1 ] || [ $1 != "--no_browser" ]; then
    emrun \
        --serve_root "$BUILD_PATH" \
        --hostname localhost \
        "test/test.htm"
else
    emrun \
        --serve_root "$BUILD_PATH" \
        --hostname localhost \
        --no_browser \
        "test/test.htm"
fi
