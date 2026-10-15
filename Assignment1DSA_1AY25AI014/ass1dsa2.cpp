#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int  emp_id;
    enum  jobtype{ FULL_TIME, CONTRACT } ;
    union {
        float salary;
        struct { float hourly_rate; int hours_worked; } contract_info;} pay;
		} Employee;

int main()
{
    int n, i, t;
    float total, bill = 0;
    Employee *ptr;
	printf("Enter number of employees: ");
    scanf("%d", &n);
	ptr = (Employee *) malloc(n * sizeof(Employee));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }

   for (i = 0; i < n; i++) {
    printf("\nEmployee %d\n", i + 1);
    printf("Enter name and emp_id: ");
    scanf("%s %d", (ptr + i)->name, &(ptr + i)->emp_id);
	printf("Enter type (0 = Full-time, 1 = Contract): ");
    scanf("%d", &t);

    if (t == 0) {
        (ptr + i)->type=FULL_TIME;
        printf("Enter monthly salary: ");
        scanf("%f", &(ptr + i)->pay.salary);
        } 
	else {
        (ptr + i)->type = CONTRACT;
        (ptr + i)-> = CONTRACT;
        printf("Enter hourly rate and hours worked: ");
        scanf("%f %d",
        &(ptr + i)->pay.contract_info.hourly_rate,
        &(ptr + i)->pay.contract_info.hours_worked);
        }}

    printf("\n=== PAYSLIPS ===\n");
    for (i = 0; i < n; i++) {
        printf("\n Name   : %s\n", (ptr + i)->name);
        printf("Emp ID : %d\n", (ptr + i)->emp_id);

    if ((ptr + i)->type == FULL_TIME) {
            total = (ptr + i)->pay.salary;
            printf("Type   : Full-time\n");
            printf("Salary : %.2f\n", (ptr + i)->pay.salary);
        } 
	else {
       total = (ptr + i)->pay.contract_info.hourly_rate *
        (ptr + i)->pay.contract_info.hours_worked;
        printf("Type   : Contract\n");
        printf("Rate   : %.2f x %d hours\n",
        (ptr + i)->pay.contract_info.hourly_rate,
        (ptr + i)->pay.contract_info.hours_worked);
        }
    printf("Total Pay: %.2f\n", total);
    bill = bill + total;}
    printf("\n=====\n");
    printf("Total salary bill of the company: %.2f\n", bill);
	free(ptr);
    return 0;
}
