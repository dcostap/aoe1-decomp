extern const int encrypt_table[];

void encrypt_codes(char* src, char* dst, int max_len) {
    char c = *src;
    char* out = dst;
    int count = 0;
    char* p = src + 1;

    while (c != 0 && count < max_len) {
        if (c < 'A' || c > '_') {
            *out = c;
            out++;
            count++;
        } else {
            int val = encrypt_table[(int)c];
            *out = (char)(val >> 8);
            out++;
            *out = (char)val;
            out++;
            count += 2;
        }
        c = *p;
        p++;
    }
    *out = 0;
}
