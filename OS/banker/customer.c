#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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
  printf("Thread %d working\n", *i);
  printf("Random %d\n", rand() % 2);
  return NULL;
}
