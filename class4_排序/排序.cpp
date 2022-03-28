#include <stdio.h>
#define len 10 

int* Bobblesort(int* list){
	int t;
	for (int i = 0; i < 9; i++) {
		for(int j=0; j < 9 - i; j++) {
			if(list[j]>list[j+1]){
				t = list[j+1];
				list[j+1] = list[j];
				list[j] = t;
			}
		}
			
	}
	return list;
}

int* Selectsort(int* list){
	
	for(int i=0; i<len;i++){
		int min =i;
		for(int j=i+1; j<len;j++){
			if(list[j]<list[min]){
				min =j;
			}
		}
		
		if(i != min){
			int t = list[i];
			list[i] = list[min];
			list[min] = t;
		}
	}
	return list;
}

int* Insertsort(int* list){
	int t;
	int j;
	for(int i=1; i<10; i++){
		t = list[i];
		if(list[i]<list[i-1]){
			for(j = i-1; t< list[j]; j--){
				list[j+1] = list[j];
			}
			list[j+1] = t;
		}	
	}
	return list;
}

int* Shellsort(int* list){
	int t,j,l,i;
	for(int l = len/2; l>0; l/=2){
		for(i=l;i<len;i++){
			if(list[i]<list[i-l]){
				t = list[i];
				for(j=i-l;j>=0&&t<list[j]; j-=l){
					list[j+l] = list[j];
				}
				list[j+l] = t;
			}
		}
	}
	return list;
}

int* Quicksort(int* list){
	int t;
	for (int i = 0; i < 9; i++) {
		for(int j=i; j < 9; j++) {
			if(list[i]>list[j+1]){
				t = list[j+1];
				list[j+1] = list[j];
				list[j] = t;
			}
		}
			
	}
	return list;
}

void Merge(int sr[], int tr[], int i, int m, int n){
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n; k++){
		if(sr[i]<sr[j])
			tr[k]=sr[i++];
		else
			tr[k]=sr[j++];
	}
	if(i<=m){
		for(l=0;l<=n-j;l++){
			tr[k+l]=sr[i+l];
		}
	}
	
	if(j<=n){
		for(l=0; l<=n-j;l++)
			tr[k+1] = sr[j+l];
	}
}
void Msort(int sr[], int tr1[],int s, int t){

	
	int m = len/2;
	int tr2[10];

	if(s==t){
		tr1[s] == sr[s];
	}
	else{
		m = (s+t/2);
		Msort(sr,tr2,s,m);
		Msort(sr,tr2,m+1,t);
		Merge(tr2,tr1,s,m,t);
		
	}
	
}

void MergeSort(int *list){
	Msort(list, list, 0, len);
}

int main(){
	
	int l[10] ={1,343,45,667,7,48,67,56,43,23};
	int* nl;
	//nl = Bobblesort(l);
	//nl = Insertsort(l);
	//nl = Shellsort(l);
	//nl = Selectsort(l);
	MergeSort(l);
	for(int i=0; i<10; i++){
		printf("%d\n", l[i]);
	}
	return 0;
} 
