//Composite 1/3 Rule
#include <stdio.h>
#include <math.h>

#define f(x) (1.0 / (1 + (x))) // Corrected macro definition

int main() {
    int i;
    float a, h, x0, xn, fx0, fxn, term, v;
    int k; // Changed data type of k to int for consistency

    printf("Enter Lower and Upper Limit:\n");
    scanf("%f%f", &x0, &xn);
    
    printf("Enter number of segments:");
    scanf("%d", &k);

    h = (xn - x0) / k;
    fx0 = f(x0);
    fxn = f(xn);
    term = fx0 + fxn;

    for (i = 1; i <= k - 1; i += 2) {
        a = x0 + i * h;
        term += 4 * f(a);
    }

    for (i = 2; i <= k - 2; i += 2) {
        a = x0 + i * h;
        term += 2 * f(a);
    }

    v = h / 3 * term;
    printf("Value of Integration is: %.3f\n", v);
    return 0;
}
