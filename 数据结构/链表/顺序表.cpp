#include <stdio.h>

#define MaxSize 50

typedef int ElemType;

typedef struct
{
  ElemType data[MaxSize];
  int length;
} SqList;

/* @L 顺序表
 * @i 插入位置
 * @e 插入元素
 * */
bool ListInsert(SqList &L, int i, ElemType e);
void PrintList(SqList L);

int main()
{

  SqList L;     // 定义顺序表 L
  bool ret;     // 返回值：True/False
  ElemType del; // 要删除的元素

  // 先手动在顺序表中赋值
  L.data[0] = 1;
  L.data[1] = 2;
  L.data[2] = 3;
  L.length = 3;

  ret = ListInsert(L, 2, 60);
  if (ret)
  {
    printf("插入成功\n");
    PrintList(L);
  }
  else
  {
    printf("插入失败\n");
    PrintList(L);
  }

  return 0;
}

bool ListInsert(SqList &L, int i, ElemType e)
{
  // 防止溢出
  if (i < 1 || i >= L.length + 1)
  {
    return false;
  }

  if (L.length >= MaxSize)
  {
    return false;
  }

  for (int j = L.length; j >= i; j--)
  {
    L.data[j] = L.data[j - 1];
  }
  L.data[i] = e;
  L.length += 1;
  return true;
}