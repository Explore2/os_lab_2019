#include "revert_string.h"
#include <string.h>
#include <stdlib.h>

void RevertString(char *str)
{
    int lenght = strlen(str);
	char* temp;
    temp = (char*) malloc(sizeof(char));
    for(int i = 0; i<lenght/2; i++){
        *temp = *(str+(lenght-i-1));
        *(str+(lenght-i-1))=*(str+i);
        *(str+i) = *temp;
    }
}

