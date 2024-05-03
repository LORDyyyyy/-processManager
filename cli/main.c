#include"main.h"

int main(){

printf("-----------------------------------------------------\n");
int type= typeInput();
char **arr = list_processes(type);
if (!arr)
	{
		printf("arr is null.\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; arr[i]; i++)
		printf("%s", arr[i]);

	free_2d_array(arr);
    printf("-------------------------------------------------------");
    printf("select the PID and the signal type you want to perform ");

	return (0);
}



