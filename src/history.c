#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

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
