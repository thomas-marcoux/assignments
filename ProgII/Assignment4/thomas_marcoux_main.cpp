/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #3
# This program displays the information given
# to instances of classes derived from the
# Assignment2's Product class.
*********************************************/

#include "book.h"
#include "dvd.h"

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
  dvd	my_dvd(1234, "Walking Dead", 33.99, 4, "AMC", "Andrew Lincoln", "Sarah Wayne Callies");
  my_dvd.print_info();
  book	my_book(4321, "Slaughterhouse Five", 9.99, 6, "Dial Press", "Kurt Vonnegut", 123456);
  my_book.print_info();
  return 1;
}
