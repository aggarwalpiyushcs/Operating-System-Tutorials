//Write a code for an algorithm shortest job first with different arrival time
#include<stdio.h>
int main(){
    int n, i, j;
    int pid[100], at[100], bt[100], ct[100], tat[100], wt[100];
    int completed[100] = {0};
    int current_time = 0, completed_count = 0;
    int shortest;

    float avg_tat = 0, avg_wt = 0;

    printf("Enter the number of procceses: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        pid[i] = i+1;

        printf("\nEnter Arrival Time pf P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    while(completed_count<n){
        shortest = -1;

        for(i = 0; i<n; i++){
            if(completed[i] == 0 && at[i] <= current_time){
                if((shortest == -1) || bt[i] < bt[shortest]){
                    shortest = i;
                }
            }
        }

        if(shortest == -1){
            current_time++;
        }
        else{
            ct[shortest] = current_time + bt[shortest];
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            current_time = ct[shortest];

            completed[shortest] = 1;
            completed_count++;
            avg_wt += wt[shortest];
            avg_tat += tat[shortest];
        }
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
