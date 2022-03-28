#include <stdio.h> 
int main()
{
	char input;
	printf("please enter a character!");
	scanf("%c", &input);
	input = input - 32;
	printf("the resault is %c", input);
	return 0;
		
}
