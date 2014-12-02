/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #4
# This program reads data from books.txt and dvd.txt
# and displays it, along with the value of static member variables.
*********************************************/

#include "dvd.h"

dvd::dvd()
  : Product(), studio("unknown"), mLead("unknown"), fLead("unknown") {}

dvd::dvd(std::string name, std::string price, std::string stock)
  : Product(name, price, stock), studio("unknown"),
    mLead("unknown"), fLead("unknown") {}

dvd::dvd(std::string name, std::string price, std::string stock,
	 std::string studio, std::string mLead, std::string fLead)
  : Product(name, price, stock), studio(studio), mLead(mLead), fLead(fLead) {}

void	dvd::print_info() const
{
  std::cout << "DVD" << std::endl;
  Product::print_info();
  std::cout << "Movie Studio: " << this->studio << std::endl
	    << "Male Lead: " << this->mLead << std::endl
	    << "Female Lead: " << this->fLead << std::endl;
}

std::ostream&	operator<<(std::ostream& out, dvd const& o)
{
  out << o.name << std::endl
      << o.price << std::endl
      << o.stock << std::endl
      << o.studio << std::endl
      << o.mLead << std::endl
      << o.fLead << std::endl;
  return out;
}

std::istream&	operator>>(std::istream& in, dvd &o)
{
  std::cout << "Name: ";
  in >> o.name;
  std::cout << "Price: ";
  in >> o.price;
  std::cout << "Stock: ";
  in >> o.stock;
  std::cout << "Studio: ";
  in >> o.studio;
  std::cout << "Male lead: ";
  in >> o.mLead;
  std::cout << "Female lead: ";
  in >> o.fLead;
  return in;
}
