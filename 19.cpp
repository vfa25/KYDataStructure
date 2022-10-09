#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// P19-13

int getMinNumNoHas(int A[], int length) {
  int i = 0, *B;
  B = (int *)malloc(sizeof(int) * length);
  memset(B, 0, sizeof(int) * length);
  for(i = 0; i < length; i++)
    if (A[i] > 0 && A[i] <= length)
      B[A[i] - 1] = 1;
  for (i=0; i < length; i++)
    if (B[i] == 0) break;
  return i + 1;
}

int main() {
  int originData[] = { -1,3,4 };
  int result = getMinNumNoHas(originData, sizeof(originData) / sizeof(int));
  printf("%d\n", result);
  return 0;
}