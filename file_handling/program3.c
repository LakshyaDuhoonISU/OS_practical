#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define NUM_BYTES 10

int main() {
    int file;
    off_t file_size;
    char buffer[NUM_BYTES + 1]; // +1 for null-terminator
    ssize_t bytesRead;

    // Open the file in read-only mode
    file = open("dummy.txt", O_RDONLY);
    if (file == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Get the file size
    file_size = lseek(file, 0, SEEK_END);
    if (file_size == -1) {
        perror("Error getting file size");
        close(file);
        return EXIT_FAILURE;
    }

    // Check if the file is smaller than NUM_BYTES
    if (file_size < NUM_BYTES) {
        fprintf(stderr, "File is smaller than %d bytes.\n", NUM_BYTES);
        close(file);
        return EXIT_FAILURE;
    }

    // Move the file pointer to NUM_BYTES before the end
    off_t offset = lseek(file, -NUM_BYTES, SEEK_END);
    if (offset == -1) {
        perror("Error setting file pointer");
        close(file);
        return EXIT_FAILURE;
    }

    // Read the last NUM_BYTES bytes from the file
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
    printf("Last %d bytes: %s\n", NUM_BYTES, buffer);

    // Close the file
    close(file);

    return EXIT_SUCCESS;
}
