#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void* do_stuff(void* param)
{
  long thread_no = (long)param;
  printf("Thread number %ld\n", thread_no);
  return (void*)(thread_no + 1);
}

void error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int main()
{
  pthread_t threads[3];
  long t;

  for (t = 0; t < 3; t++) {
    if (pthread_create(&threads[t], NULL, do_stuff, (void*)t) == -1)
      error("can't create");
  }

  void* result;
  for (t = 0; t < 3; t++) {
    if (pthread_join(threads[t], &result) == -1)
      error("Can't re");
    printf("Thread %ld returned %ld\n", t, (long)result);
  }

  return 0;
}
