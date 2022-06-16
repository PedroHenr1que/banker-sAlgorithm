#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/customersHandler.h"



int main(int argc, char *argv[]) {

        int amountOfResources = argc - 1;
        int count = 0;
        int availableResources[amountOfResources];
        for (int i = 1; i < amountOfResources; i++) {
                availableResources[count] = atoi(argv[i]);
                count ++;
        }
        
        int numberOfCustomers = getNumberOfCustomers();
        int maxResources[numberOfCustomers][amountOfResources];
        int allocatedResources[numberOfCustomers][amountOfResources];
}