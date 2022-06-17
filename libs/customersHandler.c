#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNumberOfCustomers() {
        FILE *file;
        int lines = 0;
        file = fopen("customer.txt","r");
        char c;

        while ((fscanf(file, "%c", &c)) != EOF) {
                if (c == 10) {
                        lines++;
                }
                
        }
        fclose(file);
        return lines + 1;
}

void getMaximumDemandResources(int cus, int res, int maxResources[cus][res]) {

        int customer = 0;
        int resource = 0;

        char c;
        FILE *file;

        file = fopen("customer.txt", "r");

        while (fscanf(file, "%c", &c) != EOF) {

                       //\n               
                if (c == 10) {
                        customer++;
                        resource = 0;
                              //,  
                } else if(c == 44) {
                        resource++;

                } else {
                        maxResources[customer][resource] = atoi(&c);
                }
        }
        
}