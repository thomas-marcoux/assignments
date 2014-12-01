#include <iostream>
#include <vector>
#include "Iterator.h"

int	main()
{
  std::vector<int>	V;
  Iterator<int>	It(&V);

  V.push_back(10);
  V.push_back(20);
  V.push_back(30);
  for (It.begin(); !It.end(); It.next())
    std::cout << It.get_current() << "\t";
  std::cout << std::endl;
  return 0;
}
