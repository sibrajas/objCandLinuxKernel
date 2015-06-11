#include<stdio.h>
int main()
{
   int arr[]={4,5,6,3,6,34,6,64,11,34545,454};
   int size = sizeof(arr)/sizeof(arr[0]);
   printf("Size of Array is %d", size);
   return 0;
}
