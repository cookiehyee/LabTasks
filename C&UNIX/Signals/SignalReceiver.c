#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//Signal Receiver Program

//Function to handle SIGXPU signal 
void HandleSIGUSR1(int SignalToHandle) {
    printf("SignalReceiver just got an SIGUSR1\n");
}

int main(void) {

    //Ignore SIGINT signals and check for error
    if(signal(SIGINT, SIG_IGN) == SIG_ERR) {
        perror("ERROR: Failed to ignore SIGINT.\n");
        exit(EXIT_FAILURE);
    }

    //Handle SIGUSR1 and check for error
    if(signal(SIGUSR1,HandleSIGUSR1) == SIG_ERR) {
        perror("ERROR: Failed to handle SIGXCPU.\n");
        exit(EXIT_FAILURE);
    }

    //Infinite loop containing pause()
    while(1) {
        pause();
    }

}