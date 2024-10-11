#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 50

void print_func() {
    printf("\n");
    printf(" > ");
}

void split_line(const char *input_line) {
    char first_word[10];
    for(int i = 0; input_line[i] != ' '; i++)
        first_word[i] = input_line[i];
    first_word[strlen(first_word)] = '\0';
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
    int is_label = 0;
    if(strlen(input_line) == 0 && count_spaces(input_line) == 0)
        print_func();
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
