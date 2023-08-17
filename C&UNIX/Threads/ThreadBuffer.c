#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

//Define String Type
#define STRING_LENGTH 128
typedef char String[STRING_LENGTH];

//Function prototyping
void *ThreadToProduce();
void *ThreadToConsume();

//Global String 
String GlobalString;

//Main thread
int main(void) {

    //Set the global string to empty
    GlobalString[0] = '\0';
    pthread_t ProducerThread, ConsumerThread;

    //Create Producer thread and check error
    if(pthread_create(&ProducerThread,NULL,ThreadToProduce,NULL) != 0) {
        perror("ERROR: Failed to create producer thread");
        exit(EXIT_FAILURE);
    }

    //Detach Producer thread and check error
    if(pthread_detach(ProducerThread) != 0) {
        perror("ERROR: Failed to detach producer thread");
        exit(EXIT_FAILURE);
    }

    //Create Consumer thread and check error
    if(pthread_create(&ConsumerThread,NULL,ThreadToConsume,NULL) != 0) {
        perror("ERROR: Failed to create consumer thread");
        exit(EXIT_FAILURE);
    }

    //Detach Consumer thread and check error
    if(pthread_detach(ConsumerThread) != 0) {
        perror("ERROR: Failed to detach consumer thread");
        exit(EXIT_FAILURE);
    }

    //Terminate the main thread
    pthread_exit(NULL);

}

//Function at which Producer thread begins execution
void *ThreadToProduce() {

    while(1) {
        
        //Yield the CPU until the global string is empty
        while(GlobalString[0] != '\0') {
            sched_yield(); 
        }

        //Prompt user to enter a string to assign into the global string
        printf("Enter a string: ");

        //Exit the thread to terminate the entire process if user inputs ^D (end of file)
        if (fgets(GlobalString,sizeof(GlobalString),stdin) == NULL) {
            exit(0);
        }

    }

}

//Function at which Consumer thread begins execution
void *ThreadToConsume() {

    //Infinite loop 
    while(1) {

        //Yield the CPU until the global string is non-empty
        while(GlobalString[0] == '\0') {
            sched_yield();
        }

        //Prints the global string and set it to empty
        printf("Global String: %s", GlobalString);
        GlobalString[0] = '\0';

    }

}
