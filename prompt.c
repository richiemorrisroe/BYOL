#include <stdio.h>

static char input[2048];

int main(int argc, char** argv) {

  puts("Lispy version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  /*in a never ending loop*/
  while (1) {

    /*output a prompt*/
    fputs("lispy> ", stdout);

    /*read a line of user input of max size 2048*/
    fgets(input, 2048, stdin);

    /*Echo input back to user*/
    printf("No, you're a %s", input);
  }
  return(0);
}
