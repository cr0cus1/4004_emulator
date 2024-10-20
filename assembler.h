#ifndef ASSEMBLER_H_
#define ASSEMBLER_H_

#include <stddef.h>

extern const char *cmds_names[];

typedef enum {
    JCN, FIM, SRC, FIN,
    JIN, JUN, JMS, INC, ISZ, ADD, SUB,
    LD, XCH, BBL, LDM, WRM, WMP, WRR,
    WR_phi, WR1, WR2, WR3, SBM, RDM,
    RDR, ADM, RD_phi, RD1, RD2,
    RD3, CLB, CLC, IAC, CMC, CMA,
    RAL, RAR, TCC, DAC, TCS, STC,
    DAA, KBP, DCL
} Mnemonics;

void run_cmd(int opcode);
int not_command(const char *cmd);
int return_cmd_num(const char *cmd);
void parse_line(const char *input_line);

#endif
