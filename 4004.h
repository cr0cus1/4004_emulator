#ifndef EMULATOR_H_
#define EMULATOR_H_

int init_registers();
int run_opcode(const char *opcode, const char *arg1);

#endif
