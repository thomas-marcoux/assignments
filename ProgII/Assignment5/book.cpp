/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #4
# This program reads data from books.txt and dvd.txt
# and displays it, along with the value of static member variables.
*********************************************/

#include "book.h"

book::book()
  : Product(), publisher("unknown"), author("unknown"), isbn("-1") {}

book::book(std::string name, std::string price, std::string stock)
  : Product(name, price, stock),
    publisher("unknown"), author("unknown"), isbn("-1") {}

book::book(std::string name, std::string price, std::string stock,
	   std::string publi, std::string author, std::string isbn)
  : Product(name, price, stock), publisher(publi), author(author), isbn(isbn) {}

void	book::print_info() const
{
  std::cout << "Book" << std::endl;
  Product::print_info();
  std::cout << "Publisher: " << this->publisher << std::endl
	    << "Author: " << this->author << std::endl
	    << "ISBN: " << this->isbn << std::endl;
}

std::ostream&	operator<<(std::ostream& out, book const& o)
{
  out << o.name << std::endl
      << o.price << std::endl
      << o.stock << std::endl
      << o.publisher << std::endl
      << o.author << std::endl
      << o.isbn << std::endl;
  return out;
}

std::istream&	operator>>(std::istream& in, book &o)
{
  std::cout << "Name: ";
  in >> o.name;
  std::cout << "Price: ";
  in >> o.price;
  std::cout << "Stock: ";
  in >> o.stock;
  std::cout << "Publisher: ";
  in >> o.publisher;
  std::cout << "Author: ";
  in >> o.author;
  std::cout << "ISBN: ";
  in >> o.isbn;
  return in;
}
