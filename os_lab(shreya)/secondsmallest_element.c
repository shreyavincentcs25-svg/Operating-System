#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the no. of Elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if(n < 2) {
        printf("Need at least two elements.\n");
        return 0;
    }
    int smallest = arr[0];
    int secondsmallest = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] < smallest) {
            secondsmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < secondsmallest && arr[i] != smallest) {
            secondsmallest = arr[i];
        }
    }
    if(smallest == secondsmallest)
        printf("No second smallest element found.\n");
    else
        printf("Second smallest: %d\n", secondsmallest);

    return 0;
}
