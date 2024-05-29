#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Path to the file whose owner will be changed
    const char *file_path = "dummy.txt";

    // New owner user ID and group ID (you may need to change these values)
    uid_t new_owner_uid = 1001; // Replace with the desired user ID
    gid_t new_owner_gid = 1001; // Replace with the desired group ID

    // Change file owner using chown system call
    if (chown(file_path, new_owner_uid, new_owner_gid) == -1) {
        perror("chown");
        exit(EXIT_FAILURE);
    }

    printf("File owner changed successfully.\n");

    return 0;
}
