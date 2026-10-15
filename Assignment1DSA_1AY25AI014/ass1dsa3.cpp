#include <stdio.h>
#include <math.h>

typedef struct {
    int   degree;
    float coef[101];   
} polynomial;


polynomial read_poly(char name)
{
    polynomial p;
    int i;
	printf("Enter degree of %c(x): ", name);
    scanf("%d", &p.degree);

    printf("Enter %d coefficients (highest power first): ", p.degree + 1);
    for (i = 0; i <= p.degree; i++)
        scanf("%f", &p.coef[i]);

    return p;
}

float coeff_of(polynomial p, int e)
{
    if (e > p.degree)
    return 0;
    return p.coef[p.degree - e];
}

polynomial add(polynomial a, polynomial b)
{
    polynomial c;
    int e;
	c.degree = (a.degree > b.degree) ? a.degree : b.degree;
	for (e = c.degree; e >= 0; e--)
    c.coef[c.degree - e] = coeff_of(a, e) + coeff_of(b, e);
	return c;
}

void display(polynomial p)
{int i, e, printed = 0;
    float c, absc;
 for (i = 0; i <= p.degree; i++) {
 c = p.coef[i];
    if (c == 0)                    
    continue;

    e = p.degree - i;
    absc = fabs(c);

    if (!printed) 
	{if (c < 0) printf("-");} 
	else 
	{printf(c < 0 ? " - " : " + ");}

    if (absc != 1 || e == 0)
    printf("%g", absc);

    if (e == 1)
    printf("x");
    else if (e > 1)
    printf("x^%d", e);
	printed = 1;
    }

    if (!printed)                     
    printf("0");
    printf("\n");
}

int main()
{
    polynomial A, B, C;
	A = read_poly('A');
    B = read_poly('B');
	printf("\nA(x) = ");
    display(A);
    printf("B(x) = ");
    display(B);

    C = add(A, B);
    printf("A(x) + B(x) = ");
    display(C);

    return 0;
}
