#include <stdio.h>
#include <limits.h>
#define MAX_TASKS 100
#define SIM_TIME 50
struct Task {
    int id;
    int execution;
    int period;
    int deadline;
    int remaining;
    int next_release;
    int weight;
};

void resetTasks(struct Task tasks[], int n) {
    for (int i = 0; i < n; i++) {
        tasks[i].remaining = 0;
        tasks[i].next_release = 0;
        tasks[i].deadline = tasks[i].period;
    }
}

void rateMonotonic(struct Task tasks[], int n) {
    printf("\n===== Rate Monotonic Scheduling =====\n");

    for (int time = 0; time < SIM_TIME; time++) {

        for (int i = 0; i < n; i++) {
            if (time == tasks[i].next_release) {
                tasks[i].remaining = tasks[i].execution;
                tasks[i].next_release += tasks[i].period;
            }
        }
        int selected = -1;
        int min_period = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0 && tasks[i].period < min_period) {
                min_period = tasks[i].period;
                selected = i;
            }
        }

        if (selected != -1) {
            printf("Time %d: Task %d\n", time, tasks[selected].id);
            tasks[selected].remaining--;
        } else {
            printf("Time %d: Idle\n", time);
        }
    }
}
void earliestDeadlineFirst(struct Task tasks[], int n) {
    printf("\n===== Earliest Deadline First =====\n");

    for (int time = 0; time < SIM_TIME; time++) {
        for (int i = 0; i < n; i++) {
            if (time == tasks[i].next_release) {
                tasks[i].remaining = tasks[i].execution;
                tasks[i].deadline = time + tasks[i].period;
                tasks[i].next_release += tasks[i].period;
            }
        }

        int selected = -1;
        int earliest_deadline = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0 && tasks[i].deadline < earliest_deadline) {
                earliest_deadline = tasks[i].deadline;
                selected = i;
            }
        }

        if (selected != -1) {
            printf("Time %d: Task %d\n", time, tasks[selected].id);
            tasks[selected].remaining--;
        } else {
            printf("Time %d: Idle\n", time);
        }
    }
}

void proportionalScheduling(struct Task tasks[], int n) {
    printf("\n===== Proportional Scheduling =====\n");

    int current = 0;
    int slice = tasks[0].weight;

    for (int time = 0; time < SIM_TIME; time++) {

        if (slice == 0) {
            current = (current + 1) % n;
            slice = tasks[current].weight;
        }

        printf("Time %d: Task %d\n", time, tasks[current].id);
        slice--;
    }
}
int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    struct Task tasks[MAX_TASKS];
    for (int i = 0; i < n; i++) {
        printf("\nTask %d\n", i + 1);

        tasks[i].id = i + 1;

        printf("Execution Time: ");
        scanf("%d", &tasks[i].execution);

        printf("Period: ");
        scanf("%d", &tasks[i].period);

        printf("Weight: ");
        scanf("%d", &tasks[i].weight);

        tasks[i].remaining = 0;
        tasks[i].next_release = 0;
        tasks[i].deadline = tasks[i].period;
    }

    rateMonotonic(tasks, n);
    resetTasks(tasks, n);
    earliestDeadlineFirst(tasks, n);
    resetTasks(tasks, n);
    proportionalScheduling(tasks, n);
    return 0;
}
