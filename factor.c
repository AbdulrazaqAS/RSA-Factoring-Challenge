#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *file_ptr;
	long long unsigned int number;
	char *line = NULL;
	size_t n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
	{
		perror("OPEN");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &n, file_ptr) != -1)
	{
		number = atoll(line);
		if (number % 2 == 0)
			printf("%d=%d*2", number, number / 2);
		else if (number % 3 == 0)
			printf("%d=%d*3", number, number / 3);
		else if (number % 5 == 0)
			printf("%d=%d*5", number, number / 5);
		else if (number % 7 == 0)
			printf("%d=%d*7", number, number / 7);
		else
			printf("%d=pending", number);
		putchar('\n');
	}

	fclose(file_ptr);
	free(line);
	return (EXIT_SUCCESS);
}
