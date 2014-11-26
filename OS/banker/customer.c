#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "banker.h"
#include "customer.h"

int	request_resources(int customer_num, int request[])
{
  return bankerFunc(customer_num, 1, request);
}

int	release_resources(int customer_num, int release[])
{
  return bankerFunc(customer_num, 0, release);
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
	arr[i] = rand() % (maximum[*n][i] + 1);
      (rand() % 2) ? request_resources(*n, arr)	: release_resources(*n, arr);
      sleep(2);
    }
  return NULL;
}
