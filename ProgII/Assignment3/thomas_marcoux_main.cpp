/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #2
# This program uses an overloaded >> operator to
# assign values to a Product instance and then prints
# the result using an overloaded << operator
*********************************************/

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
  Product	my_product;

  std::cin >> my_product;
  std::cout << my_product;
  return 0;
}
