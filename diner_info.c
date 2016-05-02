#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
 // char *my_env[] = {"JUICE=peach and apple", NULL};
 // execle("diner_info", "diner_info", "4", NULL, my_env);
  printf("Diners: %s\n", argv[1]);
  printf("Juice: %s\n", getenv("JUICE"));

  return 0;
}
