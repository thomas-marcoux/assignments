#include <unistd.h>
#include <stdio.h>
#include "banker.h"

void*	bankerFunc(void* p)
{
  while (1)
    {
      printf("Banking...\n");
      sleep(1);
    }
  return NULL;
}
