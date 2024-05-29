#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int sourceFile, destinationFile;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Open the source file for reading
    sourceFile = open("dummy.txt", O_RDONLY);
    if (sourceFile == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Open the destination file for writing
    destinationFile = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destinationFile == -1) {
        perror("Error opening destination file");
        close(sourceFile);
        return 1;
    }

    // Copy content from source file to destination file
    while ((bytesRead = read(sourceFile, buffer, BUFFER_SIZE)) > 0) {
        if (write(destinationFile, buffer, bytesRead) != bytesRead) {
            perror("Error writing to destination file");
            close(sourceFile);
            close(destinationFile);
            return 1;
        }
    }

    // Check for read errors
    if (bytesRead == -1) {
        perror("Error reading source file");
        close(sourceFile);
        close(destinationFile);
        return 1;
    }

    // Close both files
    close(sourceFile);
    close(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}
