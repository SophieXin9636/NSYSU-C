#include <stdio.h>

int main(void) {
	float length, width, height; // input
	float perimeter, area, surface_area, volume;

	scanf("%f %f %f", &length, &width, &height);
	printf("��: %6f\n", length);
	printf("�e: %6f\n", width);
	printf("��: %6f\n", height);

	perimeter = 4*(length + width + height);
	printf("�P��: %6f\n", perimeter);

	area = length * width;
	printf("���n: %6f\n", area);

	surface_area = 2*(length*height + length*width + width*height);
	printf("���n: %6f\n", surface_area);

	volume = length * width * height;
	printf("��n: %6f\n", volume);
	return 0;
}
