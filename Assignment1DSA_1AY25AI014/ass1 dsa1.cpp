#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[20];
    float marks;
};

int main()
{
    int n, i;
    float sum;
    char ch;
    struct Student *ptr, *top;

   
    printf("Enter number of students: ");
    scanf("%d", &n);

    ptr = (struct Student *) malloc(n * sizeof(struct Student));
    if (ptr == NULL) 
	{
    printf("Memory not allocated\n");
    return 1;
    }

  
    for (i = 0; i < n; i++) 
	{
    printf("Enter roll, name, marks: ");
        
	scanf("%d %s %f", &(ptr + i)->roll_no, (ptr + i)->name, &(ptr + i)->marks);
    }

   
    sum = 0;
    top = ptr;
    for (i = 0; i < n; i++) 
	{
    sum = sum + (ptr + i)->marks;
    if ((ptr + i)->marks > top->marks)
        top = ptr + i;
    }
    printf("\nAverage marks: %.2f\n", sum / n);
    printf("Topper: %s (Roll %d, Marks %.2f)\n", top->name, top->roll_no, top->marks);

   
    printf("\nAdd 2 more students? (y/n): ");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y') 
	{
    ptr = (struct Student *) realloc(ptr, (n + 2) * sizeof(struct Student));
    if (ptr == NULL) 
	{
    printf("Memory not allocated\n");
    return 1;
    }

    for (i = n; i < n + 2; i++) 
	{
    printf("Enter roll, name, marks: ");
    scanf("%d %s %f", &(ptr + i)->roll_no, (ptr + i)->name, &(ptr + i)->marks);
    }
        n = n + 2;

    sum = 0;
    top = ptr;
    for (i = 0; i < n; i++) 
	{
    sum = sum + (ptr + i)->marks;
    if ((ptr + i)->marks > top->marks)
    top = ptr + i;
    }
        
	printf("\nUpdated average marks: %.2f\n", sum / n);
    printf("Topper: %s (Roll %d, Marks %.2f)\n", top->name, top->roll_no, top->marks);
    }

   
    free(ptr);
    return 0;
}
