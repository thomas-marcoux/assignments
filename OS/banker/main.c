#include <stdio.h>
#include <pthread.h>
#include "banker.h"
#include "customer.h"


/*
struct
*/
//available amount of each resource
int	available[NUMBER_OF_RESOURCES];	
//maximum demand of each customer
int	maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
//amount currently allocated to each customer
int	allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
//remaining need of each customer
int	need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

int	main()
{
  pthread_t		customers[NUMBER_OF_CUSTOMERS];
  pthread_t		banker;
  pthread_attr_t	attr;
  int			i;
  int	arr[NUMBER_OF_CUSTOMERS];
  pthread_attr_init(&attr);
  pthread_create(&banker, &attr, &bankerFunc, NULL);
  for (i = 0; i < NUMBER_OF_CUSTOMERS; ++i)
    {
      arr[i] = i;
      pthread_create(&customers[i], &attr, &customerFunc, &arr[i]);
      //pthread_join(customers[i], NULL);
    }
  pthread_join(banker, NULL);
  return 1;
}
