//Write a code for First come first serve with same arrival time.
#include<stdio.h>
int main(){
    int n, i;
    int bt[100], ct[100], tat[100], wt[100];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the Burst time for each process: \n");

    for(i = 0; i<n; i++){
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    ct[0] = bt[0];

    for(i = 1; i<n; i++){
        ct[i] = ct[i-1] + bt[i];
    }

    for(i=0; i<n; i++){
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\n\n");
    printf("Process\tBT\tCT\tTAT\tWT\n");
    for(i=0; i<n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n\n");
    printf("Average waiting time = %.2f\n", avg_wt/n);
    printf("Average Turnaround time = %.2f\n", avg_tat/n);

    return 0;
}
