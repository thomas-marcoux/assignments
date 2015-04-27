#include "language.h"

Language::Language(std::ifstream &in)
{

}

Language::Language(const char *s)
  : Language(std::ifstream(s))
{

}

Language::~Language()
{

}
