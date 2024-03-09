#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Error: Please provide two arguments: filesdir and searchstr"
    exit 1
fi

filesdir="$1"
searchstr="$2"

if [ ! -d "$filesdir" ]; then
    echo "Error: $filesdir is not a directory"
    exit 1
fi

output=$(grep -r "$searchstr" "$filesdir")

num_files=$(find "$filesdir" -type f | wc -l)

num_matching_lines=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "--------------------"
echo "$output"
echo "--------------------"

echo "The number of files are $num_files and the number of matching lines are $num_matching_lines"
