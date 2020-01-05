#include "monty.h"
/**
 * parse - parse through the file
 * @file: name of the file
 */

void parse(char *file)
{
	size_t size = 0;
	unsigned int line_num = 1;
	char *str = NULL;
	stack_t *stack = NULL;
	FILE *file_input = NULL;
	char *command = NULL;

	file_input = fopen(file, "r");
	if (file_input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	arg_holder.file = file_input;
	arg_holder.SQ = 1;
	while (getline(&str, &size, file_input) != -1)
	{
		arg_holder.input_str = str;
		command = strtok(str, DELIMS);
		arg_holder.arg = strtok(NULL, DELIMS);
		opcode(command, line_num, &stack);
		line_num++;
	}
	free_all(&stack);
	fclose(arg_holder.file);
}
