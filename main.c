#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/customer/customersHandler.h"

int *availableResources;
int **maxResourcesOfCustomers;
int **allocatedResources;
int **need;

int main(int argc, char *argv[]) {

        //setting up availableResources to each customer
        int numberOfResources = argc - 1;
        int count = 0;
        availableResources = malloc(numberOfResources * sizeof(int));
        for (int i = 0; i < numberOfResources; i++) {
                availableResources[i] = atoi(argv[i+1]);
        }
        
        //setting up the max number of resources for each consumer
        int numberOfCustomers = getNumberOfCustomers();
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
        
}