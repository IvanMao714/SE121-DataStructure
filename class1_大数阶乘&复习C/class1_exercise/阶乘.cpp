#include <stdio.h> 
int main()
{
    int n, r =1;
    printf("please enter a number");
    scanf("%d", &n);
    if(n >13){
    	printf("结果溢出");
    }
    else if(n<0){
    	printf("非法输入");
    }
    while(n>1){
    	r= r * n;
    	n = n - 1;
    }
    printf("%d", r);
	return 0;
		
}
