#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd = open("numbers.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("Errors while openning the file");
        exit(1);
    }

    ssize_t entire_content_size = 0, write_result;
    char line[20];

    for (int i = 1; i <= 10; i++) {
        int length = snprintf(line, sizeof(line), "%d\n", i);

        write_result = write(fd, line, length);

        if (write_result < 0) {
            perror("Write failed");
            exit(1);
        }

        entire_content_size += write_result;
    }

    close(fd);

    fd = open("numbers.txt", O_RDWR);

    if (fd < 0) {
        perror("Errors while openning the file");
        exit(1);
    }

    off_t lseek_to_the_start = lseek(fd, 0, SEEK_SET);

    if (lseek_to_the_start < 0) {
        perror("Errors with lseek");
        exit(1);
    }

    char* content = (char*)(malloc(entire_content_size));

    if (!content) {
        perror("Memmory allocation failed");
        exit(1);
    }

    ssize_t entire_file = read(fd, content, entire_content_size);

    if (entire_file < 0) {
        perror("Reading the file failed");
        exit(1);
    }

    int byte_counter = 0;
    while(content[byte_counter] != '4') {
        byte_counter++;
    }

    off_t lseek_to_4 = lseek(fd, byte_counter + 2, SEEK_SET);

    if (lseek_to_4 < 0) {
        perror("Lseek to 4 failed");
        exit(1);
    }

    ssize_t remainder_bytes = entire_content_size - (byte_counter + 2);
    char* remainder = (char*)(malloc(remainder_bytes));

    if (!remainder) {
        perror("Memmory allocation failed");
        exit(1);
    }

    ssize_t read_the_remainder = read(fd, remainder, remainder_bytes);

    if (read_the_remainder < 0) {
        perror("Reading the file failed");
        exit(1);
    }

    lseek_to_4 = lseek(fd, byte_counter, SEEK_SET);
    
    if (lseek_to_4 < 0) {
        perror("Lseek to 4 failed");
        exit(1);
    }

    ssize_t write_100 = write(fd, "100\n", 4);

    if (write_100 < 0) {
        perror("Write of 100 failed");
        exit(1);
    }

    ssize_t write_the_remainder = write(fd, remainder, remainder_bytes);

    if (write_the_remainder < 0) {
        perror("Write of the remainder failed");
        exit(1);
    }

    lseek_to_the_start = lseek(fd, 0, SEEK_SET);

    if (lseek_to_the_start < 0) {
        perror("Lseek to the start failed");
        exit(1);
    }

    char* final_content = (char*)(malloc(23));

    if (!final_content) {
        perror("Memmory allocation failed");
        exit(1);
    }

    ssize_t final_result = read(fd, final_content, 23);

    write(1, final_content, final_result);

    close(fd);
    free(content);
    free(remainder);
    free(final_content);

	return 0;
}
