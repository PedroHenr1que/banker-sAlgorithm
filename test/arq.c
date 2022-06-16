#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main() {
        char c;
        FILE *file;

        file = fopen("customer.txt", "r");

        while (fscanf(file, "%c", &c) != EOF) {

                if (strcmp(&c, "\n") == 0) {
                        printf("quebra de linha\n");

                } else if(strcmp(&c, ",") == 0) {
                        printf("virgula\n");

                } else {
                        printf("%c\n", c);
                }
        }
        
        return 0;
}