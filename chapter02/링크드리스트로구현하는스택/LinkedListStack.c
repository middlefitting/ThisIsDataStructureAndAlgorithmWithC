#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
  char* Data;
  struct tagNode* NextNode;
} Node;

// 링크드 리스트의 헤드와 테일의 포인터
typedef strcut tagLinkedListStack {
  Node* List;
  Node* Top;  // 입출력이 이루어지는 테일
}
LinkedListStack;

void LIS_CreateStack(LinkedListStack** Stack) {
  // 스택을 자유 저장소에 생성, 용량에 자유롭다
  *Stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
  *Stack->List = NULL;
  *Stack->Top = NULL;
}

int LLS_IsEmpty(LinkedListStack* Stack) { return Stack->List == NULL }

void LLS_CreateNode(Char* NewData) {
  Node* NewNode = (Node*)malloc(sizeof(Node));
  NewNode->Data = (char*)malloc(strlen(NewData) + 1);
  // 문자열을 만드는 공간을 확보하고 깊은 복사
  strcpy(NewNode->Data, NewData);
  NewNode->NextNode = NULL;
  return NewNode;
}

void LLS_DestoryNode(Node* _Node) {
  // 문자열 할당 해제
  free(_Node->Data);
  free(_Node);
}

void LLS_DestoryStack(LinkedListStack* Stack) {
  while (!LLS_IsEmpty(Stack)) {
    Node* Popped = LLS_Pop(Stack);
    LLS_DestoryNode(Popped);
  }
  free(Stack);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode) {
  if (Stack->List == NULL) {
    Stack->List = NewNode;
  } else {
    Stack->Top->NextNode = NewNode;
  }
  Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack) {
  Node* TopNode = Stack->Top;

  if (Stack->List == Stack->Top) {
    Stack->List = NULL;
    Stack->Top = NULL;
  } else {
    Node* CurrentTop = Stack->List;
    while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) {
      CurrentTop = CurrentTop->NextNode;
    }
    Stack->Top = CurrentTop;
    Stack->Top->NextNode = NULL;
  }
  return TopNode;
}
