#include "banker.h"

void	banker()
{
  //available amount of each resource
  int	available[NUMBER_OF_RESOURCES];	
  //maximum demand of each customer
  int	maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
  //amount currently allocated to each customer
  int	allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
  //remaining need of each customer
  int	need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
}
