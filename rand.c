#include "resource.h"
char blocks_body[] = { 'I','T','O','J','L','S','Z' };
char outputrandom()//������ɷ���
{
	int index = rand() % 7;
	return blocks_body[index];
}