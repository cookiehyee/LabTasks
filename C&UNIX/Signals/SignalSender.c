#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//Signal Sender Program

//Function Prototyping
void HandleSIGINT(int SignalToHandle);
void HandleSIGALRM(int SignalToHandle);
void CleanZombie();

int main(void) {

    extern int ChildPID;
    extern int NumAlarms;

    //Handle SIGINT and check for error
    if(signal(SIGINT,HandleSIGINT) == SIG_ERR) {
        perror("ERROR: Failed to handle SIGXCPU.\n");
        exit(EXIT_FAILURE);
    }

    //Handle SIGALRM and check for error
    if(signal(SIGALRM,HandleSIGALRM) == SIG_ERR) {
        perror("ERROR: Failed to handle SIGXCPU.\n");
        exit(EXIT_FAILURE);
    }

    //Create a child process and check for error
    if((ChildPID = fork()) == -1) {
        perror("ERROR: Failed to create child process.\n");
        exit(EXIT_FAILURE);
    }

    //If the child process is successfully created 
    else if(ChildPID == 0) {
        //Run the SignalReceiver Program and check for error
        execlp("./SignalReceiver","SignalReceiver",NULL);
        perror("ERROR: Failed to run SignalReceiver.\n");
        exit(EXIT_FAILURE);
    }

    NumAlarms = 0; //Set the number of SIGALRMS handled to 0
    alarm(5); //Set a SIGALRM for 5 seconds later

    //Loop containing pause() until 3 SIGALRMS are handled
    while(NumAlarms < 3) {
        pause();
    }

    alarm(0); //Turn off the alarm
    kill(ChildPID,SIGKILL); //Kill the SignalReceiver program
    CleanZombie(); //Clean up the zombie
    
}

//Function to handle SIGINT signal 
void HandleSIGINT(int SignalToHandle) {

    extern int ChildPID;
 
    printf("SignalSender just got an interrupt\n");
    alarm(5); //Reset the alarm for 5 seconds later
    kill(ChildPID,SIGUSR1); //Send SIGUSR to SignalReceiver

}

//Function to handle SIGALRM signal 
void HandleSIGALRM(int SignalToHandle) {

    extern int NumAlarms;
    NumAlarms++; //Increment number of SIGALRMs handled

    printf("SignalSender just got alarm %d\n", NumAlarms);
    alarm(5); //Reset the alarm for 5 seconds later

}

//Function to clean the interface program zombie 
void CleanZombie() {

    extern int ChildPID;
    int Status;  //Status of the dead child

    //waitpid() used to clean the zombie of the child process
    ChildPID = waitpid(ChildPID,&Status,0);
    
}

//Declare external global variables
int NumAlarms; //Number of SIGALRMs handled
int ChildPID; //PID of SignalReceiver program