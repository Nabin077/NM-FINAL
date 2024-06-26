#include <stdio.h>

int main() {
    int n, i, j, k;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    float original_mat[n][n], l[n][n], u[n][n];

    printf("Enter the data inside the matrix below\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &original_mat[i][j]);
        }
    }

    printf("Your original matrix is \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f\t", original_mat[i][j]);
        }
        printf("\n");
    }

    // Initializing the lower and upper triangular matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i > j) {
                l[i][j] = 0; // Lower triangular matrix
                u[i][j] = 0; // Upper triangular matrix
            } else if (i == j) {
                l[i][j] = 1; // Diagonal of lower triangular matrix
                u[i][j] = original_mat[i][j]; // Diagonal of upper triangular matrix
            } else {
                l[i][j] = 0; // Lower triangular matrix
                u[i][j] = original_mat[i][j]; // Upper triangular matrix
            }
        }
    }

    // Performing LU decomposition
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            l[j][i] = original_mat[j][i] / u[i][i]; // Compute lower triangular matrix
            for (k = i; k < n; k++) {
                u[i][k] = original_mat[i][k]; // Compute upper triangular matrix
            }
            for (k = i; k < n; k++) {
                original_mat[j][k] -= l[j][i] * u[i][k]; // Update original matrix
            }
        }
    }


    // Print Lower Triangular Matrix
    printf("\nLower Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f\t", l[i][j]);
        }
        printf("\n");
    }

    // Print Upper Triangular Matrix
    printf("\nUpper Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f\t", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}
