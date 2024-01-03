#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

// 头插法 0->6->5->4->3->2->1
LinkList ListHeadInsert(LinkList &L, ElemType nums[]);

// 尾插法 0->1->2->3->4->5->6
LinkList ListTailInert(LinkList &L, ElemType nums[]);

void PrintList(LinkList L);

int main()
{

  LinkList L;
  int a[6] = {1, 2, 3, 4, 5, 6};
  // ListHeadInsert(L, a);
  ListTailInert(L, a);
  PrintList(L);
  return 0;
}

LinkList ListHeadInsert(LinkList &L, ElemType nums[])
{
  LNode *s;

  L = (LinkList)malloc(sizeof(LNode)); // 申请头节点空间

  L->next = NULL;

  for (int i = 0; i < 6; i++)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = nums[i];
    s->next = L->next;
    L->next = s;
  }
  printf("%d", L->data);
  return L;
}

LinkList ListTailInert(LinkList &L, ElemType nums[])
{
  L = (LinkList)malloc(sizeof(LNode));

  LNode *s, *r = L; // *代表链表表尾，指向链表尾部

  for (int i = 0; i < 6; i++)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = nums[i];
    r->next = s;
    r = s;
  }
  r->next = NULL;
  printf("%d", L->data);
  return L;
}

void PrintList(LinkList L)
{
  L = L->next;
  while (L != NULL)
  {
    printf("->%d", L->data);
    L = L->next;
  }
}
