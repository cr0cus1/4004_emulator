%{
    const char *cmds[] = {
        "JCN", "FIM", "SRC", "FIN", "JIN",
        "JUN", "JMS", "INC", "ISZ", "ADD",
        "SUB", "LD", "XCH", "BBL", "LDM",
        "SUB", "LD", "XCH", "BBL", "LDM",
        "WRM", "WMP", "WRR", "WR_phi", "WR1",
        "WR2", "WR3", "SBM", "RDM", "RDR",
        "ADM", "RD_phi", "RD1", "RD2", "RD3",
        "CLB", "CLC", "IAC", "CMC", "CMA",
        "RAL", "RAR", "TCC", "DAC", "TCS",
        "STC", "DAA", "KBP", "DCL", 
        NULL
    };

    int is_command(const char *cmd) {
        for(int i = 0; i < 3; i++) {
            if(strcmp(cmd,cmds[i]) == 0)
                return 0;
        }
        return 1;
    }
%}

%%

[A-Za-z_][A-Za-z0-9_]* { 
                            if(!is_command(yytext))
                                printf("it's a command!");
                        }


[ \t]+ ;
%%
int main() {
    yylex();
}
