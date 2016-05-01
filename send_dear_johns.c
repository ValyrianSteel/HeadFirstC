#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum response_type { DUMP, SECOND_CHANCE, MARRIAGE };
typedef struct {
  char *name;
  enum response_type type;
} response;

void dump(response r)
{
  printf("Dear %s,\n", r.name);
  puts("dump");
}

void second_chance(response r)
{
  printf("Dear %s,\n", r.name);
  puts("second_chance");
}

void marriage(response r)
{
  printf("Dear %s,\n", r.name);
  puts("marriage");
}

int main()
{
  response r[] = {
    {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
    {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
  };
  int i;

  for (i = 0; i < 4; i++) {
    switch (r[i].type) {
      case DUMP:
        dump(r[i]);
        break;
      case SECOND_CHANCE:
        second_chance(r[i]);
        break;
      default:
        marriage(r[i]);
    }
  }

  return 0;
}
