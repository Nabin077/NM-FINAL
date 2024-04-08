//3/8 Composite Rule
#include <stdio.h>
#include <math.h>

#define f(x) ((x) * (x) * (x) + 3 * (x) * (x))

int main() {
    int k;
    float a, h, x0, xn, fx0, fxn, term = 0, v;

    printf("Enter Lower and Upper Limit:\n");
    scanf("%f%f", &x0, &xn);

    printf("Enter number of segments:");
    scanf("%d", &k);

    h = (xn - x0) / k;
    fx0 = f(x0);
    fxn = f(xn);
    term = fx0 + fxn;

    for (int i = 1; i <= k - 1; i++) {
        a = x0 + i * h;
        if (i % 3 != 0) {
            term += 3 * f(a);
        } else {
            term += 2 * f(a);
        }
    }

    v = (3.0 / 8) * h * term;

    printf("Value of Integration is: %.6f\n", v);

    return 0;
}
