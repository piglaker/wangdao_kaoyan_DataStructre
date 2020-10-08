#!/bin/bash

file=$1

name=`python3 -c "print('$file'.split('.')[0])"`

target="$name.out"

g++ $file -o $target
chmod +x $target
./$target


