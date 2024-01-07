#include <stdio.h>
#include <unistd.h> // Include for sleep() function
#include <stdlib.h>

#define RTT 5

// Function to simulate sending frames and receiving acknowledgments
void sendFramesWithACK(int window_size, int total_frames, int *frames) {
    int i;

    printf("\nAfter sending %d frames, at each stage, the sender waits for ACK window_size", total_frames);
    printf("Sending frames in the following manner...\n\n");

    for (i = 1; i <= total_frames; i++) {
        if (i % window_size != 0) {
            // Send frames that fit in the current window
            printf("\nSending Frame no %d",i);
        } else {
            // Send frames and wait for ACK after filling the window
            printf("\nSending Frame no %d", frames[i]);
            printf("\nSENDER: Waiting for ACK for Frame ...\n\n");
            sleep(RTT / 2); // Wait for RTT/2
            printf("\nRECEIVER: Frame Received, ACK Sent\n");
            sleep(RTT / 2); // Wait for RTT/2
            printf("\nSENDER: ACK received , sending next frames\n");
        }
    }

    // Send any remaining frames that didn't fit in a complete window
    if (total_frames % window_size != 0) {
        printf("\nSENDER: Waiting for ACK...\n");
        sleep(RTT / 2); // Wait for RTT/2
        printf("\nRECEIVER: Frames Received, ACK Sent\n");
        sleep(RTT / 2); // Wait for RTT/2
        printf("\nSENDER: ACK received.\n");
    }
}

int main() {
    int window_size, total_frames, frames[50],i;

    printf("Enter window size: "); // Input the window size
    scanf("%d",&window_size);

    printf("Enter number of frames to transmit: "); // Input the number of frames
    scanf("%d", &total_frames);

    printf("\nEnter %d frames: ", total_frames); // Input the frame values
    for (i = 1; i <= total_frames; i++) {
        scanf("%d", frames[i]);
    }

    // Simulate sending frames and receiving acknowledgments
    sendFramesWithACK(window_size, total_frames, frames);

    return 0;
}
