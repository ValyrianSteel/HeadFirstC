#include "encrypt.h"

void encrypt(char *message)
{
  while (*message) {
    *message = *message ^ 28;
    message++;
  }
}
