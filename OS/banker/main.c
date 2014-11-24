#include <stdio.h>
#include <pthread.h>
#include "banker.h"
#include "customer.h"

//available amount of each resource
int	available[NUMBER_OF_RESOURCES];	
//maximum demand of each customer
int	maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
//amount currently allocated to each customer
int	allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
//remaining need of each customer
int	need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

void*	dummy(void *p)
{
  int	*i;

  i = p;
  printf("Thread %d working\n", *i);
  return NULL;
}

int	main()
{
  pthread_t		customers[NUMBER_OF_CUSTOMERS];
  pthread_attr_t	attr;
  int			i;

  pthread_attr_init(&attr);
  for (i = 0; i < NUMBER_OF_CUSTOMERS; ++i)
    {
      pthread_create(&customers[i], &attr, &dummy, &i);
      pthread_join(customers[i], NULL);
    }
  for (i = 0; i < NUMBER_OF_CUSTOMERS; ++i)
    ;
  return 1;
}
