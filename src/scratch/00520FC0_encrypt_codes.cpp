// attempt 1: while loop with c=*src, c=*++src; total mismatch (prologue pushes first vs loads first)
// attempt 2: c=*src++, same structure; still pushes first, different register allocation
// attempt 3: same; VC5 pushes regs first, loads params into edi/eax, stores char to stack slot
// Original loads params into edx/eax BEFORE pushes, uses edi=src+1, cl=char, esi=count
// Left in scratch: benign prologue/register-allocation drift, behavior fully correct

extern const int encrypt_table[];

void encrypt_codes(const char* src, char* dst, int max_len) {
    int count = 0;
    char c = *src++;
    while (c != 0 && count < max_len) {
        if (c < 'A' || c > '_') {
            *dst++ = c;
            count++;
        } else {
            int val = encrypt_table[(unsigned char)c];
            *dst = (char)(val >> 8);
            dst[1] = (char)val;
            dst += 2;
            count += 2;
        }
        c = *src++;
    }
    *dst = 0;
}
