#include <stdio.h>

void writeAlloc(int customerToApplyCommand, int numberOfResources, int commandValues[]) {
        FILE *file;

        file = fopen("result.txt", "a");

        fprintf(file, "Allocated to customer %d the resources ", customerToApplyCommand);
        for (int i = 0; i < numberOfResources; i++) {
                fprintf(file, "%d ", commandValues[i]);
        }
        fputc('\n', file);

        fclose(file);
}

void writeDeniedUnSt(int customerToApplyCommand, int numberOfResources, int commandValues[]) {
        FILE *file;

        file = fopen("result.txt", "a");

        fprintf(file, "The customer %d resquest ", customerToApplyCommand);
        for (int i = 0; i < numberOfResources; i++) {
                fprintf(file, "%d ", commandValues[i]);
        }
        fputs("was denied because result in an unsafe state\n", file);

        fclose(file);
}

void writeNotEnoughRes(int customerToApplyCommand, int numberOfResources, int commandValues[], int availableResources[]) {
        FILE *file;

        file = fopen("result.txt", "a");

        fputs("The resources ", file);
        for (int i = 0; i < numberOfResources; i++) {
                fprintf(file, "%d ", availableResources[i]);
        }
        fprintf(file, "are not enough to customer %d request ", customerToApplyCommand);
        for (int i = 0; i < numberOfResources; i++) {
                fprintf(file, "%d ", commandValues[i]);
        }
        fputc('\n', file);

        fclose(file);
}

void writeExceedMaxAllocation(int customerToApplyCommand, int numberOfResources, int commandValues[]) {
        FILE *file;

        file = fopen("result.txt", "a");

        fprintf(file, "The customer %d resquest ", customerToApplyCommand);
        for (int i = 0; i < numberOfResources; i++) {
                fprintf(file, "%d ", commandValues[i]);
        }
        fputs("was denied because exceed its maximum allocation\n", file);

        fclose(file);
}

void writeRelease(int customerToApplyCommand, int numberOfResources, int commandValues[]) {
        FILE *file;

        file = fopen("result.txt", "a");

        fprintf(file, "Release from customer %d the resources ", customerToApplyCommand);
        for (int i = 0; i < numberOfResources; i++) {
                fprintf(file, "%d ", commandValues[i]);
        }
        fputc('\n', file);

        fclose(file);
}

void printTable(int numberOfResources, int numberOfCustomers, int **maxResourcesOfCustomers, int **allocatedResources, int **need, int *availableResources) {
        FILE *file;

        file = fopen("result.txt", "a");

        int spacesMax = 1;
        if (numberOfResources > 4) {
                spacesMax = ((numberOfResources - 4) * 2) + 1;
        }

        int spacesAlloc = 1;
        if (numberOfResources > 5) {
                spacesAlloc = ((numberOfResources - 5) * 2);
        }

        fputs("MAXIMUM", file);
        for (int i = 0; i < spacesMax; i++) {
                fputc(' ', file);
        }
        fputc('|', file);

        fputs(" ALLOCATION", file);
        for (int i = 0; i < spacesAlloc; i++) {
                fputc(' ', file);
        }
        fputc('|', file);

        fputs(" NEED\n", file);
        

        for (int i = 0; i < numberOfCustomers; i++) {
                //printing MAXIMUM
                for (int j = 0; j < numberOfResources; j++) {
                        fprintf(file, "%d ", maxResourcesOfCustomers[i][j]);
                }

                if ((numberOfResources*2) < 8) {
                        for (int x = 0; x < (8 - (numberOfResources*2)); x++) {
                                fputc(' ', file);
                        }
                }
                fputc('|', file);
                
                //printing ALLOCATION
                fputc(' ', file);
                for (int j = 0; j < numberOfResources; j++) {
                        fprintf(file, "%d ", allocatedResources[i][j]);
                }

                if ((numberOfResources*2) < 11) {
                        for (int x = 0; x < (11 - (numberOfResources*2)); x++) {
                                fputc(' ', file);
                        }
                }
                fputc('|', file);

                //printing NEED
                fputc(' ', file);
                for (int j = 0; j < numberOfResources; j++) {
                        fprintf(file, "%d ", need[i][j]);
                }
                fputc('\n', file);
        }
        
        fputs("AVAILABLE ", file);
        for (int i = 0; i < numberOfResources; i++) {
                fprintf(file, "%d ", availableResources[i]);
        }
        fputc('\n', file);

        fclose(file);
        
}