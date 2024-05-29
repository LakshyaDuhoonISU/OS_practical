#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int pipe_fds[2]; // File descriptors for the pipe

    // Create the pipe
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork(); // Fork a child process

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        close(pipe_fds[1]); // Close the write end of the pipe

        char buffer[BUFFER_SIZE];
        ssize_t num_bytes_read;

        // Read data from the pipe
        num_bytes_read = read(pipe_fds[0], buffer, BUFFER_SIZE);
        if (num_bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Child process received message from parent: %s\n", buffer);

        close(pipe_fds[0]); // Close the read end of the pipe
    } else {
        // Parent process
        close(pipe_fds[0]); // Close the read end of the pipe

        char message[] = "Hello from parent process!";
        
        // Write data to the pipe
        if (write(pipe_fds[1], message, sizeof(message)) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(pipe_fds[1]); // Close the write end of the pipe
    }

    return 0;
}
