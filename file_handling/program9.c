#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int file;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    int lineCount = 0;

    // Open the file for reading
    file = open("example.txt", O_RDONLY);
    if (file == -1) {
        perror("Error opening file");
        return 1;
    }

    // Count the number of lines in the file
    while ((bytesRead = read(file, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                lineCount++;
            }
        }
    }

    // Check for read errors
    if (bytesRead == -1) {
        perror("Error reading file");
        close(file);
        return 1;
    }

    // Close the file
    close(file);

    // Increment line count for the last line if it doesn't end with a newline
    if (bytesRead > 0 && buffer[bytesRead - 1] != '\n') {
        lineCount++;
    }

    printf("Number of lines in the file: %d\n", lineCount);

    return 0;
}
