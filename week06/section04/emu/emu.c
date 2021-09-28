#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int add2(int, int);

#define NUM_REGS 16
#define PC 15

struct arm_state_st{
    uint32_t regs[NUM_REGS];
};

void arm_state_init(struct arm_state_st *state,
    uint32_t r0, uint32_t r1, uint32_t r2, uint32_t r3) {
    for (int i = 0; i < NUM_REGS; i++) {
        state->regs[i] = 0;
    }

    state->regs[0] = r0;
    state->regs[1] = r1;
    state->regs[2] = r2;
    state->regs[3] = r3;
}

bool is_bx(uint32_t iw) {
    uint32_t bxcode = (iw >> 4) & 0xFFFFFFF;
    return 0xE12FFF1 == bxcode;
}

void handle_bx(struct arm_state_st *state, uint32_t iw) {
    uint32_t rn = iw & 0b1111;
    state->regs[PC] = state->regs[rn];
}

bool is_dp(uint32_t iw) {
    uint32_t dpbits = (iw >> 26) & 0b11;
    return 0 == dpbits;
}

void handle_dp(struct arm_state_st *state, uint32_t iw) {
    uint32_t rd = (iw >> 12) & 0b1111;
    uint32_t rn = (iw >> 16) & 0b1111;
    uint32_t ibit = (iw >> 25) & 0b1;
    uint32_t opcode = (iw >> 21) & 0b1111;
    if (0 == ibit) {  // register form instruction
        uint32_t rm = iw & 0b1111;
        if (0b0100 == opcode) {  // add
            state->regs[rd] = state->regs[rn] + state->regs[rm];
        }
    }
    state->regs[PC] += 4;
}

int arm_run(struct arm_state_st *state, uint32_t *code) {
    state->regs[PC] = (uint32_t) code;
    
    while (state->regs[PC] != 0) {
        uint32_t *pc = (uint32_t*) state->regs[PC];
        uint32_t iw = *pc;
        if (is_bx(iw)) {
            handle_bx(state, iw);
        } else if (is_dp(iw)) {
            handle_dp(state, iw);
        }
    }
    printf("done\n");
    return 0;
}

int main(int argc, char **argv) {
    struct arm_state_st state;
    arm_state_init(&state, 0, 0, 5, 6);

    arm_run(&state, (uint32_t*) add2);
    return 0;        
}
