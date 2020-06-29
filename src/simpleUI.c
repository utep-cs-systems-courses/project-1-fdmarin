#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#define MAX 100

int main(){
  char input[100];
  printf("\n Welcome, please enter your sentence. To quit enter 0. \n");
  print("< ");
  fgets(input, MAX, stdin);

  if(input[0] == '0'){
    printf("\n Thank you for participating, exiting... ");
    exit(0);
  }

  printf("%s\n", input);

  char *ws = word_start(input);
  printf("Word starting at: %s\n", ws);

  char *we = word_terminator(input);
  printf("Word ending at: %s\n", we);

  int total_words = count_words(input);
  printf("The total number of words are: %d\n", total_words);

  if(input[0] != '0')
    int keep = main();

  return 0;
}
    
