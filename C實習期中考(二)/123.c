#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Question5(){
	int Z, I, M, L;
	
	while(1){
		int testcase=1;
		scanf("%d%d%d%d", &Z, &I, &M, &L); // 7 5 12 4
		if(M < L) return;
		if(Z==0 && I==0 && M==0 && L==0) return;
		
		int cycle_length = 0;
		int NRN = L;
		while(1){
			cycle_length++;
			NRN = (Z*NRN+I) % M;
			//printf("%d %d\n", L, NRN);
			if(L == NRN) break;
		}
		
		printf("Case %d: %d\n", testcase, cycle_length);
	}
}

int main(){
	Question5();
	return 0;
}
