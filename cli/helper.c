#include "main.h"

int get_terminal_width() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void formatePrinting(char ** arr){
    int terminal_width = get_terminal_width();
if (!arr)
	{
		printf("arr is null.\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; arr[i]; i++){
        int  chars_printed=0;
        
		for (int j = 0; arr[i][j] != '\0'; j++) {
        putchar(arr[i][j]);
        chars_printed++;

        if (chars_printed >= terminal_width) {
            break;
        }
        }
        printf("-------------------------------------------------------\n");
    }
	free_2d_array(arr);
}