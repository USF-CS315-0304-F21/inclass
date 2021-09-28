#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int add2(int a, int b);

#define NUM_REGS 16
#define PC 15

struct emu_st {
    uint32_t regs[NUM_REGS];    
};

void emu_init(struct emu_st *emu, 
    uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
    for (int i = 0; i < NUM_REGS; i++) {
        emu->regs[i] = 0;
    }

    emu->regs[0] = r0;
    emu->regs[1] = r1;
    emu->regs[2] = r2;
    emu->regs[3] = r3;
}

bool is_bx(uint32_t iw) {
    uint32_t bxcode = (iw >> 4) & 0xFFFFFFF;
    return  0xe12fff1 == bxcode;
}

void handle_bx(uint32_t iw) {
    printf("bx!\n");
}

bool is_dp(uint32_t iw) {
    uint32_t dpcode = (iw >> 26) & 0b11;
    return dpcode == 0;
}

void handle_dp(struct emu_st *emu, uint32_t iw) {
    uint32_t opcode = (iw >> 21) & 0b1111;
    uint32_t rd = (iw >> 12) & 0b1111;
    uint32_t rn = (iw >> 16) & 0b1111;
    uint32_t rm = iw & 0b1111;
    uint32_t ibit = (iw >> 25) & 0b1;
    if ((opcode == 0b0100) && (ibit == 0)) {
        // add with register mode 
        emu->regs[rd] = emu->regs[rn] + emu->regs[rm];
    }
}
int emu_run(struct emu_st *emu, uint32_t *code) {
    emu->regs[PC] = (uint32_t) code;
    while (emu->regs[PC] != 0) {
        uint32_t iw = *(uint32_t*) emu->regs[PC];
        if (is_bx(iw)) {
            handle_bx(iw);
        } 
        else if (is_dp(iw)) {
            handle_dp(emu, iw);
        }

        emu->regs[PC] += 4; // next instruction
    }
    return emu->regs[0];
}

int main(int argc, char **argv) {
    struct emu_st emu;
    emu_init(&emu, 1, 2, 3, 4);

    int r = emu_run(&emu, (uint32_t*)add2);
    printf("Emu: %d\n", r);
    return 0;
}
