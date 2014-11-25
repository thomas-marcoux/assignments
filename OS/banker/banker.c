#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "banker.h"

pthread_mutex_t	mutex;

int	bankerFunc()
{
  pthread_mutex_init(&mutex, NULL);
  while (1)
    {
      pthread_mutex_lock(&mutex);
      printf("Banking...\n");
      sleep(2);
      pthread_mutex_unlock(&mutex);
    }
  return 1;
}
