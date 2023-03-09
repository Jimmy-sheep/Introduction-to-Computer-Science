#include<stdio.h>
#include<string.h>

typedef struct employee {
	int em_id;
	char em_name[10];
	int em_age;
	char em_phone[12];
	float em_salary;
} employee_t;

void employee_info(employee_t my_emp) {
	printf("員工編號: %d\n", my_emp.em_id);
	printf("員工姓名: %s\n", my_emp.em_name);
	printf("員工年紀: %d\n", my_emp.em_age);
	printf("員工電話: %s\n", my_emp.em_phone);
	printf("員工薪資: %f\n", my_emp.em_salary);
}

int main() {
	employee_t my_emp;

	my_emp.em_id = 0;
	strcpy(my_emp.em_name, "IU Lee");
	my_emp.em_age = 18;
	strcpy(my_emp.em_phone, "0937123456");
	my_emp.em_salary = 1000.30;

	printf("%d\n", (int)sizeof(employee_t));
	employee_info(my_emp);

	printf("\n");

	system("PAUSE");
	return 0;
}
