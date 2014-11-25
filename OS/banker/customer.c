#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "banker.h"
#include "customer.h"

int	request_resources(int customer_num, int request[])
{
  int	i;

  printf("Thread %d requesting:\n", customer_num);
  for (i = 0; i < NUMBER_OF_RESOURCES; ++i)
    printf("%d resources of type %d:\n", request[i], i);
  return 0;
}

int	release_resources(int customer_num, int release[])
{
  int	i;

  printf("Thread %d releasing:\n", customer_num);
  for (i = 0; i < NUMBER_OF_RESOURCES; ++i)
    printf("%d resources of type %d:\n", release[i], i);
  return 0;
}

void*	customerFunc(void *p)
{
  int	*n;
  int	i;
  int	arr[NUMBER_OF_RESOURCES];

  n = p;
  srand(time(NULL));
  while (1)
    {
      for (i = 0; i < NUMBER_OF_RESOURCES; ++i)
	arr[i] = rand() % maximum[*n][i] + 1;
      (rand() % 2) ? request_resources(*n, arr) : release_resources(*n, arr);
      sleep(5);
    }
  return NULL;
}
