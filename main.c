#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/customer/customersHandler.h"



int main(int argc, char *argv[]) {

        //setting up availableResources to each customer
        int numberOfResources = argc - 1;
        int count = 0;
        int availableResources[numberOfResources];
        for (int i = 0; i < numberOfResources; i++) {
                availableResources[i] = atoi(argv[i+1]);
        }
        
        //setting up the max number of resources for each consumer
        int numberOfCustomers = getNumberOfCustomers();
        int maxResourcesOfCustomers[numberOfCustomers][numberOfResources];
        getMaximumDemandResources(numberOfCustomers, numberOfResources, maxResourcesOfCustomers);
        
        //setting up the amount of resources allocated to each consumer (starts with 0)
        int allocatedResources[numberOfCustomers][numberOfResources];
        for (int i = 0; i < numberOfCustomers; i++) {
                for (int j = 0; j < numberOfResources; j++) {
                        allocatedResources[i][j] = 0;
                }    
        }

        //setting up the need of each customer, in the start is the same as the max demand
        int need[numberOfCustomers][numberOfResources];
        for (int i = 0; i < numberOfCustomers; i++) {
                for (int j = 0; j < numberOfResources; j++) {
                        need[i][j] = maxResourcesOfCustomers[i][j];
                }    
        }
        
}