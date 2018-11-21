#include <stdio.h>
#include <stdlib.h>

int sum (int n){
	if (n==0) return n;
	else return n+sum(n-1);
}

int main (){
	int add;
	add=sum(5);
	printf("sum=%d",add);
}