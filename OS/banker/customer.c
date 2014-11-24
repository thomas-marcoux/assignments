#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "banker.h"
#include "customer.h"

int	request_resources(int customer_num, int request[])
{
  return 0;
}

int	release_resources(int customer_num, int release[])
{
  return 0;
}

void*	customerFunc(void *p)
{
  int	*i;

  i = p;
  srand(time(NULL));
  while (1)
    {
      printf("Thread %d working\n", *i);
      //printf("Random %d\n", rand() % 2);
      sleep(1);
    }
  return NULL;
}
