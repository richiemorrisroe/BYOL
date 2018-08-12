#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/*fake add_history function*/
void add_history(char* unused) {}

/*otherwise include editline headers*/
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

#include <string.h>

int main(int argc, char** argv) {
  puts("RichLisp Version 0.0.0.1");
  puts("Press Ctrl+C to Exit\n");
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr = mpc_new("expr");
  mpc_parser_t* Lispy = mpc_new("lispy");
  
  /* define with the following language */
  mpca_lang(MPCA_LANG_DEFAULT,
            "\
             \
  number: /-?[0-9]+/ ; \
  operator: '+' | '-' | '*' | '/';\
  expr: <number> | '(' <operator> <expr>+ ')'; \
  lispy: /^/ <operator> <expr>+ /$/; \
  ", Number, Operator, Expr, Lispy);
  
    
    while(1) {
      char* input = readline("rlisp> ");
      add_history(input);
      int len = strlen(input);
      printf("%s is %d characters long", input, len);
      printf("\n");
      free(input);
      
  
    }
      return 0;
  }
