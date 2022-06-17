#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getMaximumDemandResources(int cus, int res, int maxResources[cus][res]) {

        int customer = 0;
        int resource = 0;

        char line[100];
        FILE *file;

        file = fopen("customer.txt", "r");
        char *cond;
        while (feof(file) == 0) {
                
                cond = fgets(line, 100, file);
                if (cond)
                {
                        char num[3];
                        int count = 0;
                        for (int i = 0; i < 100; i++) {

                                if (line[i] != 44 && line[i] != 10 && line[i] != '\0') {
                                        num[count] = line[i];
                                        count++;

                                } else {
                                        maxResources[customer][resource] = atoi(num);
                                        count = 0;
                                        num[0] = '\0';
                                        num[1] = '\0';
                                        num[2] = '\0';
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

int main() {
        int customers = 6, resources = 3;
        int maxResources[customers][resources];
  
        getMaximumDemandResources(customers, resources, maxResources);

        for (int i = 0; i < customers; i++) {
                printf("%d Customer\n", i);
                
                for (int j = 0; j < resources; j++) {
                        printf("%d ", maxResources[i][j]);
                }

                printf("\n");
                printf("\n");
                
        }
        
}