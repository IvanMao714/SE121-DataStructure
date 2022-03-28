#include <stdio.h> 
int main()
{
    int a,b,c ;
    printf("please input a,b,c,space between number ");
    scanf("%d %d %d",&a,&b,&c);
    if(a<=0 || b<=0 || c<=0)
    {
    	printf("illegal input\n");
    }
    else if(a+b<=c || a+c <=b || b+c<=a)
    {
    	printf("not a triangle\n");
    }
    else 
    {
    	if(a==b==c)
    	{
    		printf("equilateral traiangle\n");
   	    }
    	else if(a==b || a==c || b==c)
    	{
    		printf("sosceles traiangle\n");
    	}
    	if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
    	{
    		printf("right traiangle\n");
    	}
    	else if(a*a + b*b >= c*c || a*a + c*c >= b*b || b*b + c*c >= a*a)
    	{
    		printf("acute traiangle\n");
    	}
    	else if(a*a + b*b <= c*c || a*a + c*c <= b*b || b*b + c*c <= a*a)
    	{
    		printf("obtuse traiangle\n");
    	}
	}
	return 0;
		
}
