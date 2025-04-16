#include "resource.h"
#include "check_legal.h"
void smart_decide(int this_shape, int next_shape)
{
	int best_c = 0, best_x = 0;
	int max_lines = -1, min_lines = 20;//最坏的情况

	for (int c = 0; c < 4; c++)//4个旋转角度
	{
		int dw = block_width[this_shape][c];
		for (int x = 0; x <= COLS - dw; x++)//计算x的合法范围
		{
			//找该角度下的最低下落位置
			int y = ROWS - 1;//从最底部开始找
			while (y >= 0 && !check_legal(this_shape, c, x, y))
			{
				y--;
			}
			y++;//得到最低的可行的y
			//使用一个模拟的屏幕来放置，获取最优解
			int temp_screen[ROWS][COLS], temp_height[COLS];
			memcpy(temp_screen, screen, sizeof(screen));//复制屏幕此时的方块
			memcpy(temp_height, height, sizeof(height));//复制此时的各行高度
			//记录方块的位置
			for (int i = 0; i < 4; i++)
			{
				//方块放置的核心逻辑
				int dx = blocks[this_shape][c][i][0];
				int dy = blocks[this_shape][c][i][1];
				int ny = y + dy;
				temp_screen[ny][x + dx] = 1;
				if (temp_height[x + dx] < ny)
				{
					temp_height[x + dx] = ny;
				}
			}
			//调用函数来计算此时消去的行数
			int lines = delet_lines(temp_screen, temp_height);
			int current_max_height = 0;//计算此时的最高高度
			for (int col = 0; col < COLS; col++)
			{
				if (temp_height[col] > current_max_height)
				{
					current_max_height = temp_height[col];
				}
			}
			//贪心
			if (lines > max_lines || (lines == max_lines && current_max_height < min_lines) || (lines == max_lines && current_max_height == min_lines && x < best_x))
			{
				max_lines = lines;
				min_lines = current_max_height;
				best_c = c;
				best_x = x;
			}
		}
	}
	place_and_end(this_shape, best_c, best_x);
}