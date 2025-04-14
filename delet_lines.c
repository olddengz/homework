#include "resource.h"
//重新统计每行高度
void height_reset(int screen[ROWS][COLS],int*height)
{
	for (int x = 0; x < COLS; x++)
	{
		int height_temp = -1;
		for (int y = 0; y < ROWS; y++)
		{
			if (screen[y][x])
			{
				height_temp=y;
			}
		}
		height[x] = height_temp;
	}
}
//行消除，同时返回当前分数
int delet_line()
{
	int lines = 0;
	int full_line[ROWS] = { 0 };//标记已经满的行
	for (int y = 0; y < ROWS; y++)
	{
		int full = 1;//调用该函数时至少一行
		for (int x = 0; x < COLS; x++)
		{
			if (screen[y][x] == 0)//当存在一个格没有填充，则无法消除
			{
				full = 0;
				break;
			}
		}
		if (full)//此行统计完毕，累加
		{
			full_line[y] = 1;
			lines++;
		}
	}
	if (lines > 0)//划分数，累计
	{
		int get_score = 0;
		switch (lines)
		{
		    case 1:get_score = 100; break;
			case 2:get_score = 300; break;
			case 3:get_score = 500; break;
			case 4:get_score = 800; break;
		}
		total_score += get_score;
	}
	//以下删除满行
	for (int y = ROWS - 1; y >= 0; y++)
	{
		if (!full_line[y])//从最上面开始找最近的非满行
		{
			int loc = y;
			while (loc >= 0 && full_line[loc])//找到离消除行最近的非满行
			{
				loc--;
			}
			if (loc > 0)//当前消除后上方有非满行
			{
				memcpy(screen[y], screen[loc], sizeof(int) * COLS);
			}
			else//消去上方没有满行，则当前行为0
			{
				memset(screen[y], 0, sizeof(int) * COLS);
			}
		}
	}
	height_reset(screen, height);//消去结束重新统计每列最高
	return lines;
}