
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    char file_1_path[256], file_2_path[256];

    printf("Insert the first file path: ");
    scanf("%255s", file_1_path); 


    printf("Insert the second file path: ");
    scanf("%255s", file_2_path);

    int fd_1 = open(file_1_path, O_RDONLY);

    if (fd_1 < 0) {
        perror("Errors while opening the first file");
        exit(1);
    }

    int fd_2 = open(file_2_path, O_RDONLY);

    if (fd_2 < 0) {
        perror("Errors while opening the second file");
        exit(1);
    }

    char content_1[256], content_2[256];

    off_t byte_counter = 0, difference_index = -1;

    int files_differ = 0, comparison_error = 0, files_identical = 0;

    while (1) {
        size_t bytes_read_1 = 0, bytes_read_2 = 0;

        while (bytes_read_1 < sizeof(content_1)) {
            ssize_t read_result_1 = read(fd_1, content_1 + bytes_read_1, sizeof(content_1) - bytes_read_1);

            if (read_result_1 < 0) {
                perror("Reading the first file failed");
                comparison_error = 1;
                break;
            } else if (read_result_1 == 0) {
                break;
            }

            bytes_read_1 += read_result_1;
        }

        if (comparison_error) {
            break;
        }

        while (bytes_read_2 < sizeof(content_2)) {
            ssize_t read_result_2 = read(fd_2, content_2 + bytes_read_2, sizeof(content_2) - bytes_read_2);

            if (read_result_2 < 0) {
                perror("Reading the second file failed");
                comparison_error = 1;
                break;
            } else if (read_result_2 == 0) {
                break;
            }

            bytes_read_2 += read_result_2;
        }

        if (comparison_error) {
            break;
        }

        size_t bytes_to_compare = bytes_read_1;

        if (bytes_read_2 < bytes_to_compare) {
            bytes_to_compare = bytes_read_2;
        }

        for (size_t i = 0; i < bytes_to_compare; i++) {
            if (content_1[i] != content_2[i]) {
                difference_index = byte_counter + i;
                files_differ = 1;
                break;
            }
        }

        if (files_differ) {
            break;
        }

        if (bytes_read_1 != bytes_read_2) {
            difference_index = byte_counter + bytes_to_compare;
            files_differ = 1;
            break;
        }

        if (bytes_read_1 == 0) {
            files_identical = 1;
            break;
        }

        byte_counter += bytes_read_1;
    }

    close(fd_1);
    close(fd_2);

    if (comparison_error) {
        exit(1);
    }

    if (files_differ) {
        printf("Files differ at byte %lld\n", (long long)difference_index);
        exit(1);
    }

    if (files_identical) {
        printf("Files are identical\n");
    }

    return 0;
}