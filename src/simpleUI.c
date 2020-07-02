//#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
#define MAX 100

int main (){

  char in[60];

  List *list = init_history();

  char choice;

  int innerSel;

  while(choice != -1){

    printf("enter '1' to tokenize a string");
    printf("\n");
    printf("enter '2' to print history");
    printf("\n");
    printf("enter '-1' to quit");
    printf("\n");



    scanf("%d",&choice);

    char tmp;

    scanf("%c",&tmp);



    if(choice == 1){

      printf("Enter string to tokenize:\n > ");

      fgets(in,100,stdin);

      add_history(list,in);

      char **tokens = tokenize(in);

      print_tokens(tokens);/*print tokens*/

      free_tokens(tokens); /*free the emmory used to allocate the tokens*/



    }

    if(choice == 2){

      printf("\nHistory of strings:\n");

      print_history(list);

      printf("\nSelect a string number to print or -1 to go back\n");



      scanf("%d",&innerSel);

      char tmp;

      scanf("%c",&tmp);

      if(innerSel != -1){

	char ** token = tokenize(get_history(list,innerSel));

	print_tokens(token);

	free_tokens(token);

      }

    }

  }

  printf("Thank you for participating, Exiting...");
  free_history(list);

  return 0;
}

  
