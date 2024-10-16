%{
    const char *cmds[] = {
        "JCN", "FIM", "SRC", NULL
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
