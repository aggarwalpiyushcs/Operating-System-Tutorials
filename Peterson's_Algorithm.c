//Write a C Code to implement the Peterson's Algorithm.

#include<stdio.h>

int flag[2] = {0, 0};
int turn;

int main()
{
    int choice;
    printf("Peterson's Algorithm\n");
    printf("1. Process P0 enters critical section.\n");
    printf("2. Process P1 enters critical section.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        flag[0] = 1;
        turn = 1;
        printf("\nProcess P0 wants to enter Critical Section.\n");
        if(flag[1] == 0 || turn == 0){
            printf("Process P0 enters Critical Section.\n");
            printf("Process P0 executes critical section.\n");

            flag[0] = 0;
            printf("Process P0 exits Critical Section.\n");
        }
        else{
            printf("Process P0 must wait.\n");
        }
    }
    else if(choice  == 2){
        flag[1] = 1;
        turn = 0;
        printf("\nProcess P1 wants to enter Critical Section.\n");
        if(flag[0] == 0 || turn == 1){
            printf("Process P1 enters Critical Section.\n");
            printf("Process P1 executes critical section.\n");

            flag[1] = 0;
            printf("Process P1 exits Critical Section.\n");
        }
        else{
            printf("Process P1 must wait.\n");
        }
    }
    else{
        printf("Invalid Choice!\n");
    }
    return 0;
}