#include<stdio.h>
int main(){
    int n, pages[100], frames[100];
    int f, i, j;
    int pf = 0, ph=0;
    int next = 0, found;
    printf("Enter no of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string:\n");
    for(i=0; i<n; i++){
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &f);

    if(n > 100 || n <= 0 || f > 100 || f <= 0){
        printf("Error! Invalid Input!");
        return 1;
    }

    for(i=0; i<f; i++){
        frames[i] = -1;
    }

    printf("\nPages\tFrames\t\tStatus\n");

    for(i=0; i<n; i++){
        found = 0;
        for(j=0; j<f; j++){
            if(frames[j] == pages[i]){
                found = 1;
                break;
            }
        }

        if(found){
            ph++;
            printf("%d\t", pages[i]);

            for(j=0; j<f; j++){
                if(frames[j] == -1){
                    printf("- ");
                }
                else{
                    printf("%d ", frames[j]);
                }
            }
            printf("\tHit\n");
        }
        else{
            frames[next] = pages[i];
            next = (next + 1) % f;
            pf++;

            printf("%d\t", pages[i]);

            for(j=0; j < f; j++){
                if(frames[j] == -1){
                    printf("- ");
                }
                else{
                    printf("%d ", frames[j]);
                }
            }
            printf("\tPage fault\n");
        }
    }
    printf("\nTotal Page Faults: %d\n", pf);
    printf("Total Page Hits: %d\n", ph);

    return 0;

}