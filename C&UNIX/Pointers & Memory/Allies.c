#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 128

typedef char String[STRING_LENGTH];

//Define CountryNode struct
typedef struct CountryNode {
    String Name; 
    struct CountryNode *BestAlly; //Pointer to best ally country node
    struct CountryNode *NextCountry; //Pointer to next country node
} Node;

//Function prototyping
Node* FindBestAlly(String Name, Node* Head);

int main(void) {

    String CountryName;
    Node* Head = NULL; //Initialize linked list to empty
    Node* Temp; //Temporary node to be used in linking country nodes
    Node* Country; //Pointer to a country node
    
    //Prompt user to enter first country's name
    printf("Enter nation name : ");
    fgets(CountryName, sizeof(CountryName), stdin);
    
    //Get country name until a blank entry is entered
    while(CountryName[0] != '\n') {
        
        //Allocate memory to a country node
        Country = (Node*)malloc(sizeof(Node));

        if(Country == NULL) { //If memory fails to allocate
            printf("ERROR: Failed to allocate memory.");
            return(EXIT_FAILURE);
        }

        //Remove the new line read from fgets and assign nation name
        CountryName[strlen(CountryName) - 1] = '\0';
        strcpy(Country->Name, CountryName);
        
        //If head is null, the current country node becomes the new head
        if(Head == NULL) {
            Country -> NextCountry = NULL;
            Head = Country;
        }
        
        //Elsewise, link the current country node to the linkedlist
        else {  
            Temp = Country;
            Country->NextCountry = Head;
            Head = Temp;
        }
        
        //Prompt to user to enter next country's name
        printf("Enter nation name : ");
        fgets(CountryName, sizeof(CountryName), stdin);

    }
    
    //While the list is not null, assign best ally country node to each country node
    while(Country != NULL) {
        printf("Enter best ally of %-7s : ", Country->Name);
        scanf("%s", CountryName);
         //Finds and assigns best ally in the country linkedlist 
        Country->BestAlly = FindBestAlly(CountryName, Head);

        //While the best ally input by the user does not exist in the linkedlist,
        while(Country->BestAlly == NULL) {

            //Prompt user to enter another best ally for the current country node
            printf("Enter another ally for %-7s : ", Country->Name);

            scanf("%s", CountryName);
            Country->BestAlly = FindBestAlly(CountryName, Head);
        }

        //Traverse and move on to the next country node in the linkedlist
        Country = Country->NextCountry;

    }
    
    //Reset the current country node to the head for printing each country node and its best ally
    Country = Head;
    while(Country != NULL) {  
        printf("The best ally of %s is %s\n", Country->Name, Country->BestAlly->Name);
        Country = Country->NextCountry;
    }
    
    //Reset the current country node to the head for freeing the memory of each country node
    Country = Head;
    while(Head != NULL) {
        free(Head);
        Head = Head->NextCountry;
    }
    
    return(EXIT_SUCCESS);
    
}

//Function to find the best ally in the linkedlist of country nodes
Node* FindBestAlly(String Name, Node* Head) {
    
    while(Head != NULL) {
        
        //If the name of the user input and country node's name match
        if(strcmp(Head->Name, Name) == 0) {
            return Head; //Return the country 
        }
        Head = Head->NextCountry; //Traverse to the next country node
    }
    
    //If the country does not exist, return NULL
    printf("%s does not exist in list of countries.\n", Name);
    return NULL;
    
}
