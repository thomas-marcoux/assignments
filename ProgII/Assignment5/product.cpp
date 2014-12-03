/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #5
# This program reads data from books.txt and dvd.txt,
# it then prompts the user for displaying the list of or and dvds
# or adding new objects to the lists.
*********************************************/

#include "product.h"

int	Product::nb_products = 0;
int	Product::next_id = 0;

Product::Product()
  : id(++next_id), name(""), price("0.0"), stock("0")
{
  ++(Product::nb_products);
}

Product::Product(std::string name, std::string price, std::string stock)
  : id(++next_id), name(name), price(price), stock(stock)
{
  ++(Product::nb_products);
}

Product::~Product()
{
  --(Product::nb_products);
}

int	Product::getId() const
{
  return id;
}

std::string	Product::getName() const
{
  return name;
}

std::string	Product::getPrice() const
{
  return price;
}

std::string	Product::getStock() const
{
  return stock;
}

void	Product::setId(int new_id)
{
  this->id = new_id;
}

void	Product::setName(std::string new_name)
{
  this->name = new_name;
}

void	Product::setPrice(std::string new_price)
{
  this->price = new_price;
}


void	Product::setStock(std::string new_stock)
{
  this->stock = new_stock;
}

void	Product::print_info() const
{
  std::cout << *this;
}
