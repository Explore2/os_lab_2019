#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        execvp("sequential_min_max", argv);
    }
    return 0;
}