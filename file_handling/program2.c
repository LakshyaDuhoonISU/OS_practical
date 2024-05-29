#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file;

    // Creating and opening the file for writing
    file = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file == -1) {
        perror("Error creating file");
        return EXIT_FAILURE;
    }

    // Writing some content to the file
    if (dprintf(file, "This is a line of text.\n") < 0 ||
        dprintf(file, "This is another line of text.\n") < 0) {
        perror("Error writing to file");
        close(file);
        return EXIT_FAILURE;
    }

    // Closing the file
    if (close(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    // Reopening the file for reading
    file = open("example.txt", O_RDONLY);
    if (file == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Reading and printing the content of the file
    char buffer[256];
    ssize_t bytesRead;
    while ((bytesRead = read(file, buffer, sizeof(buffer))) > 0) {
        if (write(STDOUT_FILENO, buffer, bytesRead) < 0) {
            perror("Error writing to stdout");
            close(file);
            return EXIT_FAILURE;
        }
    }
    if (bytesRead == -1) {
        perror("Error reading file");
        close(file);
        return EXIT_FAILURE;
    }

    // Closing the file again
    if (close(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
