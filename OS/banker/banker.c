#include <unistd.h>
#include <stdio.h>
#include "banker.h"

int	bankerFunc(int id, int requesting, int resources[])
{
  int	i;

  for (i = 0; i < NUMBER_OF_RESOURCES; ++i)
    pthread_mutex_init(&mutex[i], NULL);
  for (i = 0; i < NUMBER_OF_RESOURCES; ++i)
    {
      if (!requesting)
	release(&mutex[i], id, resources[i], i);
      else if (resources[i] <= need[id][i])
	request(&mutex[i], id, resources[i], i);
      else
	return -1;
    }
  return 0;
}

void	release(pthread_mutex_t *mutex,
		int id, int resource, int resource_type)
{
  pthread_mutex_lock(mutex);
  available[resource_type] += resource;
  if (available[resource_type] > maximum[id][resource_type])
    available[resource_type] = maximum[id][resource_type]; 
  allocation[id][resource_type] -= resource;
  if (allocation[id][resource_type] < 0)
    allocation[id][resource_type] = 0;
  need[id][resource_type] += resource;
  if (need[id][resource_type] > maximum[id][resource_type]) 
    need[id][resource_type] = maximum[id][resource_type];
  printf("Thread %d releasing %d resources #%d: %d resources #%d left\n"
	 , id+1, resource, resource_type+1, available[resource_type], resource_type+1);
  pthread_mutex_unlock(mutex);
}

void	request(pthread_mutex_t *mutex,
		int id, int resource, int resource_type)
{
  pthread_mutex_lock(mutex);
  int	buff;
  while (!(resource <= available[resource_type]));
  buff = available[resource_type];
  available[resource_type] -= resource;
  allocation[id][resource_type] += resource;
  need[id][resource_type] -= resource;
  printf("REQUEST: Thread %d -> %d resources #%d:\nwent from %d to %d resources #%d left\n",
	 id+1, resource, resource_type+1, buff, available[resource_type], resource_type+1);
  pthread_mutex_unlock(mutex);
}

void	printResourcesState()
{
  int	i;

  for (i = 0; i < NUMBER_OF_RESOURCES; ++i)
    printf("Resource %d : %d\n", i+1, available[i]);
}
