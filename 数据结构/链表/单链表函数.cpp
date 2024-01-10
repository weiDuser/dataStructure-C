#include <stdio.h>
#include <stdlib.h>
#include "单链表函数.h"

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
  printf("\n");
}

LNode *GetElemByIndex(LinkList L, int i)
{
  int j = 1;
  LNode *p = L->next;
  if (i == 0)
    return L;
  if (i < 1)
    return NULL;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  return p;
}

LNode *GetElemByVal(LinkList L, ElemType val)
{
  LNode *p = L->next;
  while (p != NULL && p->data != val)
  {
    p = p->next;
  }
  return p;
}

bool ListInsert(LinkList L, int i, ElemType val)
{
  LinkList p = GetElemByIndex(L, i - 1);
  if (p == NULL)
  {
    return false;
  }
  LinkList s = (LinkList)malloc(sizeof(LNode));
  s->data = val;
  s->next = p->next;
  p->next = s;
  return true;
}

bool ListDel(LinkList L, int i)
{
  LinkList p = GetElemByIndex(L, i - 1);
  if (p == NULL)
  {
    return false;
  }
  LNode *s = p->next;

  p->next = s->next;
  free(s);
  return true;
}