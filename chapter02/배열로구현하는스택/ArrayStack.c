#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 스택의 노드
typedef struct tagNode {
  ElementType Data;
} Node;

// 스택 구조체
typedef struct tagArrayStack {
  int Capacity;  // 용량
  int Top;       // 최상위 노드의 위치
  Node* Nodes;   // 노드 배열
} ArrayStack;

// 스택 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
  // 자유 저장소에 스택 생성
  *Stack = (ArrayStack*)malloc(sizeof(ArrayStack));

  // 입력된 Capacity 만큼의 노드를 자유 저장소에 생성
  (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);
  // Capacity 및 Top 초기화
  (*Stack)->Capacity = Capacity;
  (*Stack)->Top = -1;
}

// 스택 내의 노드와 스택을 소멸
void AS_DestoryStack(ArrayStack* Stack) {
  free(Stack->Nodes);
  free(Stack);
}

// 노드 삽입 연산
void AS_Push(ArrayStack* Stack, ElementType Data) {
  Stack->Top++;
  Stack->Nodes[Stack->Top].Data = Data;
}

// 노드 제거 연산
ElementType AS_Pop(ArrayStack* Stack) {
  return Stack->Nodes[Stack->Top--].Data;
}

// 노드 최상위 데이터 반환 연산
ElementType AS_Top(ArrayStack* Stack) { return Stack->Nodes[Stack->Top].Data; }

// 스택 사이즈 반환
int AS_GetSize(ArrayStack* Stack) { return Stack->Top + 1 }

// 스택 비어있는지 여부 반환
int AS_IsEmpty(ArrayStack* Stack) { return Stack->Top == -1 }
