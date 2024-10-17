%{

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
        printf("%s\n", input_line);
    }

    int is_command(const char *cmd) {
        printf("%s\n", cmd);
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
                            puts("this is line with argument!\n");
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
