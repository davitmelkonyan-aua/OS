
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char file_name[256];

    printf("Write the path to the file: ");
    scanf("%255s", file_name);

    int fd = open(file_name, O_RDONLY);

    if (fd < 0) {
        perror("Opening the file failed");
        exit(1);
    }

    off_t size = lseek(fd, 0, SEEK_END);

    if (size < 0) {
        perror("lseek failed");
        close(fd);
        exit(1);
    } else if (size == 0) {
        printf("\n");
        close(fd);
        return 0;
    }

    printf("The file is %lld bytes\n", (long long)size);

    char c;
    off_t lseek_result;
    ssize_t read_result;

    for (off_t i = size - 1; i >= 0; i--) {
        lseek_result = lseek(fd, i, SEEK_SET);

        if (lseek_result < 0) {
            perror("lseek failed");
            exit(1);
        }

        read_result = read(fd, &c, 1);

        if (read_result < 0) {
            perror("read failed");
            close(fd);
            exit(1);
        }

        if (read_result == 0) {
            break;
        }

        write(1, &c, 1);
    }

    printf("\n");
    close(fd);

    return 0;
}