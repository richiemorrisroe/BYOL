#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char** argv) {
    puts("Lispy version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  /*in a never ending loop*/
  while (1) {

    /*output a prompt and get input*/
    char* input = readline("lispy> ");
    add_history(input);
    printf("No, you're a %s\n", input);

    free(input);
  }
  return 0;
}
