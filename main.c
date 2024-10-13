#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 50

//void is_label(const char *first_word) {
//    printf("%c\n", first_word[strlen(first_word)-2]);
//    if(first_word[strlen(first_word) - 1] == ',')
//        return 0;
//    return 1;
//}

void print_func() {
    printf(" > ");
}

void split_input_line(const char *input_line) {
    char *first_word = malloc(20*sizeof(char)); // let's assume that max length of first literal can be max 20 bytes(in 4-bit assembler lmao xD)
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
    char *first_literal= malloc(20*sizeof(char)); // let's assume that max length of first literal can be max 20 bytes(in 4-bit assembler lmao xD)

    printf("%s\n", first_literal);
    free(first_literal);
    first_literal = NULL;
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
