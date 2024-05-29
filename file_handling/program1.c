#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define NUM_BYTES 10

int main() {
    int file;
    char buffer[NUM_BYTES + 1]; // +1 for null-terminator
    ssize_t bytesRead;

    // Open the file in read-only mode
    file = open("dummy.txt", O_RDONLY);
    if (file == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the first NUM_BYTES bytes from the file
    bytesRead = read(file, buffer, NUM_BYTES);
    if (bytesRead < NUM_BYTES) {
        if (bytesRead == 0) {
            printf("End of file reached.\n");
        } else if (bytesRead == -1) {
            perror("Error reading file");
            close(file);
            return EXIT_FAILURE;
        }
    }

    // Null-terminate the buffer to make it a valid string
    buffer[bytesRead] = '\0';

    // Print the read bytes
    printf("First %d bytes: %s\n", NUM_BYTES, buffer);

    // Close the file
    close(file);

    return EXIT_SUCCESS;
}
