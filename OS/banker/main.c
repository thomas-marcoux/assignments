#include <stdio.h>
#include <pthread.h>
#include "banker.h"
#include "customer.h"

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
      printf("Looping %d\n", i);
      pthread_create(&customers[i], &attr, &dummy, &i);
    }
  for (i = 0; i < NUMBER_OF_CUSTOMERS; ++i)
    pthread_join(customers[i], NULL);
  return 1;
}
