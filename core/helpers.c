#include "core.h"

void free_2d_array(char **arr)
{
	int i;

	if (arr != NULL)
	{
		for (i = 0; arr[i]; i++)
			free(arr[i]);
		free(arr);
		arr = NULL;
	}
}
