#include <stdio.h>

int add( int a, int b)
{
	return a + b;
}


int main(){
	int res= add(2,6);
	printf("sum : %d\n", res);
	return 0;
}
