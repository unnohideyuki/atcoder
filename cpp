#!/bin/bash -v
f=$1
bname1=`basename $f .cpp`
bname=`basename $bname1 .cc`
g++-11 -std=gnu++17 -O2 -Wall -Wconversion -I../ac-library -ftrapv -D _GLIBCXX_DEBUG -o $bname $f

if [ $? != 0 ]; then
   exit $?
fi

# NO DEBUG compile
g++-11 -std=gnu++17 -O2 -Wall -Wconversion -I../ac-library -ftrapv -o ${bname}-nd $f



