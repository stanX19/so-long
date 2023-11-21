#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1000

int main() {
    // File descriptor
    int file_descriptor;

    // Open the file for reading
    file_descriptor = open("assets/map/map1.ber", O_RDONLY);

    // Check if the file opened successfully
    if (file_descriptor == -1) {
        perror("Unable to open the file");
        return 1; // Exit with an error code
    }

    // Buffer to store each line
    char buffer[BUFFER_SIZE];

    // Read and print each line until the end of the file
    ssize_t bytesRead;
    while ((bytesRead = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    // Close the file
    if (close(file_descriptor) == -1) {
        perror("Error closing the file");
        return 1; // Exit with an error code
    }

    return 0; // Exit successfully
}
