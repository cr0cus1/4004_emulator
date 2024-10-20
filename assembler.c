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
            break;
         case FIM:
             break;
         case SRC:
             break;
         case FIN:
             break;
         case JIN:
             break;
         case JUN:
             break;
         case JMS:
             break;
         case INC:
             break;
         case ISZ:
             break;
         case ADD:
             break;
         case SUB:
             break;
         case LD:
             break;
         case XCH:
             break;
         case BBL:
             break;
         case LDM:
             break;
         case WRM:
             break;
         case WMP:
             break;
         case WRR:
             break;
         case WR_phi:
             break;
         case WR1:
             break;
         case WR2:
             break;
         case WR3:
             break;
         case SBM:
             break;
         case RDM:
             break;
         case RDR:
             break;
         case ADM:
             break;
         case RD_phi:
             break;
         case RD1:
             break;
         case RD2:
             break;
         case RD3:
             break;
         case CLB:
             break;
         case CLC:
             break;
         case IAC:
             break;
         case CMC:
             break;
         case CMA:
             break;
         case RAL:
             break;
         case RAR:
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
