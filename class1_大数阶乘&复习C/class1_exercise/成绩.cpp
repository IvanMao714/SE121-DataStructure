#include <stdio.h> 
int main()
{
    int M ;
    scanf("%d",& M);
    if(M>=100)
	{
		printf("你活在梦里");
	}
    else if(M>=90 && M<=100)
	{
	    printf("A");
	}
	else if(M>=80 && M<90)
	{
		printf("B");
	}
	else if
	(M>=70 && M<80)
	{
		printf("C");
	}
	else if
	(M>=60 && M <79)
	{
		printf("D");
	}
	else if
	(M>=0 && M < 60)
	{
		printf("E");
	}
	else
	{
	    printf("请输入正确数字");
	}
	return 0;
		
}
