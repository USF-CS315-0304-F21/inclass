#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
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
	}
	printf("Bad input\n");
	exit(-1);	
}

uint32_t string_to_int(char *str) {
	int input_base = 10;
	if (!strncmp(str, "0b", 2)) {
		input_base = 2;
		str += 2;
	} else {
		if (!strncmp(str, "0x", 2)) {
			input_base = 16;
			str += 2;
		}
	}

	uint32_t retval = 0;
	uint32_t placeval = 1;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		char ch = str[i];
		uint32_t digit = char_to_digit(ch, input_base);
		retval += placeval * digit;
		placeval *= input_base;
	}
	return retval;
}

void int_to_string(uint32_t val, char *str, int base) {
	char temp_buf[33] = {0};
	uint32_t quot;
	uint32_t rem;
	char ch;
	int idx = 0;
	
	while (val != 0) {
		quot = val / base;
		rem = val % base;
		if (rem < 10) {
			ch = rem + '0';
		} else if (rem < 16) {
			ch = rem + 'a' - 0xa;
		}
		temp_buf[idx] = ch;
		val = quot;
		idx++;
	}

	int j = 0;
	for (int i = strlen(temp_buf) - 1; i >= 0; i--) {
		str[j] = temp_buf[i];
		j++;
	}
	str[j] = '\0';
}

int main(int argc, char **argv) {
	char *input_str = argv[1];
	int output_base = atoi(argv[3]);

	uint32_t value = string_to_int(input_str);

	char output_buf[33];
	int_to_string(value, output_buf, output_base);
	switch(output_base) {
		case 2:
			printf("0b%s\n", output_buf);
			break;
		case 16:
			printf("0x%s\n", output_buf);
			break;
		case 10:
			printf("%s\n", output_buf);
			break;
	}
	return 0;
}
