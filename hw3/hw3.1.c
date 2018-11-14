#include <stdio.h>

int main(void) {
	int salary_per_month;
	int annual_salary = 0;

	scanf("%d ", &salary_per_month);
	if(salary_per_month <= 30000){
		annual_salary += salary_per_month*13.5;
	}
	else if(salary_per_month > 30000 && salary_per_month <= 50000){
		annual_salary += salary_per_month*14;
	}
	else if(salary_per_month > 50000 && salary_per_month <= 70000){
		annual_salary += salary_per_month*14.5;
	}
	else if(salary_per_month > 70000){
		annual_salary += salary_per_month*18;
	}
	printf("%d\n", annual_salary);
	return 0;
}
