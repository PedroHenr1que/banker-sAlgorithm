#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/customersHandler.h"



int main(int argc, char *argv[]) {

        int numberOfResources = argc - 1;
        int count = 0;
        int availableResources[numberOfResources];
        
        for (int i = 0; i < numberOfResources; i++) {
                availableResources[i] = atoi(argv[i+1]);
        }
        
        int numberOfCustomers = getNumberOfCustomers();
        int maxResourcesOfCustomers[numberOfCustomers][numberOfResources];
        getMaximumDemandResources(numberOfCustomers, numberOfResources, maxResourcesOfCustomers);
        // for (int i = 0; i < numberOfCustomers; i++) {
        //         printf("%d Customer\n", i);
                
        //         for (int j = 0; j < numberOfResources; j++) {
        //                 printf("%d ", maxResourcesOfCustomers[i][j]);
        //         }

        //         printf("\n");
        //         printf("\n");
                
        // }
        //int allocatedResources[numberOfCustomers][numberOfResources];
}