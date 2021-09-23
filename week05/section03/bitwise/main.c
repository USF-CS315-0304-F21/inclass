#include <stdio.h>
#include <stdint.h>

uint32_t get_bit_s(uint32_t num, uint32_t which);

/* swap the second and third byte of i 
    e.g. 0x1234ABCD => 0x12AB34CD
*/
uint32_t swap_bytes_2_3(uint32_t i) {
    uint32_t mask2 = 0x0000FF00; /* 0b00000000000000001111111100000000 */
    uint32_t byte2 = (i & mask2) >> 8;

    uint32_t mask3 = 0x00FF0000;
    uint32_t byte3 = (i & mask3) >> 16;

    i &= 0xFF0000FF; /* i = 0x120000CD */
    i |= byte2 << 16;
    i |= byte3 << 8;
    return i;
}

/*
uint32_t swap_bytes_2_3(uint32_t i) {
    uint32_t mask2 = 0x0000FF00; /* 0b00000000000000001111111100000000 
    uint32_t byte2 = i & mask2;

    uint32_t mask3 = 0x00FF0000;
    uint32_t byte3 = i & mask3;

    i -= byte2;
    i -= byte3;
    i += byte2 << 8;
    i += byte3 >> 8;
        
    return i;
}
*/
uint32_t get_bit_c(uint32_t num, uint32_t which) {
    uint32_t mask = 1;
    uint32_t shifted = (num >> which) & 1;
    uint32_t masked = shifted & mask;
    return masked;
}

int main(int argc, char **argv) {
    uint32_t i = 0x1234ABCD;
    uint32_t which_bit = 3;
    
    uint32_t bit_val = get_bit_c(i, which_bit);
    printf("get_bit %u = %u\n", which_bit, bit_val);

    uint32_t bit_val_s = get_bit_s(i, which_bit);
    printf("get_bit_s %u = %u\n", which_bit, bit_val_s);

    uint32_t swapped = swap_bytes_2_3(i);
    return 0;
}
