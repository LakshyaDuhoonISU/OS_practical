#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    // Path to the file whose permissions will be changed
    const char *file_path = "dummy.txt";

    // New file permissions (in octal)
    mode_t new_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // Read and write for owner, read for group and others

    // Change file permissions using chmod system call
    if (chmod(file_path, new_permissions) == -1) {
        perror("chmod");
        exit(EXIT_FAILURE);
    }

    printf("File permissions changed successfully.\n");

    return 0;
}
