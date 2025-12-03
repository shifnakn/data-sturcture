#include <stdio.h>
 int myfunction(int x,int y)
{
	int c;
	c = x + y;
	return(c);
}
 int main()
{
	int a,b;
	printf("Enter two numbers: ");
	scanf("%d%d",&a,&b);
	int result = myfunction(a,b);
	printf("Result is = %d",result);
	return 0;
}
