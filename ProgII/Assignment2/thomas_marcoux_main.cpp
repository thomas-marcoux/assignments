#include "product.h"

std::ostream&	operator<<(std::ostream& out, Product const& p)
{
  out << "Product #" << p.id << ": '" << p.name << "'" << std::endl
      << "$" << p.price << std::endl
      << "x" << p.stock << std::endl;
  return out;
}

std::istream&	operator>>(std::istream& in, Product &p)
{
  std::cout << "Id: ";
  in >> p.id;
  std::cout << "Name: ";
  in >> p.name;
  std::cout << "Price: ";
  in >> p.price;
  std::cout << "Stock: ";
  in >> p.stock;
  return in;
}

int	main()
{
  Product	p;

  std::cin >> p;
  std::cout << p;
  return 0;
}
