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

Book::Book()
  : Product(), publisher("unknown"), author("unknown"), isbn(-1) {}

Book::Book(int id, std::string name, double price, int stock)
  : Product(id, name, price, stock),
    publisher("unknown"), author("unknown"), isbn(-1) {}

Book::Book(int id, std::string name, double price, int stock,
	   std::string publi, std::string author, int isbn)
  : Product(id, name, price, stock), publisher(publi), author(author), isbn(isbn) {}

void	Book::print_info() const
{
  std::cout << "Book:" << std::endl;
  Product::print_info();
  std::cout << "Publisher: " << this->publisher << std::endl
	    << "Author: " << this->author << std::endl
	    << "ISBN: " << this->isbn << std::endl;
}
