#include<stdio.h>

int gcd(int a, int b){
	if(a%b == 0) return b;
	else return gcd(b,a%b);
} 

int main(){
	int a,b;
	
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d",gcd(a,b));
}
