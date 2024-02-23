#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
  ElementType Data;
  struct tagNode* PrevNode;
  struct tagNode* NextNode;
} Node;

Node* DLL_CreateNode(ElementType NewData) {
  Node* NewNode = (Node*)malloc(sizeof(Node));
  NewNode->Data = NewData;
  NewNode->NextNode = NULL;
  NewNode->PrevNode = NULL;

  return NewNode;
}

void DLL_AppendNode(Node** Head, Node* NewNode) {
  if (*Head == NULL) {
    *Head = NewNode;
  } else {
    Node* Tail = *Head;
    while (Tail->NextNode != NULL) {
      Tail = Tail->NextNode;
    }
    Tail->NextNode = NewNode;
    NewNode->PrevNode = Tail;
  }
}
