#include<stdio.h>
void main()
{
int a=10, b=5, temp;
printf("Numbers before swap: A=%d and B=%d\n",a,b);
temp=a;
a=b;
b=temp;
printf("Numbers after swap: A=%d and B=%d\n",a,b);
}
