#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open a file for writing using fcntl
    int file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Check if file opened successfully
    if (file == -1) {
        printf("Error opening file.\n");
        return 1;
    }

    // Write "Hello, World!" to the file
    if (write(file, "Hello, World!\n", 14) != 14) {
        printf("Error writing to file.\n");
        close(file);
        return 1;
    }

    // Close the file
    close(file);

    printf("Data written to file successfully.\n");
    
    return 0;
}
