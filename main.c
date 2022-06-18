#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/customer/customersHandler.h"

void printTable();

#define MAX_DIG_NUMBER 3

int *availableResources;
int **maxResourcesOfCustomers;
int **allocatedResources;
int **need;
int numberOfResources;
int numberOfCustomers;

int main(int argc, char *argv[]) {

        //setting up availableResources to each customer
        numberOfResources = argc - 1;
        int count = 0;
        availableResources = malloc(numberOfResources * sizeof(int));
        for (int i = 0; i < numberOfResources; i++) {
                availableResources[i] = atoi(argv[i+1]);
        }
        

        //setting up the max number of resources for each consumer
        numberOfCustomers = getNumberOfCustomers();
        maxResourcesOfCustomers = malloc(numberOfCustomers * sizeof(int *));
        for (int i = 0; i < numberOfCustomers; i++) {
                maxResourcesOfCustomers[i] = malloc(numberOfResources * sizeof(int));
        }
        getMaximumDemandResources(numberOfCustomers, numberOfResources, maxResourcesOfCustomers);
        

        //setting up the amount of resources allocated to each consumer (starts with 0)
        allocatedResources = malloc(numberOfCustomers * sizeof(int *));
        for (int i = 0; i < numberOfCustomers; i++) {
                allocatedResources[i] = malloc(numberOfResources * sizeof(int *));
        }
        for (int i = 0; i < numberOfCustomers; i++) {
                for (int j = 0; j < numberOfResources; j++) {
                        allocatedResources[i][j] = 0;
                }    
        }
        

        //setting up the need of each customer, in the start is the same as the max demand
        need = malloc(numberOfCustomers * sizeof(int *));
        for (int i = 0; i < numberOfCustomers; i++) {
                need[i] = malloc(numberOfResources * sizeof(int *));
        }
        for (int i = 0; i < numberOfCustomers; i++) {
                for (int j = 0; j < numberOfResources; j++) {
                        need[i][j] = maxResourcesOfCustomers[i][j];
                }    
        }


        //getting info from commands.txt
        char command[3];
        int commandValues[numberOfResources];
        int costumerToApplyCommand;

        FILE *commandsFile;

        commandsFile = fopen("commands.txt", "r");

        while (feof(commandsFile) == 0) {
                fscanf(commandsFile, "%s", command);

                if (strcmp(command, "*") != 0) {
                        fscanf(commandsFile, " %d", &costumerToApplyCommand);

                        for (int i = 0; i < numberOfResources; i++) {
                                fscanf(commandsFile, " %d", &commandValues[i]);
                        }
                        // printf("%s ", command);
                        // printf("%d ", costumerToApplyCommand);
                        // for (int h = 0; h < numberOfResources; h++) {
                        //         printf("%d ", commandValues[h]);
                        // }
                        // printf("\n");
                        
                } else {
                        printTable();
                
                }

                fgetc(commandsFile);
                
        }
        
        fclose(commandsFile);

        return 1;
}

void printTable() {
        int spacesMax = 1;
        if (numberOfResources > 4) {
                spacesMax = ((numberOfResources - 4) * 2) + 1;
        }

        int spacesAlloc = 1;
        if (numberOfResources > 5) {
                spacesAlloc = ((numberOfResources - 5) * 2);
        }

        printf("MAXIMUM");
        for (int i = 0; i < spacesMax; i++) {
                printf(" ");
        }
        printf("|");

        printf(" ALLOCATION");
        for (int i = 0; i < spacesAlloc; i++) {
                printf(" ");
        }
        printf("|");

        printf(" NEED\n");
        

        for (int i = 0; i < numberOfCustomers; i++) {
                //printing MAXIMUM
                for (int j = 0; j < numberOfResources; j++) {
                        printf("%d ", maxResourcesOfCustomers[i][j]);
                }

                if ((numberOfResources*2) < 8) {
                        for (int x = 0; x < (8 - (numberOfResources*2)); x++) {
                                printf(" ");
                        }
                }
                printf("|");
                
                //printing ALLOCATION
                printf(" ");
                for (int j = 0; j < numberOfResources; j++) {
                        printf("%d ", allocatedResources[i][j]);
                }

                if ((numberOfResources*2) < 11) {
                        for (int x = 0; x < (11 - (numberOfResources*2)); x++) {
                                printf(" ");
                        }
                }
                printf("|");

                //printing NEED
                printf(" ");
                for (int j = 0; j < numberOfResources; j++) {
                        printf("%d ", need[i][j]);
                }
                printf("\n");
        }
        
        printf("AVAILABLE ");
        for (int i = 0; i < numberOfResources; i++) {
                printf("%d ", availableResources[i]);
        }
        printf("\n");
        
}