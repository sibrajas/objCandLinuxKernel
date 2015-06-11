#include<stdio.h>

typedef unsigned char * bytepointer;

void showbytes(bytepointer x, int len)
{
  int i;
  for(i=0;i<len;i++)
   printf("%.2x",x[i]);
}

void showint(int *x)
{
showbytes((bytepointer)x,sizeof(int));
}
int main()
{
int x = 1024;
int *ptr = &x;
//  int **dptr = &ptr;
showint(ptr);
}
