#include "core.h"

int main()
{
	int type_input;

	scanf("%d", &type_input);

	char **arr = list_processes(type_input);

	if (!arr)
	{
		printf("arr is null.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; arr[i]; i++)
		printf("%s", arr[i]);

	free_2d_array(arr);

	return (0);
}
