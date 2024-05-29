#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main() {
    // File path to check
    char filename[100];
    scanf("%s", filename);

    // Attempt to open the file with read-only mode
    int fd = open(filename, O_RDONLY);

    // Check if file exists
    if (fd != -1) {
        printf("File exists.\n");
        // Close the file descriptor
        close(fd);
    } else {
        printf("File does not exist or cannot be opened.\n");
    }

    return 0;
}
