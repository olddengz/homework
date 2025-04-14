#include "resource.h"
//����ͳ��ÿ�и߶�
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
//��������ͬʱ���ص�ǰ����
int delet_line()
{
	int lines = 0;
	int full_line[ROWS] = { 0 };//����Ѿ�������
	for (int y = 0; y < ROWS; y++)
	{
		int full = 1;//���øú���ʱ����һ��
		for (int x = 0; x < COLS; x++)
		{
			if (screen[y][x] == 0)//������һ����û����䣬���޷�����
			{
				full = 0;
				break;
			}
		}
		if (full)//����ͳ����ϣ��ۼ�
		{
			full_line[y] = 1;
			lines++;
		}
	}
	if (lines > 0)//���������ۼ�
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
	//����ɾ������
	for (int y = ROWS - 1; y >= 0; y++)
	{
		if (!full_line[y])//�������濪ʼ������ķ�����
		{
			int loc = y;
			while (loc >= 0 && full_line[loc])//�ҵ�������������ķ�����
			{
				loc--;
			}
			if (loc > 0)//��ǰ�������Ϸ��з�����
			{
				memcpy(screen[y], screen[loc], sizeof(int) * COLS);
			}
			else//��ȥ�Ϸ�û�����У���ǰ��Ϊ0
			{
				memset(screen[y], 0, sizeof(int) * COLS);
			}
		}
	}
	height_reset(screen, height);//��ȥ��������ͳ��ÿ�����
	return lines;
}