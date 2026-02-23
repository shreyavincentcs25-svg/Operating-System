#include <stdio.h>

int main() {
    int n, i, j, sum = 0;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sum of left diagonal (where row index == column index)
    for(i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of left diagonal = %d\n", sum);

    return 0;
}
