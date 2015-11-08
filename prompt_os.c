#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/*fake readline function*/

char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = "\0";
  return cpy;
}

void add_history(char* unused {}

#else

#include <readline/readline.h>
#include <readline/history.h>
#endif

int main(int argc, char** argv) {
  puts("Lispy version 0.0.0.1");
  puts("Press Ctrl+c to exit");

  while (1) {
    char* input = readline("richlisp> ");
    add_history(input);

    printf("no you're a %s\n", input);
    free(input);

  }

  return 0;
}
