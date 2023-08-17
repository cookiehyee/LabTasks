#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Global string variable
char global_string[MAX_STRING_LENGTH];



// Producer thread function
void *producer_thread(void *arg) {
    while (1) {

        while (strlen(global_string) > 0) {
            sched_yield();
        }


        // Prompt the user for a string
        printf("Enter a string: ");


        // Read the string into the global variable until end of file
        if (fgets(global_string, MAX_STRING_LENGTH, stdin) == NULL) {
            // End the process if the user enters EOF (^D)
            exit(0);
        }

        // Notify the consumer thread that the global string is non-empty

    }
    return NULL;
}

// Consumer thread function
void *consumer_thread(void *arg) {
    while (1) {
        // Yield the CPU until the global string is non-empty
        while (strlen(global_string) == 0) {
             sched_yield();
        }

        // Print the global string to the screen
        printf("Consumer thread: %s", global_string);

        // Set the global string to empty
        global_string[0] = '\0';

        // Notify the producer thread that the global string is empty

    }
    return NULL;
}

int main() {
    // Set the common global string to empty
    global_string[0] = '\0';

    // Create and start the producer thread
    pthread_t producer;
    if (pthread_create(&producer, NULL, producer_thread, NULL) != 0) {
        fprintf(stderr, "Error creating producer thread\n");
        return 1;
    }
    pthread_detach(producer);

    // Create and start the consumer thread
    pthread_t consumer;
    if (pthread_create(&consumer, NULL, consumer_thread, NULL) != 0) {
        fprintf(stderr, "Error creating consumer thread\n");
        return 1;
    }
    pthread_detach(consumer);

    // Exit the main thread
    pthread_exit(NULL);
}
