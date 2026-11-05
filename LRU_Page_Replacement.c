#include<stdio.h>

int main(){
    int n, f, i, j, pages[100], frames[100], times[100];
    int pf, ph, counter = 0, found, least, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    if(n>100 || n<=0 || f>100 || f<=0){
        printf("Invalid Input");
        return 1;
    }

    for(i=0; i<f; i++){
        frames[i] = -1;
        times[i] = 0;
    }

    for(i=0; i<n; i++){
        found = 0;
        counter++;

        for(j=0; j<f; j++){
            if(frames[j] == pages[i]){
            found = 0;
            times[j] = counter;
            ph++;
            break;
            }
        }

        if(found = 0){
            pos = -1;
            pf++;

            for(j=0; j<f; j++){
                if(frames[j] == -1){
                    pos = j;
                    break;
                }
            }
            
            if(pos == -1){
                least = times[0];
                pos = 0;

                for(j=0; j<f; j++){
                    if(times[j] < least){
                        least = times[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            times[pos] = counter;
    }

    printf("%d\t", pages[i]);
    for(j = 0; j < f; j++){
        if(frames[j] == -1){
            printf("- ");
        }
        else{
            printf("%d", frames[j]);
        }

        if(found){
            printf("\tHit\n");
        }
        else{
            printf("\tPage Fault\n");
        }
    }

    printf("\nTotal page faults: %d\n", pf);
    printf("Total page hits: %d\n", ph);

    return 0;
    }

    
}