#include <stdio.h>
#include <stdlib.h>

#define ODD(X) ((X) & 01)
#define BITON(X,N) ((X) & (01 << (N-1))) //Shift bit to the left by N-1
#define ALLON(X,S,E) (((((X) & (((01 << E) - 01) ^ ((01 << (S - 01)) - 01)))) == \
(((01 << E) - 01) ^ ((01 << (S - 01)) - 01)))) //Check if bits in range S to E are on
//-----------------------------------------------------------------------------
int main(void) {

    unsigned int U1,BitNumber,Start,End;

    printf("Enter an integer : ");
    scanf("%ud",&U1);
    printf("%u is %s\n",U1,ODD(U1)?"odd":"even");

    printf("Enter an integer and a bit number : ");
    scanf("%u %d",&U1,&BitNumber);
    printf("%u has bit %d %s\n",U1,BitNumber,BITON(U1,BitNumber)?"on":"off");

    printf("Enter an integer, start and end bit numbers : ");
    scanf("%u %u %u",&U1,&Start,&End);
    printf("%u has %s those bits on\n",U1,ALLON(U1,Start,End)?"all":"not all");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
