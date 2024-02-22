#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 링크드 리스트 노드 표현
typedef struct tagNode {
  ElementType Data;          // 데이터
  struct tagNode* NextNode;  // 다음 노드
} Node;

// 노드 생성
Node* SLL_CreateNode(ElementType NewData);
// 노드 소멸
void SLL_DestoryNode(Node* Node);

// 노드 추가, 포인터의 주소를 넘겨서 포인터 자체를 바꿀 수 있다
void SLL_AppendNode(Node** Head, Node* NewNode);

// 노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location);

// 노드 삭제 연산
void SLL_RemoveNode(Node** Head, Node* Remove);

// 노드 삽입 연산
void SLL_InsertAfter(Node* Current, Node* NewNode);

// 노드 개수 세기 연산
int SLL_GetNodeCount(Node* Head);

void SLL_InsertNewHead(Node** Head, Node* NewHead);

#endif
