#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 20

int main(int argc, char **argv) {
    char input_line[LINE_LEN];

    printf(" > ");
    while (fgets(input_line, LINE_LEN, stdin) > 0) {
        printf("\n");
        printf(" > ");
    }
}
