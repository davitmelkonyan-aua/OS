#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	char source_file_path[256], destination_file_path[256];
	
	printf("Insert the read file path: ");
	scanf("%255s", source_file_path);
	printf("Insert the destination file path");
	scanf("%255s", destination_file_path);

	int read_fd = open(source_file_path, O_RDONLY);
	
	if (read_fd < 0) {
		perror("Opening the read file failed");
		exit (1);
	}
	
	int write_fd = open(destination_file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (write_fd < 0) {
		perror("Opening the write file failed");
		exit (1);
	}
	
	char* buffer = (char*)(malloc(50));
	
	if (!buffer) {
		perror("Memmory allocation failed");
		exit (1);
	}
	
	int read_result, total;

	while((read_result = read(read_fd, buffer, 50)) > 0) {
		write(write_fd, buffer, read_result);
		total += read_result;
	}

	if (read_result < 0) {
		perror("Errors while reading from the file");
	}

	printf("Overall %d bytes of text was transfered \n", total);

	free(buffer);
	close(read_fd);
	close(write_fd);

	return 0;
}
