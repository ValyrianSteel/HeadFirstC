#include <stdio.h>

int main()
{
  char card_name[3];
  int val = 0;

  while (card_name[0] != 'X')
  {
    puts("input: ");
    scanf("%2s", card_name);

  if  ( (card_name[0] == 'K') || (card_name[0]=='Q') || (card_name[0] =='J') ) {
    val = 10;
  } else if (card_name[0] == 'A') {
    val = 11;
  } else {
    val = atoi(card_name);
    if ((val < 2) || (10 < val)) {
      printf("input correct, ");
    }
  }

  if ((val > 2) && (val < 7))
    puts("count increase");
  else if (val == 10)
    puts("count decrease");
  }

  return 0;
}
