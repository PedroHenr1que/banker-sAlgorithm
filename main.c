#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/customer/customersHandler.h"
#include "libs/archiveHandler/archiveHandler.h"
#include "libs/errorHandler/errorHandler.h"

int resquestResources(int customerN, int request[]);
int verifiArray(int *array1, int array2[], int interations);

#define TRUE 1
#define FALSE 0

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
        
        //check if the files exists and their format
        if (check(numberOfResources) == -1) {
                exit(1);
        }

        //get number of customers
        numberOfCustomers = getNumberOfCustomers();

        //check if the customers in commands are valid
        if (checkCustomersInCommands(numberOfCustomers) == -1) {
                exit(1);
        }

        //setting up the max number of resources for each consumer
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
        int customerToApplyCommand;

        FILE *commandsFile;

        commandsFile = fopen("commands.txt", "r");

        while (feof(commandsFile) == 0) {
                fscanf(commandsFile, "%s", command);
                
                if (strcmp(command, "*") != 0) {
                        fscanf(commandsFile, " %d", &customerToApplyCommand);

                        for (int i = 0; i < numberOfResources; i++) {
                                fscanf(commandsFile, " %d", &commandValues[i]);
                        }

                        if (strcmp(command, "RQ") == 0) {
                                
                                if (verifiArray(commandValues, need[customerToApplyCommand], numberOfResources)) {

                                        if (verifiArray(commandValues, availableResources, numberOfResources)) {
                                                if (resquestResources(customerToApplyCommand, commandValues) == 1) {
                                                        writeAlloc(customerToApplyCommand, numberOfResources, commandValues);

                                                } else {
                                                        writeDeniedUnSt(customerToApplyCommand, numberOfResources, commandValues);
                                                }

                                        } else {
                                                writeNotEnoughRes(customerToApplyCommand, numberOfResources, commandValues, availableResources);
                                        }


                                } else {
                                        writeExceedMaxAllocation(customerToApplyCommand, numberOfResources, commandValues);
                                }

                        } else {
                                for (int i = 0; i < numberOfResources; i++) {
                                        allocatedResources[customerToApplyCommand][i] = allocatedResources[customerToApplyCommand][i] - commandValues[i];
                                        need[customerToApplyCommand][i] = need[customerToApplyCommand][i] + commandValues[i];
                                        availableResources[i] = availableResources[i] + commandValues[i];
                                }
                                writeRelease(customerToApplyCommand, numberOfResources, commandValues);
                                
                        }
                        
                        
                } else {
                        printTable(numberOfResources, numberOfCustomers, maxResourcesOfCustomers, allocatedResources, need, availableResources);
                
                }

                fgetc(commandsFile);
                
        }
        
        fclose(commandsFile);
        printf("Successfully completed\n");
        return 1;
}

int resquestResources(int customerN, int request[]) {
        for (int i = 0; i < numberOfResources; i++) {
                availableResources[i] = availableResources[i] - request[i];
                allocatedResources[customerN][i] = allocatedResources[customerN][i] + request[i];
                need[customerN][i] = need[customerN][i] - request[i];
        }

        //Safety Algorithm
        int a = numberOfResources;
        int work[a];
        for (int j = 0; j < numberOfResources; j++) {
                work[j] = availableResources[j];
        }
        
        int finish[numberOfCustomers];
        for (int i = 0; i < numberOfCustomers; i++) {
                finish[i] = FALSE;
        }
        

        for (int i = 0; i < numberOfCustomers; i++) {
                
                for (int j = 0; j < numberOfCustomers; j++) {

                        if (finish[j] == FALSE && verifiArray(need[j], work, numberOfResources)) {

                                for (int k = 0; k < numberOfResources; k++) {
                                        work[k] = work[k] + allocatedResources[j][k];
                                }
                                finish[j] = TRUE;
                        }

                }
        }

        for (int i = 0; i < numberOfCustomers; i++) {
                if (finish[i] == FALSE) {
                        for (int j = 0; j < numberOfResources; j++) {
                                availableResources[j] = availableResources[j] + request[j];
                                allocatedResources[customerN][j] = allocatedResources[customerN][j] - request[j];
                                need[j] = need[j] + request[j]; 
                        }
                        return -1;
                }
        }
        
        return 1;
}

int verifiArray(int array1[], int array2[], int interations) {
        int isValid = 1;
        for (int i = 0; i < interations; i++) {
                if (!(array1[i] <= array2[i])) {
                        isValid = 0;
                        break;
                }
        }

        return isValid;
}