#include "assembler.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

const char *cmds_names[] = {
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

struct Lexema {
    char cmd[5];
    char arg1[5];
} lexema;

int not_command(const char *cmd) {
    for(int i = 0; i < 44; i++) {
        if(strcmp(cmd,cmds_names[i]) == 0)
            return 0;
    }
    return 1;
}

int return_cmd_num(const char *cmd) {
    int opcode_num;

    for(opcode_num = 0; opcode_num < 46; opcode_num++) {
        if(strcmp(cmd, cmds_names[opcode_num]) == 0)
            return opcode_num;
    }

}

void parse_line(const char *input_line) {
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

void run_cmd(int opcode) {
     switch (opcode) {
         case JCN:
            printf("it's JCN!\n");
            break;
         case FIM:
            printf("it's FIM!\n");
             break;
         case SRC:
            printf("it's SRC!\n");
             break;
         case FIN:
            printf("it's FIN!\n");
             break;
         case JIN:
            printf("it's JIN!\n");
             break;
         case JUN:
            printf("it's JUN!\n");
             break;
         case JMS:
            printf("it's JMS!\n");
             break;
         case INC:
            printf("it's INC!\n");
             break;
         case ISZ:
            printf("it's ISZ!\n");
             break;
         case ADD:
            printf("it's ADD!\n");
             break;
         case SUB:
            printf("it's SUB!\n");
             break;
         case LD:
            printf("it's LD!\n");
             break;
         case XCH:
            printf("it's XCH!\n");
             break;
         case BBL:
            printf("it's JCN!\n");
             break;
         case LDM:
            printf("it's JCN!\n");
             break;
         case WRM:
            printf("it's JCN!\n");
             break;
         case WMP:
            printf("it's JCN!\n");
             break;
         case WRR:
            printf("it's JCN!\n");
             break;
         case WR_phi:
            printf("it's JCN!\n");
             break;
         case WR1:
            printf("it's JCN!\n");
             break;
         case WR2:
            printf("it's JCN!\n");
             break;
         case WR3:
            printf("it's JCN!\n");
             break;
         case SBM:
            printf("it's JCN!\n");
             break;
         case RDM:
            printf("it's JCN!\n");
             break;
         case RDR:
            printf("it's JCN!\n");
             break;
         case ADM:
            printf("it's JCN!\n");
             break;
         case RD_phi:
            printf("it's JCN!\n");
             break;
         case RD1:
            printf("it's JCN!\n");
             break;
         case RD2:
            printf("it's JCN!\n");
             break;
         case RD3:
            printf("it's JCN!\n");
             break;
         case CLB:
            printf("it's JCN!\n");
             break;
         case CLC:
            printf("it's JCN!\n");
             break;
         case IAC:
            printf("it's JCN!\n");
             break;
         case CMC:
            printf("it's JCN!\n");
             break;
         case CMA:
            printf("it's JCN!\n");
             break;
         case RAL:
            printf("it's JCN!\n");
             break;
         case RAR:
            printf("it's JCN!\n");
             break;
         case TCC:
             break;
         case DAC:
             break;
         case TCS:
             break;
         case STC:
             break;
         case DAA:
             break;
         case KBP:
             break;
         case DCL:
             break;
     }
}
