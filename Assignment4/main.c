#include <stdio.h>
#include <stdlib.h>

int	min, max, avrg;

void	setMin(int array[], int size)
{
  int	i;

  min = array[0];
  for (i = 0; i < size; ++i)
    if (array[i] < min)
      min = array[i];
}

void	setMax(int array[], int size)
{
  int	i;

  max = array[0];
  for (i = 0; i < size; ++i)
    if (array[i] > max)
      max = array[i];
}

void	setAvrg(int array[], int size)
{
  int	i;

  avrg = 0;
  for (i = 0; i < size; ++i)
    avrg += array[i];
  avrg /= size;
}

int	main(int argc, char** argv)
{
  int	array[argc - 1];
  int	i;

  for (i = 1; i < argc; ++i)
    array[i - 1] = atoi(argv[i]);
  setAvrg(array, argc - 1);
  setMin(array, argc - 1);
  setMax(array, argc - 1);
  printf("The average value is %d\n", avrg);
  printf("The minimum value is %d\n", min);
  printf("The maximum value is %d\n", max);
  return 0;
}
