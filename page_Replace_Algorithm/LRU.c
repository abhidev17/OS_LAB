#include <stdio.h>

int main() {
    int frames, pages, i, j, k;
    int fault = 0, hit = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[50], frame[10], time[10];

    printf("Enter reference string: ");
    for(i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    int counter = 0;

    for(i = 0; i < pages; i++) {
        int found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                hit++;                  
                counter++;
                time[j] = counter;
                break;
            }
        }

        if(!found) {
            int pos = 0;

            for(j = 1; j < frames; j++)
                if(time[j] < time[pos])
                    pos = j;

            frame[pos] = ref[i];
            counter++;
            time[pos] = counter;
            fault++;                   
        }

        printf("\n");
        for(k = 0; k < frames; k++)
            printf("%d\t", frame[k]);
    }

    printf("\n\nTotal Page Faults = %d", fault);
    printf("\nTotal Page Hits = %d\n", hit);

    return 0;
}