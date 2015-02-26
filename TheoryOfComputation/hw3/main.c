#include <stdio.h>

#define SIZE		13
#define STATE_NB	5

enum	State {
  STATE0,
  STATE1,
  STATE2,
  STATE3,
  STATE4
};

enum State	transition(char c, enum State e)
{
  if (c != 'a' && c != 'b')
    return STATE0;
  if (e == STATE1 && c == 'a')
    return STATE2;
  if (e == STATE2 && c == 'b')
    return STATE3;
  if (e == STATE3 && c == 'b')
    return STATE2;
  if (e == STATE3 && c == 'a')
    return STATE4;
  if (e == STATE4 && c == 'b')
    return STATE2;
  return e;
}

int	main()
{
  enum State	e;
  int	i, j;
  char	*s[SIZE] = {"aabbaabaaa", "abbbaaba", "abbabb", "babbaa",
		 "bbb", "aaaa", "aaaaba", "abaaaabbabbba",
		    "aacaba", "qbbba", "abbaz", "abababbbabbaa", "abbab"};
  char	*state_messages[STATE_NB] = {"FAILURE (Wrong symbol)",
				     "FAILURE (Does not begin with an a)",
				     "FAILURE (Even number of Bs)",
				     "FAILURE (Does not end with an a)",
				     "SUCCESS"};
  for (i = 0; i < SIZE; ++i)
    {
      for (e = STATE1, j = 0; s[i][j] && (e = transition(s[i][j], e)) && e != STATE1; ++j);
      printf("%s : %s\n", s[i], state_messages[e]);
    }
  return 0;
}
