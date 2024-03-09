#!/bin/sh

# Check if arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Two arguments are required."
    exit 1
fi

filesdir="$1"
searchstr="$2"

# Check if filesdir exists and is a directory
if [ ! -d "$filesdir" ]; then
    echo "Error: $filesdir is not a directory."
    exit 1
fi

file_count=$(find "$filesdir" -type f | wc -l)
matching_lines=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are $file_count and the number of matching lines are $matching_lines"
