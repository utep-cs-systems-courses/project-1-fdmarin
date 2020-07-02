#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

/*initialize the linked list to keep history*/

List* init_history(){

  List *head = (List*)malloc(sizeof(List)); /*allocate space for the list*/

  head->root = NULL;

  return head;

}



/*Helper method to copy a string and allocate memory for the string with copy_str*/

char *str_copy(char *str){

  char *end = str;

  while(*end != '\0'){

    end++;

  }

  int len = end-str-1;

  return copy_str(str,len); /*return a copy of the whole string*/

}





/*add an item to the end of the list*/

void add_history(List *list, char*str){

  char *copy = str_copy(str);



  if (list->root == NULL) {

    list->root = (Item*) malloc(sizeof(Item));

    list->root->id = 1;

    list->root->str = copy;

    list->root->next = NULL;

  } else {

    Item* current;

    current = list->root;

    while (current->next != NULL) {   /*loop to the last element*/

      current = current->next;

    }//get out of the loop when current->next is null

    current->next = (Item*) malloc(sizeof(Item));
    current->next->id = current->id+1;
    current->next->str = copy;
    current->next->next =NULL;
  }
}

char *get_history(List *list, int id){
  Item* current = list->root;
  while(current != NULL){
    if(current->id == id){
      return current->str;
    }

    if(current->next == NULL){
      return "OutOfBounds";
    }
    else
      {current = current->next;
    }
  }
}

void print_history(List *list){
  Item *current = list->root;
  while(current != NULL){
    printf("%d.- %s \n", current->id, current->str);
    current= current->next;
  }
}

void free_history(List *list){
  Item *current = list->root;
  while(current != NULL){
    free(current->str);
    free(current);
    current = current->next;
  }
  free(list);
}

/*
//Initialize the linked list to keep the history//
List *init_history(){
  List *history;
  history = (List*) malloc(sizeof(List));
  history-> root = NULL;
  return history;
}

// Add a history item to the end of the list.//
void add_history(List *list, char *str) {
  Item* addItem = (Item*) malloc(sizeof(Item)*300);
  addItem->str = str;
  if(list->root == NULL){
    addItem->id = 1;
    list->root = addItem;
  }
  else{
    Item* history_item = list->root;
    addItem->id=1;
    while(history_item->next!=NULL){
      addItem->id++;
      history_item=history_item->next;
    }
    history_item->next=addItem;
    addItem->str = str;
    addItem->id++;
  }
}

//Retrieve the string stored in the node where Item-> id == id
char *get_history(List *list, int id){
  if(list->root == NULL){
    return "empty List";
  }
  else{
    Item* temp = list->root;
    while (temp != NULL){
      if(temp->id == id){
	return temp->str;
      }
      temp = temp->next;
    }
    return "Sorry, Item ID not found\n";
  }
}

//Prints the entire contenets of the list
void print_history(List *list){
  int i = 0;
  Item *temp = list->root;
  while(temp != NULL){
    printf("Item [%d]: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

//Free the hsitory list and the strings it references.
void free_history(List *list){
  Item* temp;
  Item* temp2 = list->root;
  while(temp2 != NULL){
    temp= temp2;
    temp2;
    temp2->next;
    free(temp);
  }
  free(list);
}
*/
