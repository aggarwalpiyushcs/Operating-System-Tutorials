//Write a C/C++ Code to implement FIRST fit algorithm.

#include<stdio.h>
int main(){
    int blocks[100], processes[100], allocation[100];
    int m, n, i ,j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each memory blocks:\n");
    for(i=0; i<m; i++){
        printf("Block %d: ", i+1);
        scanf("%d", &blocks[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("Enter size of each processes:\n");
    for(i=0; i<n; i++){
        printf("Process %d: ", i+1);
        scanf("%d", &processes[i]);
        allocation[i] = -1;
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++){
            if(blocks[j]>=processes[i]){
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock Allocation\n");
    for(i=0; i<n; i++){
        printf("%d\t\t%d\t\t", i+1, processes[i]);

        if(allocation[i] != -1){
            printf("%d\n", allocation[i]+1);
        }
        else{
            printf("Not Allocated\n");
        }
    }

    printf("\nRemaining Memory in Each Block:\n");
    for(i=0; i<m; i++){
        printf("Block %d: %d\n", i+1, blocks[i]);
    }

    return 0;

}
