//Write a code for algorithm Round robin with different arrival time.

#include<stdio.h>
int main(){
    int n, tq;
    int pid[100], at[100], bt[100], rem[100], ct[100], tat[100], wt[100];
    int time = 0, completed = 0;
    int i;

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        pid[i] = i+1;
        printf("\nEnter Arrival Time of P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("\nEnter Burst Time of P%d: ", i+1);
        scanf("%d", &bt[i]);

        rem[i] = bt[i];
    }
    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    while(completed < n){
        int found = 0;
        for(i=0; i<n; i++){
            if(at[i] <= time && rem[i] > 0){
                found = 1;
                if(rem[i] > tq){
                    time += tq;
                    rem[i] -= tq;
                }
                else{
                    time += rem[i];
                    rem[i] = 0;

                    ct[i] = time;
                    completed++;
                }
            }
        }

        if(found == 0){
            time++;
        }
    }

    for(i=0; i<n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    printf("\n\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i<n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], ct[i], tat[i], wt[i]);

    }

    printf("\n\n");

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("Average waiting time = %.2f\n", avg_wt/n);
    printf("Average Turnaround Time = %.2f", avg_tat/n);

    return 0;

}