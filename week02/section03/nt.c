#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint32_t char_to_digit(char ch, int base) {
	switch(base) {
		case 2:
			if (ch == '0' || ch == '1') {
				return ch - '0';
			}
			break;
		case 10:
			if (ch >= '0' && ch <= '9') {
				return ch - '0';
			}
			break;
		case 16:
			if (ch >= '0' && ch <= '9') {
				return ch - '0';
			}
			if (ch >= 'a' && ch <= 'f') {
				return ch - 'a' + 0xa;
			}
			if (ch >= 'A' && ch <= 'F') {
				return ch - 'A' + 0xa;
			}
			break;
	}
	printf("Bad input \n");
	exit(-1);
}

uint32_t string_to_int(char *str) {
	int base = 10;
	if (!strncmp(str, "0b", 2)) {
		base = 2;
		str += 2;
	} else if (!strncmp(str, "0x", 2)) {
		base = 16;
		str += 2;
	} 

	uint32_t retval = 0;
	uint32_t placeval = 1;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		char ch = str[i];
		uint32_t digit = char_to_digit(ch, base);
		retval += digit * placeval;
		placeval *= base;
	}
	return retval;
}

void int_to_string(uint32_t val, char *str, int base) {
	char temp_buf[33] = {0,};
	int quot;
	int rem;
	int idx = 0;
	char ch;
	
	while (val != 0) {
		quot = val / base;
		rem = val % base;
		if (rem < 10) {
			ch = rem + '0';
		} else if (rem < 16) {
			ch = rem + 'a' - 0xa;
		}
		val = quot;
		temp_buf[idx] = ch;
		idx++;
	}

	for (int i = 0; i < idx; i++) {
		str[i] = temp_buf[idx - 1 - i];
	}
	str[idx] = '\0';
}

int main(int argc, char **argv) {
	char *input_str = argv[1];
	int output_base = atoi(argv[3]);

	uint32_t val = string_to_int(input_str);

	char output_buf[33];
	int_to_string(val, output_buf, output_base);
	switch(output_base) {
		case 2: 
			printf("0b%s\n", output_buf);
			break;
		case 16:
			printf("0x%s\n", output_buf);
			break;
		default:
			printf("%s\n", output_buf);
	}
	return 0;
}
