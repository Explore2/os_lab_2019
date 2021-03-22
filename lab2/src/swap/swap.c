#include "swap.h"

void Swap(char *left, char *right)
{
	char temp;
    temp = *right;
    *right = *left;
    *left = temp;
}
