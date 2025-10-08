#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} Node;

void printlist(Node* first);

int main() {
  Node* first = NULL;

  int n = 0;
  printf("The number of the nodes:");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;

    printf("Node %d:", i);
    scanf("%d", &newNode->data);

    if (first == NULL)
      first = newNode;
    else
      first->next = newNode;

    first = newNode;
  }
  printlist(first);
}

void printlist(Node* ptr) {
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}
