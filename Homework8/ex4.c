#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd < 0) {
        perror("Errors while openning the file");
        exit(1);
    }

    char input[256];
    ssize_t read_result = read(0, input, sizeof(input));

    if (read_result < 0) {
        perror("Errors while reading from the file");
        exit(1);
    } else if (read_result == 0) {
        printf("The input was empty");
        return 0;
    }

    if (input[read_result - 1] != '\n') {
        input[read_result] = '\n';
        read_result++;
    }

    pid_t pid = getpid();
    char pid_string[20];
    int pid_length = snprintf(pid_string, sizeof(pid_string), "PID=%d: ", (int)pid);

    ssize_t write_1 = write(fd, pid_string, pid_length);
    
    if (write_1 < 0) {
        perror("Errors while writing to the file");
        exit(1);
    }

    ssize_t write_2 = write(fd, input, read_result);
    
    if (write_2 < 0) {
        perror("Errors while writing to the file");
        exit(1);
    }

    off_t lseek_result = lseek(fd, 0, SEEK_CUR);

    if (lseek_result < 0) {
        perror("Errors with the lseek");
        exit(1);
    }

    printf("The offset is at: %d \n", (int)lseek_result);
    close(fd);

	return 0;
}

// O_APPEND moves each write to the end of the file, and the file offset advances after each successful write. Therefore, SEEK_CUR returns the growing offset even with O_APPEND