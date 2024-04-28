#include <stdio.h>
/**
 * 栈
 * 先进后出
 */
#define MaxSize 50
typedef int ElemType;

typedef struct
{
  ElemType data[MaxSize];
  int top; // 栈顶
} SqStack;

void InitStack(SqStack &s)
{
  s.top = -1; // 表示栈为空
}

// 判断栈是否为空
bool IsEmpty(SqStack &s)
{
  if (s.top == -1)
  {
    return true;
  }
  return false;
}

// 入栈
bool Push(SqStack &s, ElemType v)
{
  if (s.top == MaxSize - 1)
  {
    return false; // 防止越界
  }
  s.data[++s.top] = v;
  return true;
}
// 出栈
bool Pop(SqStack &s)
{
  if (IsEmpty(s))
  {
    return false;
  }
  s.top = s.top - 1;
  return true;
}

// 读取栈顶元素
ElemType GetTop(SqStack &s)
{
  if (IsEmpty(s))
  {
    return -1;
  }
  return s.data[s.top];
}

int main()
{
  SqStack s;
  ElemType v;
  bool flag;
  InitStack(s);
  Push(s, 3);
  Push(s, 4);
  Push(s, 5);
  printf("栈顶元素为%d\n", GetTop(s));
  Pop(s);
  printf("栈顶元素为%d\n", GetTop(s));
  return 0;
}