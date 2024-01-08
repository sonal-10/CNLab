#include<stdio.h>
#include<string.h>

int main() {
    char stuffed_frame[200], Destuffed_Frame[500] = "\0";

    // Accept the frame to be destuffed
    printf("\nEnter stuffed frame: ");
    scanf("%s", stuffed_frame);

    int i = 0, j = 0;
    char beginningFlag[] = "dlestx";
    char endFlag[] = "dleetx";
    int length = strlen(stuffed_frame)-strlen(endFlag);

    // Iterate through the input frame
    for (i = strlen(beginningFlag); i < length ; i++) {
        // Check for 'dle' sequence in the input frame
        if (stuffed_frame[i] == 'd' && stuffed_frame[i + 1] == 'l' && stuffed_frame[i + 2] == 'e') {
            // Delete the 'dle' sequence
            Destuffed_Frame[j++] = stuffed_frame[i++];
            Destuffed_Frame[j++] = stuffed_frame[i++];
            Destuffed_Frame[j++] = stuffed_frame[i];
            j += 3; 
        } else {
            // Copy other characters directly to the Destuffed frame
            Destuffed_Frame[j++] = stuffed_frame[i];
        }
    }

    // Display the result after Destuffing
    printf("\nFrame after stuffing: %s\n", Destuffed_Frame);

    return 0;
}