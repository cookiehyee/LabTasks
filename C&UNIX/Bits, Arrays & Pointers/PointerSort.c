#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARRAY_SIZE 5

typedef int* IntPointer; //Pointer to an integer
typedef int IntArray[ARRAY_SIZE]; //Array of five integers
typedef IntPointer PointerArray[ARRAY_SIZE]; //Array of five pointers

//Function prototyping
void InitializeArray(int *Num, int **Point);
void PrintIntegerArray(int *Num);
void PrintPointerArray(int **Point);
void BubbleSortIntegers(int *Num, int Size);
void BubbleSortPointers(int **Point, int Size);

int main(void) {
    
    IntArray Numbers; //Array of five integers
    PointerArray Pointers; //Array of five pointers
    
    /* Initialize an array of five integers and an array of
       five pointers to those integers */
    InitializeArray(Numbers, Pointers);
    
    printf("---- Initialized array of integers ----");
    PrintIntegerArray(Numbers); //Print the array of integers
    
    BubbleSortPointers(Pointers, 5); //Sort the array of pointers
    printf("\n---- Sorted array of pointers ----");
    PrintPointerArray(Pointers); //Print the array of pointers
    
    BubbleSortIntegers(Numbers, 5); //Sort the array of integers
    printf("\n---- Sorted array of integers ----");
    PrintIntegerArray(Numbers); //Print the array of integers
    
    printf("\n---- Array of pointers ----");
    PrintPointerArray(Pointers); //Print the array of pointers
    
    return(EXIT_SUCCESS);
    
}

//Function to initialize the array of integers and pointers
void InitializeArray(int *Num, int **Point) {
    
    int Index;
    srand(getpid()); //Use return from getpid as the seed
    
    /* Loop to assign random integers to the array of integers
       and their address to the array of pointers */
    for(Index = 0; Index < ARRAY_SIZE; Index++) {
        Num[Index] = rand(); //Assign a random integer
        //Assign the integer's memory address to the pointer
        Point[Index] = &Num[Index];
    }
 
}
                      
//Function to print the array of integers
void PrintIntegerArray(int *Num) {
    
    int Index;
    //Loop to print the index and integer stored in the array
    for(Index = 0; Index < 5; Index++) {
        printf("\n%d : %11d", Index, Num[Index]);
    }
    
}

//Function to print the array of pointers
void PrintPointerArray(int **Point) {
    
    int Index;
    
    //Loop to print the index and pointers stored in the array
    for(Index = 0; Index < 5; Index++) {
        printf("\n%d : %11d", Index, *Point[Index]);
    }
    
}

//Function to bubble sort the array of integers
void BubbleSortIntegers(int *Num, int Size) {
    
    int AccessIndex, CompareIndex, Temp;
    
    //Loop to sort the array of integers
    for(AccessIndex = 0; AccessIndex < Size - 1; AccessIndex++) {
        for(CompareIndex = 0; CompareIndex < Size - AccessIndex - 1; CompareIndex++) {
            if (*(Num + CompareIndex) > *(Num + CompareIndex + 1)) {
                //Use a temporary int variable to swap and sort the array
                Temp = *(Num + CompareIndex);
                *(Num + CompareIndex) = *(Num + CompareIndex + 1);
                *(Num + CompareIndex + 1) = Temp;
            }
        }
    }
    
}

//Function to bubble sort the array of integers
void BubbleSortPointers(int **Point, int Size) {
    
    int AccessIndex, CompareIndex, *Temp;
    
    //Loop to sort the array of pointers
    for(AccessIndex = 0; AccessIndex < Size - 1; AccessIndex++) {
        for(CompareIndex = 0; CompareIndex < Size - AccessIndex - 1; CompareIndex++) {
            if (*Point[CompareIndex] > *Point[CompareIndex + 1]) {
                //Use a temporary pointer variable to swap and sort the array
                Temp = Point[CompareIndex];
                Point[CompareIndex] = Point[CompareIndex + 1];
                Point[CompareIndex + 1] = Temp;
            }
        }
    }
    
}
