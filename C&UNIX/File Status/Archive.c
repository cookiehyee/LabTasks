#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[]) {

    struct stat StatusBuffer; //Struct containing file status
    time_t CurrentTime = time(NULL); 
    mode_t NewMode; //Permission mode to change
    int FourWeeks = (4 * 7 * 24 * 60 * 60); //Four weeks in seconds
    float ModifiedAge; //File age in terms of last modified time
    
    //Exit if command line argument does not include the file as an argument
    if(argc != 2) {
        perror("ERROR: Invalid number of arguments.");
        exit(EXIT_FAILURE);
    }

    //Retrive information about the file passed as a command line argument
    stat(argv[1],&StatusBuffer);

    //Calculate the file age in seconds
    ModifiedAge = difftime(CurrentTime,StatusBuffer.st_mtime);

    //If the last modified date of the file is more than 4 weeks
    if(ModifiedAge > FourWeeks) {
        //Calculate the new mode in bits to remove all write permissions
        NewMode = StatusBuffer.st_mode & ~(S_IWUSR | S_IWGRP | S_IWOTH);
        //Change the mode of the file to remove all write permissions
        chmod(argv[1], NewMode);
    }

    return(EXIT_SUCCESS);

}  