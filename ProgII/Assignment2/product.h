#ifndef PRODUCT_H
#define	PRODUCT_H

#include <iostream>
#include <string>

class	Product
{
 private:
  int		id;
  std::string	name;
  double	price;
  int		stock;
  
 public:
  Product(int = -1, std::string = "", double = 0.0, int = 0);
  int	getId() const;
  std::string	getName() const;
  double	getPrice() const;
  int	getStock() const;
  void	setId(int);
  void	setName(std::string);
  void	setPrice(double);
  void	setStock(int);
  friend std::ostream& operator<<(std::ostream& out, Product const& p);
  friend std::istream& operator>>(std::istream& out, Product &p);
};

#endif
