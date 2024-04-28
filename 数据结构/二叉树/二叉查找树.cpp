#include <stdio.h>
#include <stdlib.h>

/**
 * 二叉查找树： 左子树小于根节点，右子树大于根节点
 */

typedef struct BTNode
{
  int data;
  struct BTNode *left;
  struct BTNode *right;
} BTNode;

BTNode *createBST(int a[], int n)
{
  BTNode *r, *p, *q, *pa;

  r = NULL;
  for (int i = 0; i < n; i++)
  {
    p = (BTNode *)malloc(sizeof(BTNode));
    p->data = a[i];
    p->left = p->right = NULL;

    if (!r)
    {
      r = p;
    }
    else
    {
      q = r;
      while (q)
      {
        pa = q;

        if (p->data < q->data)
        {
          q = q->left;
        }
        else
        {
          q = q->right;
        }
      }
      if (p->data < pa->data)
      {
        pa->left = p;
      }
      else
      {
        pa->right = p;
      }
    }
  }
  return r;
}

void inOrder(BTNode *r)
{
  if (r)
  {
    inOrder(r->left);
    printf("%d ", r->data);
    inOrder(r->right);
  }
}

int main()
{
  int a[8] = {3, 2, 5, 8, 4, 7, 6, 9};
  int n = sizeof(a) / sizeof(a[0]);

  BTNode *root = NULL;

  // 创建二叉查找树
  root = createBST(a, n);
  printf("中序遍历：");
  inOrder(root);
  printf("\n");

  return 0;
}