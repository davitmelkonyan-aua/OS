#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int write_fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (write_fd < 0) {
        perror("Opening data.txt file failed");
		exit(1);
    }

    ssize_t initial_write = write(write_fd, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);

    if (initial_write < 0) {
        perror("initial write failed");
		exit(1);
    }

    close(write_fd);

    int read_write_fd = open("data.txt", O_RDWR);

    if (read_write_fd < 0) {
        perror("reopening the file failed");
		exit(1);
    }
    
    off_t size = lseek(read_write_fd, 0, SEEK_END);

    if (size < 0) {
        perror("lseek failed");
		exit(1);
    }

    printf("The file is currently %d bytes \n", (int)size);
    
    if (ftruncate(read_write_fd, 10) < 0) {
        perror("ftruncate failed");
		exit(1);
    }

    off_t new_size = lseek(read_write_fd, 0, SEEK_END);

    if (new_size < 0) {
        perror("lseek failed");
		exit(1);
    }

    printf("The file is now %d bytes \n", (int)new_size);

    off_t rewind = lseek(read_write_fd, 0, SEEK_SET);

    if (rewind < 0) {
        perror("lseek failed");
		exit(1);
    }

    char buffer[new_size];
    ssize_t read_bytes = read(read_write_fd, buffer, new_size);

    if (read_bytes < 0) {
        perror("read failed");
		exit(1);
    }

    ssize_t write_bytes = write(1, buffer, read_bytes);

    if (write_bytes < 0) {
        perror("write failed");
		exit(1);
    }

    printf("\n");

    close(read_write_fd);

    return 0;
}