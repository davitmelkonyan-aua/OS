#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("sparse.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("Errors while openning the file");
        exit(1);
    }

    ssize_t write_1 = write(fd, "Start", sizeof("Start"));

    if (write_1 < 0) {
        perror("The first write failed");
        exit(1);
    }

    off_t lseek_1 = lseek(fd, 1024*1024, SEEK_CUR);

    if (lseek_1 < 0) {
        perror("Lseek 1 failed");
        exit(1);
    }

    ssize_t write_2 = write(fd, "End", sizeof("End"));

    if (write_2 < 0) {
        perror("The second write failed");
        exit(1);
    }

    close(fd);

    fd = open("sparse.bin", O_RDONLY);

    if (fd < 0) {
        perror("Errors while openning the file");
        exit(1);
    }

    off_t lseek_2 = lseek(fd, 0, SEEK_END);

    if (lseek_2 < 0) {
        perror("Lseek 2 failed");
        exit(1);
    }

    printf("The file size is: %ld \n", (long)lseek_2);
    close(fd);

	return 0;
}

// The file contains a large hole (unallocated region) because lseek() moved the file offset without writing zeros. But that does not mean
// there will be as much storage allocated, it would be useless, so the OS returns 0 bytes when reading to that region, without us
// writing them.