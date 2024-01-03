#include <stdio.h>

void increment();

void change();

#define N 5

int main()
{
  int *intPtr;

  printf("intPtr's address is %p\n", &intPtr);

  int x = 1;
  // x 的 值发生了改变
  increment(&x);
  printf("%d\n", x);

  char c[] = "hello";
  change(c);
  puts(c);

  return 0;
}

void increment(int *p)
{
  *p = *p + 1;
}

void change(char *c)
{
  *c = 'H';
  c[1] = 'E';
  *(c + 2) = 'L';
}