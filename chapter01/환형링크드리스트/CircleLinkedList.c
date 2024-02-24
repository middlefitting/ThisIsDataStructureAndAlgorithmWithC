#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
  ElementType Data;
  struct tagNode* PrevNode;
  struct tagNode* NextNode;
} Node;

// 노드 추가연산 테일과 헤드 사이에 새 노드를 삽입한다.
void CDLL_AppendNode(Node** Head, Node* NewNode) {
  if (*Head == NULL) {
    *Head = NewNode;
    (*Head)->NextNode = *Head;
    (*Head)->PrevNode = *Head;
  } else {
    Node* Tail = (*Head)->PrevNode;
    Tail->NextNode->PrevNode = NewNode;
    Tail->NextNode = NewNode;
    NewNode->NextNode = (*Head);
    NewNode->PrevNode = Tail;
  }
}
