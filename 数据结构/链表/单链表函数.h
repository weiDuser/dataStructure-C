#include <stdio.h>

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

// 按位置查找 NULL代表节点不存在
LNode *GetElemByIndex(LinkList L, int i);

// 按值查找 NULL代表节点不存在

LNode *GetElemByVal(LinkList L, ElemType val);

// 插入节点
bool ListInsert(LinkList L, int i, ElemType val);

// 删除节点
bool ListDel(LinkList L, int i);

// 打印链表
void PrintList(LinkList L);