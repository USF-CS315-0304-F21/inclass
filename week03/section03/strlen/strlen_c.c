int strlen_c(char *str) {
    int len = 0;
    while (str[len] != '\0') {  // ldrb r2, [r0, r1]
        len++;
    }
    return len;
}
