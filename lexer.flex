%{
#include <strings.h>

    struct Lexema {
        char cmd[5];
        char arg1[5];
    } lexema;

    const char *cmds[] = {
        "JCN", "FIM", "SRC", "FIN", "JIN",
        "JUN", "JMS", "INC", "ISZ", "ADD",
        "SUB", "LD", "XCH", "BBL", "LDM",
        "WRM", "WMP", "WRR", "WR_phi", "WR1",
        "WR2", "WR3", "SBM", "RDM", "RDR",
        "ADM", "RD_phi", "RD1", "RD2", "RD3",
        "CLB", "CLC", "IAC", "CMC", "CMA",
        "RAL", "RAR", "TCC", "DAC", "TCS",
        "STC", "DAA", "KBP", "DCL", 
        NULL
    };

    void split_input_line(const char *input_line) {
        int i, k;
        for(i = 0; input_line[i] != ' '; i++)
            lexema.cmd[i] = input_line[i];

        for(k = 0; input_line[i] != '\0'; i++, k++)
            lexema.arg1[k] = input_line[i];

    }

    int is_command(const char *cmd) {
        for(int i = 0; i < 44; i++) {
            if(strcmp(cmd,cmds[i]) == 0)
                return 0;
        }
        return 1;
    }
%}

%%

[A-Za-z_][A-Za-z0-9_]*, { printf("it's a label!"); }

[A-Za-z_][A-Za-z0-9_]*[ \t]+[0-9]+ { 
                            split_input_line(yytext);
                        }

[A-Za-z_][A-Za-z0-9_]* { 
                            if(!is_command(yytext))
                                printf("it's a command - %s!", yytext);
                        }

[ \t]+ ;
%%
int main() {
    yylex();
}
