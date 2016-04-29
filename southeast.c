#include <stdio.h>

void go_south_east(int *lat, int *lon)
{
  printf("lat is %p, lon is %p\n", lat, lon);
  printf("lat lives at %p, lon lives at %p\n", &lat, &lon);
  *lat = *lat -1;
  *lon = *lon +1;
}

int main()
{
  int latitude = 32;
  int longitude = -64;
  printf("latitude lives at %p, longitude lives at %p\n", &latitude, &longitude);
  go_south_east(&latitude, &longitude);
  printf("where: [%i, %i]\n", latitude, longitude);

  return 0;
}
