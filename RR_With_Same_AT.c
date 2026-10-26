//Write an algorithm for Round Robin with same arrival time.

#include<stdio.h>

int main(){
	int n, tq;
	int bt[100], rem_bt[100], ct[100], tat[100], wt[100];
	int i, time = 0, completed = 0;
	float avg_tat = 0, avg_wt = 0;
    
	printf("Enter the number of processes: ");
	scanf("%d", &n);

	printf("Enter the burst time: \n");
	for(i=0; i<n; i++){
		printf("P%d: ", i+1);
		scanf("%d", &bt[i]);

		rem_bt[i] = bt[i];
	}

	printf("Enter Time Quantum: ");
	scanf("%d", &tq);
	while(completed < n){
		for(i = 0; i<n; i++){
			if(rem_bt[i] >0){
				if(rem_bt[i]>tq){
					time += tq;
					rem_bt[i] -= tq;
				}
				else{
					time += rem_bt[i];
                    rem_bt[i] = 0;

                    ct[i] = time;
                    completed++;
				}
			}
		}
	}
	for(i = 0; i<n; i++){

    	tat[i] = ct[i];
    	wt[i]= tat[i] - bt[i];

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
