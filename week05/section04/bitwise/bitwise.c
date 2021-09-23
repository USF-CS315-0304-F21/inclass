#include <stdio.h>
#include <stdint.h>

uint32_t get_bit_val(uint32_t n, uint32_t which) {

    /*
    this works, but could be expressed more concisely, as below
    uint32_t shifted = n >> which;
    uint32_t val = shifted & 1; //0b00000000000000000000000000000001;
    return val;
    */
    return (n >> which) & 1;
}

uint32_t get_byte_val(uint32_t n, uint32_t which)
{
    /*
    this works, but could be expressed more concisely, as below
    uint32_t shifted = n >> (8 * which);
    uint32_t masked = shifted & 0b11111111; // 0x000000ff
    return masked;
    */

    /*
    this works, and is similar to the *8 I used above
    return (n >> (which * 8)) & 0xff;
    */

    // multiply by 8 is the same as shift left by 3
    return (n >> (which << 3)) & 0xff; 

}
 
int main(int argc, char **argv) {
    uint32_t n = 0xdeadbeef;
    uint32_t which = 7;
    uint32_t val = get_bit_val(n, which);

    printf("get_bit_val(%x, %d) = %u\n", n, which, val);

    which = 2;
    val = get_byte_val(n, which);
    printf("get_byte_val(%x, %d) = %x\n", n, which, val);

    return 0;
}
