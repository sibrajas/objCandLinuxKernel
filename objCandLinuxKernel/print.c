#include<stdio.h>
int add(int a, int b)
{
   int val = printf("%*c%*c",a,'\a',b,'\b');
   return val;
}
int main()
{
   printf("%d",add(9,7));
   return 0;
}
