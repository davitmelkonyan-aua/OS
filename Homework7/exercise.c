		
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int start_time;
    int completion_time;
} process;


void print_results(char *title, process schedule[], int n) {
    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    double total_response_time = 0;
    int current_time = 0;

    printf("\n=== %s ===\n", title);
    printf("Gantt Chart: |");

    for (int i = 0; i < n; i++) {
        if (schedule[i].start_time > current_time) {
            printf(" IDLE (%d-%d) |", current_time, schedule[i].start_time);
        }

        printf(" P%d (%d-%d) |", schedule[i].pid, schedule[i].start_time, schedule[i].completion_time);

        current_time = schedule[i].completion_time;
    }

    printf("\n\n");

    printf("%-8s %-8s %-8s %-8s %-8s %-8s\n", "PID", "AT", "BT", "WT", "TAT", "RT");

    for (int i = 0; i < n; i++) {
        printf("%-8d %-8d %-8d %-8d %-8d %-8d\n", schedule[i].pid, schedule[i].arrival_time, schedule[i].burst_time, schedule[i].waiting_time, schedule[i].turnaround_time, schedule[i].response_time);

        total_waiting_time += schedule[i].waiting_time;
        total_turnaround_time += schedule[i].turnaround_time;
        total_response_time += schedule[i].response_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
    printf("Average Response Time: %.2f\n", total_response_time / n);
}


void fcfs(process input[], int n) {
    process *schedule = malloc(n * sizeof(process));

    if (schedule == NULL) {
        perror("Memory allocation failed");
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        schedule[i] = input[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (schedule[j].arrival_time > schedule[j + 1].arrival_time) {
                process temp = schedule[j];
                schedule[j] = schedule[j + 1];
                schedule[j + 1] = temp;
            }
        }
    }

    int time = 0;

    for (int i = 0; i < n; i++) {
        if (time < schedule[i].arrival_time) {
            time = schedule[i].arrival_time;
        }

        schedule[i].start_time = time;

        schedule[i].waiting_time = schedule[i].start_time - schedule[i].arrival_time;
        schedule[i].response_time = schedule[i].start_time - schedule[i].arrival_time;
        schedule[i].completion_time = time + schedule[i].burst_time;
        schedule[i].turnaround_time = schedule[i].completion_time - schedule[i].arrival_time;

        time = schedule[i].completion_time;
    }

    print_results("First Come First Served (FCFS)", schedule, n);

    free(schedule);
}


void sjf(process input[], int n) {
    process *schedule = malloc(n * sizeof(process));
    int *completed = calloc(n, sizeof(int));

    if (schedule == NULL || completed == NULL) {
        perror("Memory allocation failed");

        free(schedule);
        free(completed);

        exit(0);
    }

    int time = 0;
    int count = 0;

    while (count < n) {
        int selected = -1;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && input[i].arrival_time <= time) {

                if (selected == -1 || input[i].burst_time < input[selected].burst_time || (input[i].burst_time == input[selected].burst_time && input[i].arrival_time < input[selected].arrival_time)) {
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            int next_arrival = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (!completed[i] && input[i].arrival_time < next_arrival) {
                    next_arrival = input[i].arrival_time;
                }
            }

            time = next_arrival;
            continue;
        }

        schedule[count] = input[selected];

        schedule[count].start_time = time;
        schedule[count].waiting_time = time - input[selected].arrival_time;
        schedule[count].response_time = schedule[count].waiting_time;

        time += input[selected].burst_time;

        schedule[count].completion_time = time;
        schedule[count].turnaround_time = time - input[selected].arrival_time;

        completed[selected] = 1;
        count++;
    }

    print_results("Shortest Job First (SJF)", schedule, n);

    free(schedule);
    free(completed);
}


int main(void) {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process *processData = malloc(n * sizeof(process));

    if (processData == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processData[i].pid = i + 1;

        printf("Enter the arrival time and burst time for process %d: ", i + 1);

        scanf("%d %d", &processData[i].arrival_time, &processData[i].burst_time);
    
        if (processData[i].arrival_time < 0 || processData[i].burst_time <= 0) {
            printf("Arrival time must be non-negative and burst time must be positive.\n");
            free(processData);
            return 1;
        }

        processData[i].turnaround_time = 0;
        processData[i].waiting_time = 0;
        processData[i].response_time = 0;
        processData[i].start_time = 0;
        processData[i].completion_time = 0;
    }

    fcfs(processData, n);
    sjf(processData, n);

    free(processData);

    return 0;
}
