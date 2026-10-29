//Write a C/C++ Code to implement Banker's algorithm.
#include<stdio.h>
int main(){
    int n, m;
    int allocation[10][10], max[10][10];
    int need[10][10], available[10];
    int finish[10] = {0}, SafeSequence[10];
    int i, j, k, count=0, found;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    if(n <=0 || n > 10 || m <=0 || m >10){
        printf("Invalid Input! Maximum 10 Processes and resources allowed.\n");
        return 1;
    }

    printf("\nEnter Allocation Matrix:\n");
    for(i=0; i<n; i++){
        printf("Process P%d: ", i);
        for(j=0; j<m; j++){
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");
    for(i=0; i<n; i++){
        printf("Process P%d: ", i);
        for(j=0; j<m; j++){
            scanf("%d", &max[i][j]);
        }
    }


    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(max[i][j]<allocation[i][j]){
                printf("Invalid Input: Allocation exceeds maximum claim.\n");
                return 1;
            }

            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nEnter Available Resources: ");
    for(j=0; j<m; j++){
        scanf("%d", &available[j]);
    }

    printf("\nNeed Matrix: \n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d", need[i][j]);
        printf("\n");
        }
    }

    while(count<n){
        found=0;
        for(i=0; i<n; i++){
            if(finish[i] == 0){
                for(j=0; j<m; j++){
                    if(need[i][j] > available[j])
                        break;
                }

            if(j == m){
                for(k=0; k<m; k++)
                    available[k] +=allocation[i][k];
                SafeSequence[count++] = i;
                finish[i] = i;
                found = 1;
                }
            }
        }
        if(found == 0)
            break;
    }


    if(count == n){
        printf("\nSystem is in a SAFE state.\n");
        printf("Safe Sequence: ");

        for(i=0; i<n; i++){
            printf("P%d", SafeSequence[i]);

            if(i<n-1)
                printf("->");
        }
        printf("\n");
    }

    else{
        printf("\nSystem is i an UNSAFE state.\n");
        printf("No Safe Sequence exists for the given state.\n");
    }

    return 0;
}
