#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
typedef struct LNode
{
  ElemType data;
  struct LNode * next;
} LNode, *LinkList;

/**
 * @brief 在L链表的i位置（索引）插入数据e
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 
 * @return false 
 */
bool ListInsert(LinkList &L, int i, ElemType e) {
  if (i < 1)
    return false;
  LNode *cur;
  int j = 0;
  cur = L;
  while(cur != NULL && j < i-1) {
    cur = cur -> next;
    j++;
  }

  if (cur == NULL)
    return false;
  LNode *s = (LNode *) malloc(sizeof(LNode));
  s -> data = e;
  s -> next = cur -> next;
  cur -> next = s;
  return true;

}

bool initLinkList(LinkList &L) {
  L = (LinkList) malloc(sizeof(LNode));
  if (L == NULL)
    return false;
  L->next = NULL;
  return true;
}

// 将 27 -> 16 -> 10 反转 为 10 -> 16 ->27
// 头插法
// 缓存当前结点cur，头插法insert
void reserveLinkList(LinkList &L) {
  if (L == NULL) return;
  if (L -> next == NULL) return;
  LinkList cur = L -> next -> next;
  if (cur) {
    L -> next -> next = NULL;
  }
  while (cur != NULL) {
    LinkList tem = cur -> next ;
    LinkList b = L -> next;
    cur -> next = b;
    L -> next = cur;
    cur = tem;
  }

}


int main() {
  LinkList linkList;
  initLinkList(linkList);
  ListInsert(linkList, 1, 27);
  ListInsert(linkList, 2, 16);
  ListInsert(linkList, 3, 10);
  reserveLinkList(linkList);


  // printf("%d\n", result);
  return 0;
}
