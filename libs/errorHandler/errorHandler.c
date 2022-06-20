
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
                for (int i = 0; i < 100; i++) {
                        line[i] = '\0';
                }
                fgets(line, 100, file);
                int validResources = 0;
                lineWrong = count;
                //checks for any incorrect caracter
                for (int i = 0; i < 100; i++) {

                        //check white line
                        if (line[i] == '\n' && i == 0 || line[i] == '\0' && i == 0) {
                                fclose(file);
                                return 1;
                        }
                        
                        //check if there are different chars than the allowed ones
                        if (line[i] != '\0' && line[i] != '\n') {
                                if(line[i] == ',' && !isdigit(line[i+1]) && i < 99 
                                || i == 0 && line[i] == ',' || !isdigit(line[i]) && line[i] != ',') {
                                        fclose(file);
                                        return 2;
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
                        return 3;
                }
                count++;
        }

        fclose(file);
        return 0;
        
}

int checkFormatCommands(int numberOfResources) {
        int count = 0;
        FILE *file;

        file = fopen("commands.txt", "r");
        char line[100];
        while (feof(file) == 0) {
                for (int i = 0; i < 100; i++) {
                        line[i] = '\0';
                }
                fgets(line, 100, file);
                lineWrong = count;
                int validResources = 0;

                if (line[0] != '\n' && line[0] != '\0') {
                        char command[3];
                        for (int i = 0; i < 3; i++) {
                                command[i] = '\0';
                        }
                        
                        command[0] = line[0];
                        command[1] = line[1];

                        if (strcmp(command, "RQ") == 0 || strcmp(command, "RL") == 0) {
                                for (int i = 2; i < 100; i++) {

                                        //check diferetents char than the allowed ones
                                        if (line[i] != '\0' && line[i] != '\n') {
                                                if (line[i] != ' ' && !isdigit(line[i]) || line[i] == ' ' && !isdigit(line[i+1]) ) {
                                                        return 2;
                                                }
                                                
                                        } else {
                                                break;
                                        }
                                        
                                }
                                
                                //checks if the amount of numbers is the same as the resources
                                int flag = 0;
                                for (int i = 5; line[i] != '\0' && line[i] != '\n'; i++) {

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
                                        return 3;
                                }
                                
                                
                        } else if (command[0] == '*') {
                                if(line[1] != '\0' && line[1] != '\n') {
                                        return 2;
                                }

                        } else {
                                //when there is an unidentified command
                                return 4;
                        }
                        

                } else {
                        //white line or blank line
                        return 1;
                }
                count++;
        }
        return 0;
}

int checkCustomersInCommands(int numberOfCustomers) {

        int count = 0;
        FILE *file;

        file = fopen("commands.txt", "r");
        char line[100];

        while (feof(file) == 0) {
                for (int i = 0; i < 100; i++) {
                        line[i] = '\0';
                }
                fgets(line, 100, file);

                char num[4];
                for (int i = 0; i < 4; i++) {
                        num[i] = '\0';
                }
                
                for (int i = 0; i < 3; i++) {
                        if (!isdigit(line[i+3])) {
                                break;
                        }
                        num[i] = line[i+3];
                }

                int numDec = atoi(num);

                if (numDec > numberOfCustomers || numDec < 0) {
                        printf("############################ ERROR ############################\n");
                        printf("# commands.txt\n");
                        printf("# Error in line %d\n", count + 1);
                        printf("# The customer number is bigger than the allowed\n");
                        printf("# The biggest customer is %d\n", 5);
                        printf("###############################################################\n\n");
                        return -1;
                }

                count++;
        }
        return 0;
}

int check(int numberOfResources) {
        int result = 0;
        int check = 0;
        if (checkIfFileExistAndCanBeOpen("customer.txt") == -1) {
                result = -1;

        } else {
                check = checkFormatCustomers(numberOfResources);
                if (check != 0) {
                        if (check == 1) {
                                printf("############################ ERROR ############################\n");
                                printf("# customer.txt\n");
                                printf("# There is a white line in line %d\n", lineWrong + 1);
                                printf("###############################################################\n\n");

                        } else if (check == 2 ) {
                                printf("############################ ERROR ############################\n");
                                printf("# customer.txt\n");
                                printf("# Format error in line %d\n", lineWrong + 1);
                                printf("# The format must be -> (r1,r2,r3,r4,...,rn)\n");
                                printf("###############################################################\n\n");

                        } else {
                                printf("############################ ERROR ############################\n");
                                printf("# customer.txt\n");
                                printf("# The number of resources is differente in line %d\n", lineWrong + 1);
                                printf("###############################################################\n\n");
                                
                        }
                        result = -1;
                }
        }

        if (checkIfFileExistAndCanBeOpen("commands.txt") == -1) {
                result = -1;

        } else {
                check = checkFormatCommands(numberOfResources);
                if (check != 0) {
                        if (check == 1) {
                                printf("############################ ERROR ############################\n");
                                printf("# commands.txt\n");
                                printf("# The archive is empty or it has a blank line in line %d\n", lineWrong + 1);
                                printf("###############################################################\n\n");

                        } else if (check == 2 ) {
                                printf("############################ ERROR ############################\n");
                                printf("# commands.txt\n");
                                printf("# Format error in line %d\n", lineWrong + 1);
                                printf("# The format must be -> (RQ C r1 r2 r3 r4 ... rn)\n");
                                printf("# or\n");
                                printf("# The format must be -> (RL C r1 r2 r3 r4 ... rn)\n");
                                printf("# or\n");
                                printf("# The format must be -> (*)\n");
                                printf("###############################################################\n\n");

                        } else if(check == 3) {
                                printf("############################ ERROR ############################\n");
                                printf("# commands.txt\n");
                                printf("# The number of resources is differente in line %d\n", lineWrong + 1);
                                printf("###############################################################\n\n");

                        } else {
                                printf("############################ ERROR ############################\n");
                                printf("# commands.txt\n");
                                printf("# Unidentified command in line %d\n", lineWrong + 1);
                                printf("###############################################################\n\n");

                        }
                        result = -1;
                }
        }

        return result;
}