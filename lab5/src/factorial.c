#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <getopt.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int res = 1;
int k = 0, pnum = 0, mod = 0;

void factorial(int *number)
{
  pthread_mutex_lock(&mut);
    int i = k/pnum * *number + 1;
    int end = (*(number) + 1)==pnum?(k + 1):(k / pnum * (*number + 1) + 1);

    for(i = i; i < end; i++)
    {   
        
        res = (res * (i % mod)) % mod;
       
    }
  pthread_mutex_unlock(&mut);
}


int main(int argc, char **argv)
{
    static struct option options[] = {{"k", required_argument, 0, 0},
                                  {"pnum", required_argument, 0, 0},
                                  {"mod", required_argument, 0, 0},
                                  {0, 0, 0, 0}};

    int option_index = 0; 
while(1)
{
    int c = getopt_long(argc, argv, "f", options, &option_index);
	if (c == -1) break;
	switch(c)
	{
	case 0:
		switch(option_index)
		{
			case 0:
				k = atoi(optarg);
				if(k < 0)
					k = -1;
				break;
			case 1:
				pnum = atoi(optarg);
				if(pnum < 1)
					pnum = -1;
				break;
			case 2:
				mod = atoi(optarg);
				if(mod < 1)
					mod = -1;
				break;
		}
		break;
	default:
		printf("Index %d is out of options\n", option_index);
	}
}

pthread_t thread[pnum];
int number[pnum];

for(int i = 0; i < pnum; i++)
{   
    number[i] = i;
    if (pthread_create(&thread[i], NULL, (void *)factorial, (void *)&number[i]) != 0){
        perror("pthread_create");
        exit(1);
    }
}

for(int i = 0; i < pnum; i++)
{
    if (pthread_join(thread[i], NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }
}

    printf("%d\n", res);
    return 0;
}