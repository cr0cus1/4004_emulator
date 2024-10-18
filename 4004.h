#ifndef EMULATOR_H_
#define EMULATOR_H_

enum mnemonics {
    JCN, FIM, SRC, FIN,
    JIN, JUN, JMS, INC, ISZ, ADD, SUB,
    LD, XCH, BBL, LDM, WRM, WMP, WRR,
    WR_phi, WR1, WR2, WR3, SBM, RDM,
    RDR, ADM, RD_phi, RD1, RD2,
    RD3, CLB, CLC, IAC, CMC, CMA,
    RAL, RAR, TCC, DAC, TCS, STC,
    DAA, KBP, DCL
};

int init_registers();
int define_opcode(const char *mnemonic);
int run_opcode(const char *opcode, const char *arg1);

#endif
