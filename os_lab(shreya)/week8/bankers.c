#include <stdio.h>
int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    int alloc[10][10], request[10][10];
    int avail[10];
    int work[10];
    int finish[10] = {0};
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for P%d\n", i);
        printf("Enter Allocation:\n");
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
        printf("Enter Request:\n");
        for (int j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }
    printf("\nEnter Available Resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }
    for (int i = 0; i < m; i++) {
        work[i] = avail[i];
    }
    int count = 0;
    printf("\n--- EXECUTION ---\n");
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int possible = 1;
                for (int j = 0; j < m; j++) {

                    if (request[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }
                if (possible) {

                    printf("P%d is executed ( ", i);

                    for (int j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                        printf("%d ", work[j]);
                    }

                    printf(")\n");

                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found)
            break;
    }
    int deadlock = 0;
    printf("\n--- RESULT ---\n");
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            if (deadlock == 0)
                printf("Deadlocked Processes: ");
            printf("P%d ", i);
            deadlock = 1;
        }
    }
    if (!deadlock)
        printf("System is NOT in Deadlock");
    printf("\n\nProcess\tAllocation\tRequest\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < m; j++)
            printf("%d ", alloc[i][j]);
        printf("\t\t");

        for (int j = 0; j < m; j++)
            printf("%d ", request[i][j]);

        printf("\n");
    }

    return 0;
}