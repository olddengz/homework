#include "resource.h"
#include "check_legal.h"
void smart_decide(int this_shape, int next_shape)
{
	int best_c = 0, best_x = 0;
	int max_lines = -1, min_lines = 20;//������

	for (int c = 0; c < 4; c++)//4����ת�Ƕ�
	{
		int dw = block_width[this_shape][c];
		for (int x = 0; x <= COLS - dw; x++)//����x�ĺϷ���Χ
		{
			//�ҸýǶ��µ��������λ��
			int y = ROWS - 1;//����ײ���ʼ��
			while (y >= 0 && !check_legal(this_shape, c, x, y))
			{
				y--;
			}
			y++;//�õ���͵Ŀ��е�y
			//ʹ��һ��ģ�����Ļ�����ã���ȡ���Ž�
			int temp_screen[ROWS][COLS], temp_height[COLS];
			memcpy(temp_screen, screen, sizeof(screen));//������Ļ��ʱ�ķ���
			memcpy(temp_height, height, sizeof(height));//���ƴ�ʱ�ĸ��и߶�
			//��¼�����λ��
			for (int i = 0; i < 4; i++)
			{
				//������õĺ����߼�
				int dx = blocks[this_shape][c][i][0];
				int dy = blocks[this_shape][c][i][1];
				int ny = y + dy;
				temp_screen[ny][x + dx] = 1;
				if (temp_height[x + dx] < ny)
				{
					temp_height[x + dx] = ny;
				}
			}
			//���ú����������ʱ��ȥ������
			int lines = delet_lines(temp_screen, temp_height);
			int current_max_height = 0;//�����ʱ����߸߶�
			for (int col = 0; col < COLS; col++)
			{
				if (temp_height[col] > current_max_height)
				{
					current_max_height = temp_height[col];
				}
			}
			//̰��
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