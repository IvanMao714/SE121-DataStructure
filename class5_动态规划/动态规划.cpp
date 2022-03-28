#include <stdio.h>

int house[] = {2, 3, 5, 6,7, 8,9, 3};
int len = sizeof(house)/sizeof(int);


int total(int i, int *house){
	int s;
	if(i<2){
		s = house[i];
	}
	else{
	
		if(total(i-1) > total(i-2) + house[i]){
			s = total(i-1); 
		}
		else{
			s = total(i-2) + house[i];
		}
	}
	
	return s;
}

/*int total2{
	int sum[len];
	if()
}*/
int main(){

	printf("%d", total(len -1), house);
	//printf("%d", total2(len-1)); 
	return 0;
} 
