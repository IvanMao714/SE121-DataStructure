#include <stdio.h> 
int main()
{
    int M ;
    scanf("%d",& M);
    if(M>=100)
	{
		printf("���������");
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
	    printf("��������ȷ����");
	}
	return 0;
		
}
