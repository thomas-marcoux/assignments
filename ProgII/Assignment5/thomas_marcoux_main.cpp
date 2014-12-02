/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #4
# This program reads data from books.txt and dvd.txt
# and displays it, along with the value of static member variables.
*********************************************/

#include "product.h"
#include "dvd.h"
#include "book.h"
#include <vector>
#include <fstream>

std::ostream&	operator<<(std::ostream& out, Product const& p)
{
  out << "Id: " << p.id << std::endl
      << "Name: " << p.name << std::endl
      << "Price: $" << p.price << std::endl
      << "# in stock: " << p.stock << std::endl;
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
  std::vector<book*> all_books;
  std::vector<dvd*> all_dvds;
  
  std::cout << "# of all instances: "
	    << Product::getNbProducts() << std::endl;
  for(int i = 0; i < all_books.size(); i++)
    all_books[i]->print_info();
  for(int i = 0; i < all_dvds.size(); i++)
    all_dvds[i]->print_info();
  for(int i = 0; i < all_books.size(); i++)
    delete all_books[i];
  for(int i = 0; i < all_dvds.size(); i++)
    delete all_dvds[i];
  std::cout << "# of all instances: "
	    << Product::getNbProducts() << std::endl;
  return 0;
}
