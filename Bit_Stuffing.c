/*Program to Perform Bit Stuffing
Example:
INPUT : 101011111011
OUTPUT: 0111111010101111101111110
*/
#include <stdio.h>
#include <string.h>
   
int main() {
    // Input : frame 
    // Output : stuff_frame
    char frame[100], stuff_frame[400] = "\0";

    printf("Enter the Data in 1's and 0's: ");
    scanf("%s",frame);

    int i,j,count=0;
    // Add the beginFlag
    strcat(stuff_frame,"01111110");
    // Start the stuffing after the begin Flag
    j=strlen(stuff_frame);

    for(i=0;i<= strlen(frame); i++){
        if (frame[i] == '1')
            count++;
        else
            count = 0;

        if(count==5){
                stuff_frame[j++] == '0';
                stuff_frame[j++]=frame[i];
                count = 0;
        }
        
        stuff_frame[j++]=frame[i];
    }
    // Add the endFlag
    strcat(stuff_frame,"01111110");

    printf("After Bit Stuffing: %s\n", stuff_frame);

    return 0;
}
