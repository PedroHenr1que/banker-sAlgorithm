#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIG_NUMBER 3

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

void getMaximumDemandResources(int numberOfResources, int **maxResources) {
        int customer = 0;
        FILE *file;

        file = fopen("customer.txt", "r");

        while (feof(file) == 0) {
                char num[10];
                if (numberOfResources > 1) {
                        for (int i = 0; i < numberOfResources - 1; i++) {
                                fscanf(file, "%[^,]", num);
                                fgetc(file);
                                maxResources[customer][i] = atoi(num);
                        }
                        fscanf(file, "%s", num);
                        maxResources[customer][numberOfResources-1] = atoi(num);

                } else {
                        fscanf(file, "%s", num);
                        maxResources[customer][numberOfResources-1] = atoi(num);

                }
                fgetc(file);
                customer++;
        }

        fclose(file);
}