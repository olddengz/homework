#include "resource.h"
void print_screen(int screen[ROWS][COLS])
{
	for (int y = 0; y < ROWS; y++)
	{
		for (int x = 0; x < COLS; x++)
		{
			printf("%d ", screen[y][x]);
		}
		printf("\n");
	}
}