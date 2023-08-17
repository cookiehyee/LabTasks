#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 128 //Species name can store max 128 characters
#define INITIAL_SIZE 1 //Initial size of the array of species recorded

typedef char String[MAX_STRING];

//Enum for species type
typedef enum {
    mammal,
    insect,
    bird,
    fish,
    unidentified_species
} SpeciesType;

//Species struct 
typedef struct {
    String Name;
    float Size;
    SpeciesType Type;
} Species;

//Function prototyping
void* Malloc(size_t size);
void PrintSpecies(Species *Record, int End);
SpeciesType StringToType(char * SpeciesString);
char* TypeToString(SpeciesType Type);

int main(void) {

    Species* SpeciesRecord; //Array of species recorded 
    Species NewSpecies; //New species to be add to record
    String SpeciesName, AnimalType;  //Species name and type

    float SpeciesSize; //Size of the species
    int RecordSize = INITIAL_SIZE; //Size of the species array
    int EndofRecord = -1; //Index of last occupied element of the species array
    //EndofRecord is initialized to -1 to indicate that the array is initially empty

    //Malloc memory and size to the species array
    SpeciesRecord = (Species*)Malloc(RecordSize * sizeof(Species));

    //Prompt user to enter Species information
    printf("Enter animal information (\"exit\" to exit)\n");
    printf("What is the name : ");
    scanf("%s", SpeciesName);

    while(strcmp(SpeciesName, "exit") != 0) {

        EndofRecord++;

        //If there is no more available space in the species array
        if(EndofRecord == RecordSize) {
            //Realloc memory double the size of the array 
            RecordSize *= 2;
            SpeciesRecord = (Species*)realloc(SpeciesRecord, RecordSize * sizeof(Species));

            //Check realloc error
            if(SpeciesRecord == NULL) {
                perror("ERROR: Failed to realloc.");
                return(EXIT_FAILURE);
            }
        }

        //Assign species name
        strcpy(NewSpecies.Name,SpeciesName);

        //Prompt user to input species size
        printf("What is the size : ");
        scanf("%f", &SpeciesSize);
        NewSpecies.Size = SpeciesSize;

        //Prompt user to input species type
        printf("What is the type : ");
        scanf("%s", AnimalType);
        NewSpecies.Type = StringToType(AnimalType);

        //Add the new species struct into the array of species
        SpeciesRecord[EndofRecord] = NewSpecies;

        printf("Enter animal information (\"exit\" to exit)\n");
        printf("What is the name : ");
        scanf("%s", SpeciesName);
    
    }

    //Print array of species
    PrintSpecies(SpeciesRecord, EndofRecord);
    free(SpeciesRecord); //Free memory allocated to the array of species
    return(EXIT_SUCCESS);

}

//Wrapper function to malloc memory and check malloc error
void* Malloc(size_t size) {
    void* Memory;
    if((Memory = malloc(size)) == NULL) {
        perror("ERROR: Failed to malloc.");
        exit(EXIT_FAILURE);
    }
    return Memory;
}

//Function to print the array of species
void PrintSpecies(Species *Record, int End) {
    int Index;
    printf("\nThe following new species were found:\n");
    for(Index = 0; Index <= End; Index++) {
        printf("%-20s has size %6.2f and is a %s\n", Record[Index].Name,
            Record[Index].Size, TypeToString(Record[Index].Type));
    }
}

//Function to convert Species Type from String to enum
SpeciesType StringToType(char * SpeciesString) {
    if (!strcasecmp(SpeciesString,"mammal")) {
        return(mammal);
    }
    if (!strcasecmp(SpeciesString,"insect")) {
        return(insect);
    }
    if (!strcasecmp(SpeciesString,"bird")) {
        return(bird);
    }
    if (!strcasecmp(SpeciesString,"fish")) {
        return(fish);
    }
    return(unidentified_species);
}

//Function to convert Species Type from enum to String
char* TypeToString(SpeciesType Type) {
    switch (Type) {
        case mammal:
            return("mammal");
        case insect:
            return("insect");
        case bird:
            return("bird");
        case fish:
            return("fish");
        default:
            perror("ERROR: Unidentified species\n");
            exit(EXIT_FAILURE);
            break;
    }
}