%{
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
int main() {
    yylex();
}
