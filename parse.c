#include "monty.h"

void parse(char *file)
{
        size_t size = 0;
	unsigned int line_num = 1;
	char *str;
	stack_t *stack = NULL;
	FILE *file_input;
	char *command;

	file_input = fopen(file, "r");
	if (file_input == NULL)
	{
		printf("Error: Can't open file %s\n", file);
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
}
