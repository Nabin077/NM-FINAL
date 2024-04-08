//Composite Trapezoid Rule
#include <stdio.h>
#include <math.h>

#define f(x) (3 * (x) * (x) + 2 * (x) - 5)

int main()
{
    float a, h, k, x0, xn, fx0, fxn, term, v;
    printf("Enter Lower and Upper Limit:\n");
    scanf("%f%f", &x0, &xn);
    printf("Enter number of segments:");
    scanf("%f", &k);
    h = (xn - x0) / k;
    fx0 = f(x0);
    fxn = f(xn);
    term = fx0 + fxn; // Initialize term with endpoints
    for (int i = 1; i <= k - 1; i++)
    {
        a = x0 + i * h;
        term += 2 * f(a); // Accumulate the sum of function values
    }
    v = h * term / 2; // Multiply by h/2
    printf("Value of Integration is: %.3f\n", v);
    return 0;
}
