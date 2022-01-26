#include <fnmatch.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  FILE *stream;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char *pattern;
  char ok;

  while ((read = getline(&line, &len, stdin)) != -1) {
    line[read - 1] = '\0';
    ok = 1;
    for (int i = 1; i < argc; ++i) {
      pattern = argv[i];
      if (!fnmatch(pattern, line, 0)) {
        ok = 0;
        continue;
      }
    }
    if (ok) {
      printf("%s\n", line);
    }
  }
}