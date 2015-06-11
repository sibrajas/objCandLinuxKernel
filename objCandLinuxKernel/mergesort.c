#include<stdio.h>
/*void mergesort(int arr[],int length, int low, int high)
{
 int mid=(low+high)/2;
 if(low<high){
   mergesort(arr,length, low,mid);
   mergesort(arr,length, mid+1,high);
   merge(arr,length, low,mid,high);}
}*/

void merge(int arr[],int length, int low, int mid, int high)
{
 int i,helper[length],remaining,helperLeft,helperRight,current;
 for (i=0;i<high;i++)
  helper[i]=arr[i];
 helperLeft = low;
 helperRight = mid+1;
 current = low;
 while(low <= mid && mid <= high){
 if(helper[helperLeft] < helper[helperRight]){
  arr[current] = helper[helperLeft];
  helperLeft++;}
 else{
  arr[current] = helper[helperRight];
  helperRight++;}
 current++;
 }
 if(low < mid)
  { 
  remaining = mid - low; 
  for(i=0;i<remaining;i++)
      arr[current+i] = helper[helperLeft+i]; 
  }
return;
}
void mergesort(int arr[],int length, int low, int high)
{
 int mid=(low+high)/2;
 if(low<high){
   mergesort(arr,length, low,mid);
   mergesort(arr,length, mid+1,high);
   merge(arr,length, low,mid,high);}
}
 
int main()
{
 int arr[10]={6,3,76,2,1,7,85,4,6,9};
 mergesort(arr,10,0,9);
return 0;
} 


