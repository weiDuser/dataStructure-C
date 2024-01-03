# 链表

## 线性表

由 n(n>=0)个相同类型的元素组成的有序集合。

线性表是逻辑结构。

顺序表：逻辑上相邻的两个元素物理位置也相邻。（数组）

单链表：逻辑上相邻的两个元素物理位置不相邻。

```c++
typedef struct LNode {
  ElemType data;
  struct LNode *next;
}LNode, *LinkList;
```

头插法
