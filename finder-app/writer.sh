#!/bin/bash

# Check if arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Two arguments are required."
    exit 1
fi

file="$1"
str="$2"

mkdir -p "$(dirname "$file")"

#touch $filesdir
echo $str > $file
