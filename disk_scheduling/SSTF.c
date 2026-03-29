
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);
printf("------Enter request within the limit (0,199)------\n");

    int requests[n], visited[n];
    for(int i = 0; i < n; i++) {
        printf("Enter request %d: ", i+1);
        scanf("%d", &requests[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total_seek = 0;

    printf("Order of execution: %d ", head);

    for(int i = 0; i < n; i++) {
        int min = 9999, index = -1;

        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(head - requests[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total_seek += min;
        head = requests[index];

        printf("-> %d ", head);
    }

    printf("\nTotal seek time: %d\n", total_seek);
    return 0;
}



