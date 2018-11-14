#include <stdio.h>

int main(void) {
	int int1, int2, int3, int4; // input integer
	scanf("%d %d %d %d", &int1, &int2, &int3, &int4);
	printf("Num1: %d\n", int1);
	printf("Num2: %d\n", int2);
	printf("Num3: %d\n", int3);
	printf("Num4: %d\n", int4);
	printf("%d + %d - %d * %d = %d\n",int1, int2, int3, int4, int1 + int2 - int3 * int4);
	printf("%d + %d * %d - %d = %d\n",int1, int2, int3, int4, int1 + int2 * int3 - int4);
	printf("%d - %d + %d * %d = %d\n",int1, int2, int3, int4, int1 - int2 + int3 * int4);
	printf("%d - %d * %d + %d = %d\n",int1, int2, int3, int4, int1 - int2 * int3 + int4);
	printf("%d * %d + %d - %d = %d\n",int1, int2, int3, int4, int1 * int2 + int3 - int4);
	printf("%d * %d - %d + %d = %d\n",int1, int2, int3, int4, int1 * int2 - int3 + int4);
	return 0;
}
