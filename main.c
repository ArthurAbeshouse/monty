#include "monty.h"

/**
 * main - define function
 * @argc: count of arguments
 * @argv: pointer to array of pointers
 * Return: on success, always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	parse(argv[1]);

	return (EXIT_SUCCESS);
}
