#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef int ElemType;

typedef struct
{
  ElemType data[MaxSize]; // 数组，存储 MaxSize-1 个数据元素
  int front, rear;        // 队列头、队列尾
} SqQueue;

void InitQueue(SqQueue &Q)
{
  Q.front = Q.rear = 0;
}
// 判空
bool IsEmpty(SqQueue Q)
{
  return Q.front == Q.rear;
}
// 入栈
bool EnQueue(SqQueue &Q, ElemType e)
{
  if ((Q.rear + 1) % MaxSize == Q.front)
    return false;
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MaxSize;
  return true;
}
// 出栈
bool DeQueue(SqQueue &Q, ElemType &e)
{
  if (Q.front == Q.rear)
    return false;
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}

int main()
{
  SqQueue Q;
  InitQueue(Q);
  EnQueue(Q, 1);
}