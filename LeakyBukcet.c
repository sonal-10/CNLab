#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define bucketSize 1000
#define packets 5

// Function to simulate data output from the bucket
void bucketOutput(int *bucket, int op) {
    if (*bucket > 0 && *bucket > op) {
        *bucket = *bucket - op;
        printf("\n%d Output, Remaining is %d\n", op, *bucket);
    }
}

// Function to simulate the arrival and processing of packets
void processPackets(int outputRate) {
    int i, j, new, old = 0, bucket = 0;

    for (i = 1; i <= packets; i++) {
        new = rand() % 500; // Random Packet from 0 to 499
        printf("\nNew Packet Size = %d\n", new);
        new += old;

        // Check if the total packet size is within the bucket's capacity
        if (new < bucketSize) {
            bucket = new;
        } else {
            printf("\n%d (new + old) is greater than Bucket Size. Rejecting packet\n", new);
            bucket = old;
        }

        printf("\n The data in the Bucket = %d\n", bucket); // Current Data in the Bucket
        printf("\n The Next packet will arrive in %ds\n", rand() % 5); // Wait time for next packet

        // Simulate waiting for the arrival of the Next Packet
        for (j = 0; j < rand() % 5; j++) {
            bucketOutput(&bucket, outputRate); // Output the data
            sleep(1);                            // 1 second wait time
        }
        old = bucket;
    }

    // Continue The data output until the Bucket is Empty
    while (bucket > 0) {
        bucketOutput(&bucket, outputRate);
    }
}

int main() {
    int outputRate;
    printf("Enter the output Rate:");
    scanf("%d", &outputRate);

    // Process packets and simulate bucket operation
    processPackets(outputRate);

    return 0;
}
