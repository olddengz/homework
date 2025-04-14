#include "resource.h"
char blocks_body[] = { 'I','T','O','J','L','S','Z' };
char outputrandom()//随机生成方块
{
	int index = rand() % 7;
	return blocks_body[index];
}