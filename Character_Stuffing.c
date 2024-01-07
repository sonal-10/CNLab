/*Program to Perform Character Stuffing
Example:
INPUT : doodle
OUTPUT: dlestxdoodledledleetx
*/
#include<stdio.h>
#include<string.h>

int main() {
    char frame[20], stuffedFrame[50] = "\0";

    // Accept the frame to be stuffed
    printf("\nEnter frame: ");
    scanf("%s", frame);
    int i = 0, j = 0;
    char beginningFlag[] = "dlestx";
    char endFlag[] = "dleetx";

    // Copy the beginning flag sequence to the stuffed frame
    strcat(stuffedFrame, beginningFlag);
    j = strlen(beginningFlag);

    // Iterate through the input frame
    for (i = 0; i < strlen(frame); i++) {
        // Check for 'dle' sequence in the input frame
        if (frame[i] == 'd' && frame[i + 1] == 'l' && frame[i + 2] == 'e') {
            // Copy 'dle' sequence and the next two characters to the stuffed frame
            stuffedFrame[j++] = 'd';
            stuffedFrame[j++] = 'l';
            stuffedFrame[j++] = 'e';
            stuffedFrame[j++] = frame[i++];
            stuffedFrame[j++] = frame[i++];
            stuffedFrame[j++] = frame[i];
        } else {
            // Copy other characters directly to the stuffed frame
            stuffedFrame[j++] = frame[i];
        }
    }

    // Terminate the stuffed frame with the ending flag sequence
    strcat(stuffedFrame, endFlag);


    // Display the result after character stuffing
    printf("\nFrame after stuffing: %s\n", stuffedFrame);

    return 0;
}
