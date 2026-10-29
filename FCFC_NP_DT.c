//Write a code for a algorithm First come first serve with different arrival time.
#include<stdio.h>
int main(){
    int n, i, j;
    int pid[100], at[100], bt[100], ct[100], tat[100], wt[100];
    int temp;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i<n; i++){
        pid[i] = i + 1;

        printf("\nEnter the arrival time of P%d: ", pid[i]);
        scanf("%d", &at[i]);

        printf("\nEnter Burst time of P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(at[i]>at[j]){
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    int current_time = 0;

    for(i=0; i<n; i++){
        if(current_time <at[i]){
            current_time = at[i];
        }

        ct[i] = current_time + bt[i];

        tat[i] = current_time + bt[i];
        wt[i] = tat[i] - bt[i];

        current_time = ct[i];

        avg_wt += wt[i];
        avg_tat += tat[i];

    }

    printf("\n\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i<n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

    }

    printf("\n\n");

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("Average waiting time = %.2f\n", avg_wt/n);
    printf("Average Turnaround Time = %.2f", avg_tat/n);

    return 0;
}