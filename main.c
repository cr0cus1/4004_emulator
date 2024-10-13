#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 50

int is_label(const char *first_word) {
    if(first_word[strlen(first_word) - 2] == ',')
        return 0;
    return 1;
}

void print_func() {
    printf(" > ");
}

char *first_literal(const char *input_line) {
    char *first_word = malloc(20*sizeof(char)); // let's assume that max length of first literal can be max 20 bytes(in 4-bit assembler lmao xD)
    for(int i = 0; input_line[i] != ' '; i++)
        first_word[i] = input_line[i];
    first_word[strlen(first_word)] = '\0';

    return first_word;
}

int count_spaces(const char *input_line) {
    int space_counter = 0;

    while(*input_line != '\0') {
        if(*input_line == ' ')
            space_counter++;
        input_line++;
    }

    return space_counter;
}

void parse_line(const char *input_line) {
    char *first_word;
    first_word = first_literal(input_line);
    printf("%s\n", first_word);
    free(first_word);
}

int main(int argc, char **argv) {
    char input_line[LINE_LEN];

    printf(" > ");
    while (fgets(input_line, LINE_LEN, stdin) > 0) {
        parse_line(input_line);
        memset(input_line, 0, LINE_LEN);
        print_func();
    }
}
