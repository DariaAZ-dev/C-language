#include <stdio.h>
#include <math.h>

void solve(int *a, int *b, int *c)
{
    int A = *a;
    int B = *b;
    int C = *c;

    int delta = B * B - 4 * A * C;

    if (delta < 0)
    {
        printf("There is no real solution\n");
    }
    else if (delta == 0)
    {
        double x = -B / (2.0 * A);
        printf("One solution: %.2f\n", x);
    }
    else
    {
        double x1 = (-B - sqrt(delta)) / (2.0 * A);
        double x2 = (-B + sqrt(delta)) / (2.0 * A);
        printf("Two solutions: %.2f and %.2f\n", x1, x2);
    }
}

int main(void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    solve(&a, &b, &c);

    return 0;
}
