#include <stdio.h>
#include <math.h>
struct point{
	float x;
	float y;
	float z;
}; 
int main(){
	point p1, p2;
	float l;
	scanf("%f %f %f %f %f %f", &p1.x, &p1.y, &p1.z, &p2.x, &p2.y, &p2.z);
	l = sqrt(pow((p1.x -p2.x), 2) + pow((p1.y - p2.y), 2) + pow((p1.z - p2.z), 2));
	printf("the length is %f", l);
} 
