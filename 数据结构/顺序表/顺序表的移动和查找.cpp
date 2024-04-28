#include <stdio.h>
#include <stdlib.h>

void moveElement1(int a[], int n, int k)
{
  int i, j;
  for (i = 0; i < k; i++)
  {
    int x = a[0];
    for (j = 0; j < n - 1; j++)
    {
      a[j] = a[j + 1];
    }
    a[j] = x;
  }
}

void repElement2(int a[], int n, int k, int low, int high)
{
  for (; low < high; low++, high--)
  {
    int x = a[low];
    a[low] = a[high];
    a[high] = x;
  }
}

void moveElement2(int a[], int len)
{
  for (int i = 0; i < len / 2; i++)
  {
    int x = a[i];
    a[i] = a[len - i - 1];
    a[len - i - 1] = x;
  }
}
int main()
{

  // int a[] = {3, 2, 5, 8, 4, 7, 6, 9};

  // int n, k;

  // n = sizeof(a) / sizeof(a[0]);
  // k = 4;

  // No.1 将前 k 个元素移动到后面去

  // 移动一个元素： 每次把第一个元素用 x 存起来 再将剩下的元素 前移一位， 最后将 x 放到最后， 这样执行 k 次 时间复杂度为 O(n^2)
  // moveElement1(a, n, k);

  // 移动多个元素：
  // 1. 将所有的元素逆序（用两个指针从两头同时向中间逼近进行元素交换）
  // 2. 将前 k 个元素逆序
  // 3. 将剩下的元素逆序
  // 时间复杂度为 O(n)
  // repElement2(a, n, k, 0, n - 1);
  // repElement2(a, n, k, 0, k - 1);
  // repElement2(a, n, k, k, n - 1);

  // for (int c = 0; c < n; c++)
  // {
  //   printf("%d", a[c]);
  // }

  // No.2 将顺序表 a 一分为二， 前半段和后半段按照顺序交换，若有奇数个元素，中间元素不参与交换

  int b[] = {3, 2, 5, 8, 4, 7, 6, 9};
  // int b[] = {3, 2, 5, 8, -1, 4, 7, 6, 9};

  int len = sizeof(b) / sizeof(b[0]);

  moveElement2(b, len);

  for (int i = 0; i < len; i++)
  {
    printf("%d", b[i]);
  }

  return 0;
}