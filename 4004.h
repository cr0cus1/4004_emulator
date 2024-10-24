#ifndef EMULATOR_H_
#define EMULATOR_H_

typedef struct {
    int index_register[16];
    int program_counter;
    int stack[3];
    int adder;
} Cpu_4004;

int init_cpu_env();
void instruction_cycle();

#endif
