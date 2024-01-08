/*Program to Perform Cyclic Redundancy Check
Example:
INPUT : 
OUTPUT: 
*/
#include <stdio.h>
#include <string.h>

// Global variables
char msg[28], cs[28], g[] = "1101";
int msglen,genlen, i, j;

// Function to perform bitwise XOR
void xor1() {
    for (j = 1; j < genlen; j++)
        cs[j] = ((cs[j] == g[j]) ? '0' : '1');
}

// Function to perform CRC (Cyclic Redundancy Check)
void crc() {
    for (i = 0; i < genlen; i++)                                                
        cs[i] = msg[i];                                                
    do {                                                              
        if (cs[0] == '1') // If the first bit is 1, perform XOR
            xor1();

        for (j = 0; j < genlen - 1; j++)
            cs[j] = cs[j + 1]; // Shifting
        cs[j] = msg[i++];     // Dropping the next bit for division
    } while (i <= msglen + genlen - 1);
}

// Function to append zeros to the message
void appendZeros() {
    for (i = msglen; i < msglen + genlen - 1; i++)
        msg[i] = '0';
}

int main() {
    int err;
    printf("\nMessage to be sent is: ");
    scanf("%s", msg);
    printf("\nGenerating polynomial: %s", g);

    msglen = strlen(msg);
    genlen = strlen(g);

    // Appending (genlen - 1) zeros to the message
    appendZeros();

    printf("\nAfter appending zeros to the message: %s", msg);

    crc();

    printf("\nChecksum is: %s", cs);

    // Appending checksum to the message
    for (i = msglen; i < msglen + genlen - 1; i++)
        msg[i] = cs[i - msglen];

    printf("\nFinal codeword (message + checksum) to be transmitted is: %s", msg);

    printf("\n\nTest error detection: No(0) Yes(1)?: ");
    scanf("%d", &err);

    if (err == 1) {
        // Inserting error for testing error detection 
        do {
            printf("\nEnter the position where error is to be inserted: ");
            scanf("%d", &err);
        } while (err == 1 || err > msglen + genlen - 1);
        msg[err - 1] = (msg[err - 1] == '0') ? '1' : '0';
        printf("\n\nErroneous data transmitted: %s\n", msg);
    }

    crc();
    printf("\nRemainder: %s", cs);

    // Checking for errors
    for (i = 0; (i < genlen - 1) && (cs[i] != '1'); i++);

    if (i < genlen - 1)
        printf("\n\nError detected\n\n");
    else
        printf("\n\nNo error detected\n\n");

    return 0;
}
