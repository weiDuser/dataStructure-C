#include <stdio.h>
#include <stdlib.h>
#include "单链表函数.cpp"

int main()
{

  LinkList L;
  int a[6] = {1, 2, 3, 4, 98, 6};
  // ListHeadInsert(L, a);
  ListTailInert(L, a);
  PrintList(L); // 打印链表

  LinkList search = GetElemByIndex(L, 4);
  if (search != NULL)
  {
    printf("%d\n", search->data);
  }
  search = GetElemByVal(L, 98);
  if (search != NULL)
  {
    printf("%d\n", search->data);
  }

  ListInsert(L, 3, 70);
  PrintList(L);
  ListDel(L, 3);
  PrintList(L);
  return 0;
}
