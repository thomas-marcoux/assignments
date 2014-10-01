#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	min, max, avrg;
int	size;

void	*setMin(void *param)
{
  int	*array = param;
  int	i;

  min = array[0];
  for (i = 0; i < size; ++i)
    if (array[i] < min)
      min = array[i];
  pthread_exit(0);
}

void	*setMax(void *param)
{
  int*	array = param;
  int	i;

  max = array[0];
  for (i = 0; i < size; ++i)
    if (array[i] > max)
      max = array[i];
  pthread_exit(0);
}

void	*setAvrg(void *param)
{
  int*	array = param;
  int	i;

  avrg = 0;
  for (i = 0; i < size; ++i)
    avrg += array[i];
  avrg /= size;
  pthread_exit(0);
}

int	main(int argc, char** argv)
{
  pthread_t	tid_avg;
  pthread_t	tid_max;
  pthread_t	tid_min;
  pthread_attr_t	attr;
  int	array[argc - 1];
  int	i;

  if (argc < 2) {
    fprintf(stderr, "usage:%s <Integers...>\n", argv[0]);
    return 0;
  }
  size = argc - 1;
  for (i = 1; i < argc; ++i)
    array[i - 1] = atoi(argv[i]);
  pthread_attr_init(&attr);
  pthread_create(&tid_avg, &attr, setAvrg, array);
  pthread_create(&tid_max, &attr, setMax, array);
  pthread_create(&tid_min, &attr, setMin, array);
  pthread_join(tid_avg, NULL);
  pthread_join(tid_max, NULL);
  pthread_join(tid_min, NULL);
  printf("The average value is %d\n", avrg);
  printf("The minimum value is %d\n", min);
  printf("The maximum value is %d\n", max);
  return 0;
}
