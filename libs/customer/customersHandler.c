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

void getMaximumDemandResources(int cus, int res, int maxResources[cus][res]) {

        int customer = 0;
        int resource = 0;

        char line[100];
        FILE *file;

        file = fopen("customer.txt", "r");
        char *cond;
        while (feof(file) == 0) {
                
                cond = fgets(line, 100, file);
                if (cond) {
                        char num[MAX_DIG_NUMBER + 1];
                        int count = 0;
                        for (int i = 0; i < 100; i++) {

                                if (line[i] != 44 && line[i] != 10 && line[i] != '\0') {
                                        num[count] = line[i];
                                        count++;

                                } else {
                                        maxResources[customer][resource] = atoi(num);
                                        count = 0;
                                        for (int j = 0; j < MAX_DIG_NUMBER + 1; j++) {
                                                num[j] = '\0';
                                        }
                                        resource++;
                                }

                                if (line[i] == 10 || customer == cus - 1 && resource == res) {
                                        break;

                                } 
                                
                        }
                        customer++;
                        resource = 0;
                }
                
                
        }
        fclose(file);
        
}