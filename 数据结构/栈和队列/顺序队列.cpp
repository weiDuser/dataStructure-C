#include <stdio.h>
#include <stdlib.h>

/**
 * 队列
 * 先进先出
 *
 * 队列的链式表示称为链队列，它实际上是一个同时带
 * 有队头指针和队尾指针的单链表。头指针指向队头结
 * 点，尾指针指向队尾结点，即单链表的最后一个结点。
 */
typedef int ElemType;

typedef struct QNode
{
  ElemType data;
  struct QNode *next;
} QNode;

struct LinkQueue
{
  QNode *front;
  QNode *rear;
};

void InitQueue(LinkQueue &Q)
{
  Q.front = Q.rear = (QNode *)malloc(sizeof(QNode));
  Q.front->next = NULL;
}

bool EnQueue(LinkQueue &Q, ElemType x)
{
  QNode *s = (QNode *)malloc(sizeof(QNode));
  if (s == NULL)
    return false;
  s->data = x;
  s->next = NULL;
  Q.rear->next = s;
  Q.rear = s;
  return true;
}

bool DeQueue(LinkQueue &Q, ElemType &x)
{
  if (Q.front == Q.rear)
    return false;
  QNode *p = Q.front->next;
  x = p->data;
  Q.front->next = p->next;
  if (Q.rear == p)
    Q.rear = Q.front;
  free(p);
  return true;
}

bool QueueEmpty(LinkQueue Q)
{
  return Q.front == Q.rear;
}

void PrintQueue(LinkQueue Q)
{
  QNode *p = Q.front->next;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void DestroyQueue(LinkQueue &Q)
{
  QNode *p;
  while (Q.front != NULL)
  {
    p = Q.front->next;
    free(Q.front);
    Q.front = p;
  }
}

int main()
{
  LinkQueue Q;
  InitQueue(Q);
  EnQueue(Q, 1);
  EnQueue(Q, 2);
  EnQueue(Q, 3);
  EnQueue(Q, 4);
  EnQueue(Q, 5);
  PrintQueue(Q);
  ElemType x;
  DeQueue(Q, x);
  printf("出队元素：%d\n", x);
  PrintQueue(Q);
  return 0;
}