#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STRING_LENGTH 128
#define MAX_ARGS 10 //Max arguments for a command

typedef char String[STRING_LENGTH];

int main(int argc, char* argv[]) {

    FILE* InputCommand; //File input stream to read file
    String CommandFile, Command; 
    char* CommandArgs[MAX_ARGS]; //Array to store command arguments
    int ChildPID, ArgIndex, Status;

    //If command line argument does not include the file as an argument
    if(argc != 2) {
        perror("ERROR: Invalid number of arguments.");
        exit(EXIT_FAILURE);
    }

    //Assign the name of the file to read commands from
    strcpy(CommandFile,argv[1]);

    //Open file to read command
    InputCommand = fopen(CommandFile,"r");

    //Check file open error
    if(InputCommand== NULL) {
        perror("ERROR: Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    //Get each line of the file
    while(fgets(Command, sizeof(Command), InputCommand) != NULL) {

        //Remove new line from file input 
        Command[strlen(Command) - 1] = '\0';

        //Fork() to create new child process
        if((ChildPID = fork()) == -1) {
            perror("ERROR: Failed to fork().");
            exit(EXIT_FAILURE);
        }

        //If child process is created successfully
        if(ChildPID == 0) {
            ArgIndex = 0;
            //Store the command in the argument array
            CommandArgs[ArgIndex] = strtok(Command, " ");

            //While the last element of the array is not null
            while(CommandArgs[ArgIndex++] != NULL) {
                //Split and store the arguments of the command
                CommandArgs[ArgIndex] = strtok(NULL, " ");
            }
            
            //Execute command extracted from command file
            execvp(CommandArgs[0],CommandArgs);

            //Print error and exit if command failed to execute 
            perror("ERROR: Failed to execute command.");
            exit(EXIT_FAILURE);
            
        }

        else {
            //Wait for the process to complete
            ChildPID = waitpid(ChildPID, &Status, WUNTRACED);

            //If process did not end normally
            if(!WIFEXITED(Status)) {    
                perror("ERROR: Process did not end normally.");
                exit(EXIT_FAILURE);
            }
        }
    }

    //Close file input stream and check error
    if(fclose(InputCommand) == EOF) {
        perror("ERROR: Failed to close file.");
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
    
}