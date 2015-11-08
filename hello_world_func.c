#include <stdio.h>

int main(int argc, char** argv) {
  void hello_world(int n) {
    for(int i= 0;i<=n;i++) {
      puts("Hello, world!\n");
        }
  }
  int n = 5;
  hello_world(n);
  return(0);
}
