#include <stdio.h>
#include <string.h>

int main() {
    // Input : stuff_frame 
    // Output : destuff_frame
    char stuff_frame[500], destuff_frame[200] = "\0";

    printf("Enter the received data: ");
    scanf("%s", stuff_frame);

    int i,j=0,count=0;
    char flag[] = "01111110";
    int length = strlen(stuff_frame)-strlen(flag);

    for(i=strlen(flag); i<length ;i++){
        if (stuff_frame[i] == '1')
            count++;
        else
            count = 0;
        if(count==5){
            destuff_frame[j++] = stuff_frame[i];
            count = 0;
            j++; 
            continue;
        }
        destuff_frame[j++] = stuff_frame[i];
        
    }

    // Display the result after bit destuffing
    printf("After Bit Destuffing: %s\n", destuff_frame);

    return 0;
}
