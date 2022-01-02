#include<stdio.h>

int main(){
	int decimal ;
	scanf("%d",&decimal);
	int binary[20] = {0,};
	int position = 0;
	int count= 0;
	while(1){
		binary[position] = decimal % 2 ;
		
		
		decimal = decimal / 2 ;
		
		position++ ;
		
		if(decimal == 0) break;
	}
	int i;
	
	for (i = position -1; i>=0; i--){
		printf("%d", binary[i]);
		if(binary[i]== 1) count++;
	}
	printf("\n");
	printf("%d",count);
	
	return 0;
}
