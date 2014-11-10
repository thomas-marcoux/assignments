/*********************************************
# Thomas Marcoux
# Programming II
# Fall 2014
# Assignment #3
# This program displays the information given
# to instances of classes derived from the
# Assignment2's Product class.
*********************************************/

#include "product.h"

Product::Product()
  : id(-1), name(""), price(0.0), stock(0) {}

Product::Product(int id, std::string name, double price, int stock)
  : id(id), name(name), price(price), stock(stock) {}

int	Product::getId() const
{
  return id;
}

std::string	Product::getName() const
{
  return name;
}

double	Product::getPrice() const
{
  return price;
}

int	Product::getStock() const
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

void	Product::setPrice(double new_price)
{
  this->price = new_price;
}


void	Product::setStock(int new_stock)
{
  this->stock = new_stock;
}

void	Product::print_info() const
{
  std::cout << *this;
}
