#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <fstream>
#include <string>

class	Language
{
 public:
  Language(std::ifstream&);
  Language(const char*);
  ~Language();
};

#endif
