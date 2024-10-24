%{
#include <stdlib.h>
#include <strings.h>
#include "assembler.h"
%}

%%

[A-Za-z_][A-Za-z0-9_]*, { printf("it's a label!"); }

[A-Za-z_][A-Za-z0-9_]*[ \t]+[0-9]+ { 
                            parse_line(yytext);
                        }

[A-Za-z_][A-Za-z0-9_]* { 
                            if(!not_command(yytext))
                                printf("it's a command - %s!", yytext);
                        }

[ \t]+ ;
%%
int main(int argc, char **argv) {
    FILE *file;
    if (argc > 1) {
        file = fopen(argv[1], "r");
        if (!file) {
            perror("failed to open file");
            return 1;
        }
    }

    yyin = file;
    yylex();

    if (argc > 1) {
        fclose(yyin);
    }
}
