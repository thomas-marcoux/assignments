#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

template<class T>
class Iterator
{
public:
  Iterator(std::vector<T>*);
  T	begin();
  T	next();
  bool	end();
  T	get_current();

private:
  std::vector<T>	*_vector;
  T			_index;
};


template<class T>
Iterator<T>::Iterator(std::vector<T> *v)
  : _vector(v), _index(0) {}

template<class T>
T	Iterator<T>::begin()
{
  return _index;
}

template<class T>
T	Iterator<T>::next()
{
  return _index++;
}

template<class T>
bool	Iterator<T>::end()
{
  return (_index >= _vector->size());
}

template<class T>
T	Iterator<T>::get_current()
{
  return (*_vector)[_index];
}

#endif
