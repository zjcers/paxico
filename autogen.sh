#!/bin/sh
autoreconf --install
automake --add-missing
libtoolize
mkdir -p build
