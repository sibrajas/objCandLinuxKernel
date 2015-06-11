#include<stdio.h>
char* toCharArray(int x)
{
char *result;
result = malloc(sizeof(char)*20);
sprintf(result,"%d",x);
return result;
}
int main()
{
int i, x = 19834342;
char * result;
//char result[10];
sprintf(result,"%d",x);
result = toCharArray(x);
sprintf(result,"%d",x);
printf("%s \n",result);
for(i=0;i<9;i++)
printf("%c",result[i]);
return 0;
}
