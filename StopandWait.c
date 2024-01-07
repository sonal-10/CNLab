#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TIMEOUT 4
#define TOT_FRAMES 7
#define RTT 4

// Enumeration for acknowledgment state
enum { NO, YES } ACK;

// Function to simulate sending frames and receiving acknowledgments
void sendFrames() {
    int wait_time, i = 1;
    ACK = YES; // Initialize acknowledgment state to YES (positive)

    for (; i <= TOT_FRAMES;) {
        if (ACK == YES && i != 1) {
            printf("\nSENDER: ACK for frame %d Received.\n", i - 1);
        }

        printf("\nSENDER: Frame %d sent, waiting for ACK...\n", i);
        ACK = NO;
        wait_time = rand() % 5 ;

        if (wait_time == TIMEOUT) {
            printf("SENDER: ACK not received for Frame %d => TIMEOUT Resending Frame...\n", i);
        } else {
            sleep(RTT);
            printf("\nRECEIVER: Frame %d received, ACK sent\n", i);
            printf("...............................................");
            ACK = YES;
            i++;
        }
    }
}

int main() {
    // Simulate sending frames and receiving acknowledgments
    sendFrames();

    return 0;
}
