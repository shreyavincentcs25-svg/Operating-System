#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int allocation[10], request[10];
    int available;
    printf("\nEnter Allocation for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &allocation[i]);
    }
    printf("\nEnter Request for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }
    printf("\nEnter Available Resources: ");
    scanf("%d", &available);
    printf("\n--- INITIAL TABLE ---\n");
    printf("\nProcess\tAllocation\tRequest\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n",
               i, allocation[i], request[i]);
    }
    printf("\nAvailable Resources = %d\n", available);
    int finish[10] = {0};
    int count = 0;
    printf("\n--- EXECUTION TABLE ---\n");
    printf("\nProcess\tAvailable Before\tAvailable After\n");
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0 &&
                request[i] <= available) {
                int before = available;
                available += allocation[i];
                int after = available;
                printf("P%d\t%d\t\t\t%d\n",
                       i, before, after);
                finish[i] = 1;
                found = 1;
                count++;
            }
        }
        if (!found)
            break;
    }

    printf("\n--- FINISH STATUS ---\n");
    printf("\nProcess\tFinish\n");
    for (int i = 0; i < n; i++) {
        if (finish[i])
            printf("P%d\tTrue\n", i);
        else
            printf("P%d\tFalse\n", i);
    }

    // Deadlock Check
    int deadlock = 0;

    printf("\n--- RESULT ---\n");

    for (int i = 0; i < n; i++) {

        if (finish[i] == 0) {

            if (deadlock == 0)
                printf("Deadlocked Processes: ");

            printf("P%d ", i);

            deadlock = 1;
        }
    }

    if (deadlock == 0)
        printf("System is NOT in Deadlock");

    return 0;
}