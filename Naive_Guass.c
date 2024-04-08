
#include <stdio.h>

#define MAX_SIZE 10

void naive_gaussian(float A[MAX_SIZE][MAX_SIZE + 1], int n) {
    // Displaying augmented matrix before Gaussian elimination
    printf("Augmented matrix before Gaussian elimination:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        // Partial pivoting
        for (int k = i + 1; k < n; k++) {
            if (A[i][i] < A[k][i]) {
                for (int j = 0; j <= n; j++) {
                    float temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
            }
        }

        // Gaussian elimination
        for (int k = i + 1; k < n; k++) {
            float factor = A[k][i] / A[i][i];
            for (int j = i; j <= n; j++) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    // Displaying augmented matrix after Gaussian elimination
    printf("Augmented matrix after Gaussian elimination:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Back substitution
    float x[MAX_SIZE];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = A[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    // Displaying solution
    printf("Values of x1, x2, x3:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, x[i]);
    }
}

int main() {
    int n;
    float A[MAX_SIZE][MAX_SIZE + 1];
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix coefficients row-wise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f/t", &A[i][j]);
        }
    }

    naive_gaussian(A, n);

    return 0;
}
