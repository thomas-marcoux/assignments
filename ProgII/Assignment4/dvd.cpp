/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #3
# This program displays the information given
# to instances of classes derived from the
# Assignment2's Product class.
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
  std::cout << "DVD:" << std::endl;
  Product::print_info();
  std::cout << "Movie Studio: " << this->studio << std::endl
	    << "Male Lead: " << this->mLead << std::endl
	    << "Female Lead: " << this->fLead << std::endl;
}
