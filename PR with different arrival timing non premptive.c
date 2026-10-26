#include <stdio.h>

int main()
{
    int n, i, j;
    int at[20], bt[20], p[20];
    int ct[20], wt[20], tat[20];
    int completed[20] = {0};

    int time = 0, count = 0, highest, min_at;

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);


    for(i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter Priority of P%d: ", i + 1);
        scanf("%d", &p[i]);
    }


    while(count < n)
    {
        highest = -1;
        for(i = 0; i < n; i++)
        {
            if(completed[i] == 0 && at[i] <= time)
            {
                if(highest == -1 || p[i] < p[highest])
                {
                    highest = i;
                }
            }
        }

        if(highest == -1)
        {
            time++;

            continue;
        }

        time = time + bt[highest];
        ct[highest] = time;
        tat[highest] = ct[highest] - at[highest];
        wt[highest] = tat[highest] - bt[highest];
        completed[highest] = 1;
        count++;

    printf("\n\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", i + 1, at[i], bt[i], p[i], ct[i], wt[i], tat[i]);
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f", avg_tat);

    return 0;
}