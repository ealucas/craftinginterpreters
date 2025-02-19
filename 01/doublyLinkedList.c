#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char* elem;
  struct Node* prev;
  struct Node* next;
} Node;

typedef struct {
  Node *head;
  Node *tail;
} DoublyLinkedList;

DoublyLinkedList* newList(){
  DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void insert(DoublyLinkedList* list, const char* newElem){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->elem = (char*)malloc(strlen(newElem) + 1);
  strcpy(newNode->elem, newElem);

  if(list->head == NULL){
    list->head = newNode;
    list->tail = newNode;
  } else {
    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;
  }
}

int find(DoublyLinkedList* list, const char* elem){
  Node *iter = list->head;
  int i = 0;
  while(iter != NULL){
    if(strcmp(iter->elem, elem) == 0){
      return i;
    } 
    i++;
    iter = iter->next;
  }
  return -1;
}

void delete(DoublyLinkedList* list, int index){
  
  if (list->head == NULL) {
    printf("%s\n", "empty list!");
    return;
  }

  Node* aux = list->head;
  int i = 0;

  while (i < index){
    if (aux == NULL){
      printf("%s\n", "Invalid index. too big.");
      return;
    }
    aux = aux->next;
    i++;
  }
  
  if (aux->prev == NULL){
    list->head = aux->next;
    if (list->head != NULL){
      list->head->prev = NULL;
    } else{
      list->tail = NULL;
    }
  } else if (aux->next == NULL){
    list->tail = aux->prev;
    list->tail->next = NULL;
  } else {
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;
  }
  free(aux->elem);
  free(aux);
}

void printList(DoublyLinkedList* list){
  Node* aux = list->head;
  if (aux == NULL) {
    printf("%s\n", "empty list!");
    return;
  }
  while(aux != NULL){
    printf("%s ", aux->elem);
    printf("\n");
    aux = aux->next;
  }
}
void freeList(DoublyLinkedList* list){
  Node* iter = list->head;
  while (iter != NULL){
    Node* temp = iter;
    iter = iter->next;
    free(temp->elem);
    free(temp);
  }
  free(list);
}
int main(){
  DoublyLinkedList *list = newList();

  insert(list, "1st String!");
  insert(list, "2nd String!");
  insert(list, "3rd String!");
  insert(list, "4th String!");

  int foundIndex = find(list, "3rd String!"); 
  printList(list);
  printf("String '3rdString' Found at Index: %d\n", foundIndex);
  printf("Now deleting the 3rd String!\n");
  delete(list, foundIndex);
  printList(list);
  freeList(list);
  
  return 0;
}
