#include <stdio.h>

// 顺序表删除元素
int removeElement(int a[], int n, int t)
{
  for (int i = 0; i < n; i++)
  {
    if (a[i] == t)
    {
      for (int j = i; j < n - 1; j++)
      {
        a[j] = a[j + 1];
      }
      n--;
    }
  }
  return n;
}

int insetElement(int a[], int n, int p, int t)
{
  if (p > n)
  {
    return n;
  }
  for (int i = n; i > p; i--)
  {
    a[i] = a[i - 1];
  }
  a[p] = t;
  return n + 1;
}

int main()
{
  int a[] = {3, 2, 5, 8, 4, 7, 6, 9};

  int n = sizeof(a) / sizeof(a[0]);

  int new_n = removeElement(a, n, 8);
  for (int i = 0; i < new_n; i++)
  {
    printf("%d ", a[i]);
  }

  return 0;
}