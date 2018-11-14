#include <stdio.h>
#include <ctype.h>

int main(void) {
	char inputChar, buffer;
	FILE *fptr = fopen("input1.txt", "w+");
	
	printf("請輸入要尋找的字元： ");
	scanf("%c", &inputChar);
	scanf("%c", &buffer); // eat '\n'
	
	while(inputChar != '*'){
		srand(1); // rand seed 
		int count = 0 , i=1;

		// randomly generate 1000 character and input to file 
		for(int i=0; i<1000; i++){
			char random_number = rand() % 52; // 0~51
			if(random_number < 26){ // is lower alphabet
				random_number += 65;
				fprintf(fptr,"%c", random_number); // input data to file
			}
			else{ // is upper alphabet
				random_number += 71;
				fprintf(fptr,"%c", random_number); // input data to file
			}

			// statistic
			if(toupper(random_number) == toupper(inputChar)) count++;
		}
		fclose(fptr); // After file is closing, system is wiriting data into file.
		printf("%d\n", count);
		
		printf("請輸入要尋找的字元： ");
		scanf("%c", &inputChar);
		scanf("%c", &buffer); // eat '\n'
	}	
	return 0;
}
