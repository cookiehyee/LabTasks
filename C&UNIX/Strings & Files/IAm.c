#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 1024 //Max length of growing String

typedef char String[STRING_LENGTH]; //Type define String type

//Function prototyping
void CheckFileOpen(FILE* OpenFile);
void CheckFileClose(FILE* CloseFile);

int main(void) {

    FILE* OutputQualities; //File stream to write on a file
    FILE* InputQualities;  //File stream to read from a file 

    String Sentence; //Sentence input by the user 
    String ExtractedQuality; //Quality extracted from the input sentence
    String Qualities = ""; //All qualities input by the user
    //Initialized as an empty string 

    //Open Qualities.txt to write on
    OutputQualities = fopen("Qualities.txt", "w");
    CheckFileOpen(OutputQualities); //Check error in opening file

    //Prompt user to input qualities 
    printf("Please enter sentences, . to end.\n");
    fgets(Sentence, sizeof(Sentence), stdin);
    //Replace the new line character with the null terminator after fgets()
    Sentence[strlen(Sentence) - 1] = 0; 

    //Loop while the entry is not a period
    while(strcmp(Sentence,".") != 0) {
	
        //If the sentence starts with "I am"
        if (Sentence == strstr(Sentence,"I am")) {

            //Extract the quality from the sentence 
            strncpy(ExtractedQuality, Sentence + 5, sizeof(Sentence));

            //Print the quality to Qualities.txt
            fprintf(OutputQualities, "%s\n", ExtractedQuality);

            //Concatenate the ExtractedQuality to the growing string Qualities 
            strncat(Qualities, ExtractedQuality, strlen(ExtractedQuality));

            //Concatenate a comma after each ExtractedQuality is added to Qualities 
            strncat(Qualities, ", ", strlen(ExtractedQuality));

        }

        //Get the next sentence from the user
        fgets(Sentence, sizeof(Sentence), stdin);
        Sentence[strlen(Sentence) - 1] = 0;

    }

    //Close file stream after writing on the file and check error in closing file
    CheckFileClose(OutputQualities);

    //Remove the comma at the end of the Qualities string
    Qualities[strlen(Qualities) - 2] = '\0';
    //Print the Qualities string with a period at the end
    printf("The qualities are %s.\n", Qualities);
    
    //Open Qualities.txt to read from
    InputQualities = fopen("Qualities.txt", "r");
    CheckFileOpen(InputQualities); //Check error in opening file
    printf("\nConfirming the saved qualities ...\n");

    //Read each line of the Qualities.txt using fgets()
    while(fgets(ExtractedQuality, sizeof(ExtractedQuality), InputQualities)) {
        printf("    %s", ExtractedQuality);
    }

    //Close file stream after reading the file and check error in closing file
    CheckFileClose(InputQualities);
    delete("Qualities.txt") //Delete file 
    return(EXIT_SUCCESS);

}

//Function to check error in opening file
void CheckFileOpen(FILE* OpenFile) {
    if (OpenFile == NULL) {
        perror("ERROR: Failed to open file.");
        exit(EXIT_FAILURE);
    }
}

//Function to close file and check error in closing file
void CheckFileClose(FILE* CloseFile) {
    if (fclose(CloseFile) == EOF) { 
        perror("ERROR: Failed to close file.");
        exit(EXIT_FAILURE);
    }
}