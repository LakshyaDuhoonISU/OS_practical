#!/bin/zsh

# Script to rename all .txt files to .bak in the current directory

for txt_file in *.txt; do
  # Check if there are any .txt files to process
  if [[ -e "$txt_file" ]]; then
    # Construct the new filename with .bak extension
    bak_file="${txt_file%.txt}.bak"
    # Rename the file
    mv -v "$txt_file" "$bak_file"
  else
    echo "No .txt files found in the current directory."
    break
  fi
done

