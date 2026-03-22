#include <stdio.h>

int main() {
    int frames, pages, i, j, k;
    int fault = 0, hit = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[50], frame[10];

    printf("Enter reference string: ");
    for(i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    int index = 0;

    for(i = 0; i < pages; i++) {
        int found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                hit++;   // ✅ HIT
                break;
            }
        }

        if(!found) {
            frame[index] = ref[i];
            index = (index + 1) % frames;
            fault++;   // ✅ FAULT
        }

        printf("\n");
        for(k = 0; k < frames; k++)
            printf("%d\t", frame[k]);
    }

    printf("\n\nTotal Page Faults = %d", fault);
    printf("\nTotal Page Hits = %d\n", hit);

    return 0;
}