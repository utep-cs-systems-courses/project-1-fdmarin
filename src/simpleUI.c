//#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
#define MAX 100



int main(){
  printf("\n Welcome, Please enter your sentence. To quit enter 0. \n");
  char input[MAX];
  fgets(input, MAX, stdin);

  if(input[0] == '0'){
    printf("Thank you for participating, exiting... ");
    printf("\n");
    exit(0);
  }

  printf("\n");
  printf("word_start testing...\n");
  char *str=&input[0];
  char *start = word_start(str);
  printf("beginning with: %c\n", *start);
  printf("place: %d\n", *start);
  printf("\n");

  printf("word_terminator testing...\n");
  char *end = word_terminator(str);
  printf("ending with: %c\n", *end);
  printf("ending with: %d\n", *end, "\n");

  printf("\n");
  printf("count_words testing...\n");
  int counter = count_words(str);
  printf("your sentence has this many words: %d\n", counter);

  printf("\n");
  printf("tokenizer testing...\n");
  char **token = tokenize(str);

  printf("\n");
  printf("print_tokens testing...\n");
  printf("tokenizing string...: \n");
  print_tokens(token);
  free_tokens(token);
}
    
