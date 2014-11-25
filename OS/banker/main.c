#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "banker.h"
#include "customer.h"

void	init_globals(char **argv)
{
  int	i, j;

  for (i = 0; i < NUMBER_OF_RESOURCES; ++i)
    available[i] = atoi(argv[i+1]);
  for (i = 0; i < NUMBER_OF_CUSTOMERS; ++i)
    {
      for (j = 0; j < NUMBER_OF_RESOURCES; ++j)
	{
	  maximum[i][j] = available[j];
	  allocation[i][j] = 0;
	  need[i][j] = 0;
	}
    }
}

int	main(int argc, char **argv)
{
  pthread_t		customers[NUMBER_OF_CUSTOMERS];
  pthread_t		banker;
  pthread_attr_t	attr;
  int			i;
  int			arr[NUMBER_OF_CUSTOMERS];

  if (argc != NUMBER_OF_CUSTOMERS - 1)
    {
      printf("Usage: %s [[Resource Number]...]\n", argv[0]);
      return 0;
    }
  init_globals(argv);
  pthread_attr_init(&attr);
  pthread_create(&banker, &attr, &bankerFunc, NULL);
  for (i = 0; i < NUMBER_OF_CUSTOMERS; ++i)
    {
      arr[i] = i;
      pthread_create(&customers[i], &attr, &customerFunc, &arr[i]);
    }
  for (i = 0; i < NUMBER_OF_CUSTOMERS; ++i)
    pthread_join(customers[i], NULL);
  pthread_join(banker, NULL);
  return 1;
}
