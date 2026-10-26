//Write a code for Shortest Job first algorithm with same arrival time.

#include<stdio.h>
int main(){
    int n, i, j;
    int pid[100], ct[100], at[100], bt[100], wt[100], tat[100];
    int temp;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i<n; i++){
        pid[i] = i+1;

        printf("Enter Burst time of P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(bt[i]>bt[j]){
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    ct[0] = bt[0];
    for(i = 1; i<n; i++){
        ct[i] = ct[i-1] + bt[i];
    }

    for(i=0; i<n; i++){
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
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