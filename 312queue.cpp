#include <stdio.h>

#define MaxSize 10

typedef int ElemType;
typedef struct {
  ElemType data[MaxSize];
  int front, rear;
} SqQueue;

void initQueue(SqQueue &Q) {
  Q.front = Q.rear = 0;
}

bool queueEmpty(SqQueue Q) {
  if (Q.rear == Q.front) {
    return true;
  } else {
    return false;
  }
}
bool enQueue(SqQueue &Q, ElemType x) {
  if ((Q.rear + 1) % MaxSize == Q.front) {
    return false;
  }
  Q.data[Q.rear] = x;
  Q.rear = (Q.rear + 1) % MaxSize;
  return true;
}

bool deQueue(SqQueue &Q, ElemType &x) {
  if (queueEmpty(Q)) {
    return false;
  }
  x = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}

int main () {
  SqQueue Q;
  initQueue(Q);
  enQueue(Q, 5);
  enQueue(Q, 4);
  enQueue(Q, 3);
  enQueue(Q, 2);
  ElemType eqEle;
  deQueue(Q, eqEle);
  queueEmpty(Q);


  return 0;
}