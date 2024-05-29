#!/bin/zsh

# Script to display the last 20 lines of all .log files in the current directory

for log_file in *.log; do
  # Check if there are any .log files to process
  if [[ -e "$log_file" ]]; then
    echo "Displaying last 20 lines of: $log_file"
    echo "-------------------------------------"
    # Display the last 20 lines of the log file
    tail -n 20 "$log_file"
    echo "\n"  # Add a newline for better readability
  else
    echo "No .log files found in the current directory."
    break
  fi
done

