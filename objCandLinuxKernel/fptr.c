#include<stdio.h>
int add(int a,int b) { return a+b; }
int sub(int a,int b){ return a-b; }
int mul(int a,int b){ return a*b; }
int (*operation)(int,int) = NULL;  // Declaring a function pointer
//typedef int (*operation)(int,int);
int anyop(int a, int b, int (*operation)(int,int))  // Passing a function pointer as an argument
{
	int result = operation(a,b);  // Using ptr to assing result
	printf(" Result is %d \n", result);
return 1;
}
/*int anyop1(int a ,int b, fptr)
{

}*/


int main()
{
char char1;
operation = &mul; 
printf(" Call function pointer directly %d \n", (*operation)(4,5));
while(1)
{
//sleep(10);
//wait();
scanf("%c",&char1);
//if(operation == &mul) //Comparing function pointers
if(char1 == 'm')
anyop(5,6,operation);  
else if(char1 == 's')
anyop(8,5,&sub);
 
} // Specific functionality
return 1;
}
	
