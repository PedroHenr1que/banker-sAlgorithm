#include <stdio.h>

int getNumberOfCustomers() {
        FILE *file;
        int lines;
        file = fopen("customer.txt","r");
        char line[100];

        while ((fscanf(file, "%[^\n]", line)) != EOF) {
                getc(file);
                lines++;
        }

        return lines;
}