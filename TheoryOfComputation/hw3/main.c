#include <stdio.h>

#define SIZE 12

enum	State {
  STATE0,
  STATE1,
  STATE2,
  STATE3,
  STATE4
};

enum State	transition(char c, enum State e)
{
  if (e == STATE1 && c == 'a')
    return STATE2;
  if (e == STATE2 && c == 'a')
    return STATE2;
  if (e == STATE2 && c == 'b')
    return STATE3;
  if (e == STATE3 && c == 'b')
    return STATE2;
  if (e == STATE3 && c == 'a')
    return STATE4;
  if (e == STATE4 && c == 'a')
    return STATE4;
  if (e == STATE4 && c == 'b')
    return STATE2;
  return STATE0;
}

int	main()
{
  enum State	e;
  int	i, j;
  const char	*s[SIZE] = {"aabbaabaaa", "abbbaaba", "abbabb", "babbaa",
		 "bbb", "aaaa", "aaaaba", "abaaaabbabbba",
		 "aacaba", "qbbba", "abbaz", "abababbbabbaa"};
  for (i = 0; i < SIZE; ++i)
    {
      for (e = STATE1, j = 0; s[i][j] && (e = transition(s[i][j], e)); ++j);
      if (e == STATE4)
	printf("%s = success\n", s[i]);
      else
	printf("%s = fail\n", s[i]);
    }
  return 0;
}
