#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}
int main(int argc, char *argv[])
{
  char *vars[] = {"RSS_FEED=http://zhangwenli.com/blog/feed.xml","RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
  char *phrase = argv[1];

  FILE *f = fopen("stories.txt", "w");
  if (!f) {
    error("Can't open stories.txt");
  }


    pid_t pid = fork();
    if (pid == -1) {
      error("Can't fork process");
    }
    if (!pid) {
      if (dup2(fileno(f), 1) == -1) {
        error("Can't redirect Standard Output");
      }
      if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
        error("Can't run script");
      }
    }


  int pid_status;
  if (waitpid(pid, &pid_status, 0) == -1) {
    error("waiting child process is error");
  }
  if (WEXITSTATUS(pid_status)) {
    puts("Error status non-zero");
  }

  return 0;
}
