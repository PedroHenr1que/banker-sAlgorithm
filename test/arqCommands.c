#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
        int numberOfResources = 4;
        char command[3];
        int commandValues[numberOfResources];
        int costumer;
        FILE *file;

        file = fopen("commands.txt", "r");
        
        while (feof(file) == 0) {
                fscanf(file, "%s", command);

                if (strcmp(command, "*") != 0) {
                        fscanf(file, " %d", &costumer);
                        for (int i = 0; i < numberOfResources; i++) {
                                fscanf(file, " %d", &commandValues[i]);
                        }
                        printf("%s %d %d %d %d\n", command, costumer, commandValues[0], commandValues[1], commandValues[2]);
                } else {
                        printf("%s\n", command);
                }
                
                fgetc(file);
        }

        return 0;
}