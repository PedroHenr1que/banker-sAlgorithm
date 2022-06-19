
//functions to check errors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int lineWrong = 0;

int checkIfFileExistAndCanBeOpen(char fileName[]) {

        FILE *file;

        file = fopen(fileName, "r");

        if (file == NULL) {
                printf("############################ ERROR ############################\n");
                printf("# Could not open the file (%s) or it does not exist\n", fileName);
                printf("###############################################################\n\n");

                return -1;

        } else {
                
                return 0;
        }

        fclose(file);
}

int checkFormatCustomers(int numberOfResources) {
        
        int count = 0;
        FILE *file;

        file = fopen("customer.txt", "r");

        char line[100];
        while (feof(file) == 0) {
                
                fgets(line, 100, file);
                int validResources = 0;
                lineWrong = count;
                //checks for any incorrect caracter
                for (int i = 0; i < 100; i++) {

                        //check white line
                        if (line[i] == '\n' && i == 0) {
                                return 1;
                        }

                        //checks if there are unecessary ',', like 7,5,3,,,,
                        if (i > 0 && line[i] == ',' && !isdigit(line[i-1])) {
                                return 1;
                        }
                        
                        //check if there are diferents char than numbers and ','
                        if (line[i] != '\0' && line[i] != '\n') {
                                if (!isdigit(line[i]) && line[i] != ',') {
                                        return 1;
                                }
                        } else {
                                break;
                        }
                        
                }

                //checks if the amount of numbers is the same as the resources
                int flag = 0;
                for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {

                        if (isdigit(line[i])) {
                                if (flag == 0) {
                                        validResources ++;
                                }
                                flag++;
                        } else {
                                flag = 0;
                        }
                }
                

                if (validResources != numberOfResources) {
                        fclose(file);
                        return 2;
                }
                count++;
        }

        fclose(file);
        return 0;
        
}

int main() {
        int result = 0;

        if (checkIfFileExistAndCanBeOpen("customer.txt") == -1) {
                result = -1;
        }

        if (checkIfFileExistAndCanBeOpen("commands.txt") == -1) {
                result = -1;
        }

        int check = checkFormatCustomers(3);
        if (check != 0) {
                if (check == 2 ) {
                        printf("############################ ERROR ############################\n");
                        printf("# customer.txt\n");
                        printf("# The number of resources is differente in line %d\n", lineWrong + 1);
                        printf("###############################################################\n\n");

                } else {

                        printf("############################ ERROR ############################\n");
                        printf("# customer.txt\n");
                        printf("# Format error in line %d\n", lineWrong + 1);
                        printf("###############################################################\n\n");
                }
                result = -1;
        }
}