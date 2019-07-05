#include <stdio.h>

int main(){
	unsigned int x, y; // input

	while(scanf("%d %d", &x, &y)!= EOF){
		int check = 0; // check number of carry
		int carry = 0; // carry or not carry, 0 is not carry
		if(x == -1 || y == -1) return 0;
		if(x >= 1000000000 || y >= 1000000000) return 0; 
		
		int temp_x, temp_y;
		while((x+y+check) >= 10){
			temp_x = x % 10;
			temp_y = y % 10;

			if(carry == 1){
				if((temp_x + temp_y + 1) >= 10){
					check++;				
					carry = 1;
				}
				else carry = 0;
			}
			else{
				if((temp_x + temp_y) >= 10){
					check++;				
					carry = 1;
				}
				else carry = 0;
			}

			x /= 10;
			y /= 10;
		}
		if(check > 0)	printf("%d carry operations\n", check);
		else printf("No carry operations\n");
	} 
	
	return 0;
} 
