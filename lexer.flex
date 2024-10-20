%{
#include <strings.h>
#include "assembler.h"

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

    void run_cmd(int opcode) {
        switch (opcode) {
            case JCN:
                printf("here will be func for JCN \n");
                break;
            case FIM:
                printf("here will be func for FIM \n");
                break;
        }
    }

    int not_command(const char *cmd) {
        for(int i = 0; i < 44; i++) {
            if(strcmp(cmd,cmds[i]) == 0)
                return 0;
        }
        return 1;
    }

    int return_cmd_num(const char *cmd) {
        int opcode_num;

        for(opcode_num = 0; opcode_num < 46; opcode_num++) {
            if(strcmp(cmd, cmds[opcode_num]) == 0)
                return opcode_num;
        }

    }

    void split_input_line(const char *input_line) {
        int i, k;

        memset(lexema.cmd, 0, 5);
        for(i = 0; input_line[i] != ' '; i++)
            lexema.cmd[i] = input_line[i];

        for(k = 0; input_line[i] != '\0'; i++, k++)
            lexema.arg1[k] = input_line[i];

        if(not_command(lexema.cmd))
            printf("ERROR!\n");
        else {
            int opcode_num = return_cmd_num(lexema.cmd);
            run_cmd(opcode_num);
        }

    }
%}

%%

[A-Za-z_][A-Za-z0-9_]*, { printf("it's a label!"); }

[A-Za-z_][A-Za-z0-9_]*[ \t]+[0-9]+ { 
                            split_input_line(yytext);
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
