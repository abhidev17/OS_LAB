#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main() {
    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);
       printf("-------Enter request within the limit (0,199)------\n ");

    int requests[n];
    for(int i = 0; i < n; i++) {
        printf("Enter request %d: ", i+1);
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    sort(requests, n);

    int total_seek = 0, i;

    for(i = 0; i < n; i++) {
        if(head < requests[i]) break;
    }

    printf("Order: %d ", head);

    // Move right
    for(int j = i; j < n; j++) {
        total_seek += abs(head - requests[j]);
        head = requests[j];
        printf("-> %d ", head);
    }

    // Move to end (199)
    total_seek += abs(head - 199);
    head = 199;
    printf("-> %d ", head);

    // Jump to start (0)
    total_seek += 199;
    head = 0;
    printf("-> %d ", head);

    // Continue servicing
    for(int j = 0; j < i; j++) {
        total_seek += abs(head - requests[j]);
        head = requests[j];
        printf("-> %d ", head);
    }

    printf("\nTotal seek time: %d\n", total_seek);
    return 0;
}
