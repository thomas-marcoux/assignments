#include "product.h"

std::ostream&	operator<<(std::ostream& out, Product const& p)
{
  out << p.id << std::endl << p.name << std::endl << p.price << std::endl
      << p.stock << std::endl;
  return out;
}

int	main()
{
  std::cout << Product();
  return 0;
}
