// 00423EE0 RGE_translate_palette (color.cpp:23-67)
// Attempt log:
// 1: Pointer implementation with s/d locals: size 448, broad diff; compiler kept pct in EBP and used different pointer basis.
// 2: d-before-s and d[-3] stores: no material improvement.
// 3: Natural indexed PALETTEENTRY loop: worse (95.3% diff), rolled back.
// 4: Pointer form with register d/s hints: no material change, still 448 bytes.
// 5: Use unsigned int color parameter: worsened padded diff to 96.2%; rolled back to struct color.
// Left in scratch: best explored source is still 448 bytes and broad register/pointer-basis mismatch. Original keeps EBP=dst+3, EDI=src+1, reloads pct from stack, and uses VC5 signed magic divisions; rebuilt keeps pct/pointers in different callee-saved registers. Needs focused variant lab on pointer topology/local order/arithmetic surface.

struct tagPALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };

void __cdecl RGE_translate_palette(tagPALETTEENTRY* src, tagPALETTEENTRY* dst, tagPALETTEENTRY color, long pct, int keep1, int keep2)
{
    long index1;
    long intense[3];
    register unsigned char* d = &dst->peFlags;
    register unsigned char* s = &src->peGreen;
    int diff = (int)dst - (int)src;
    intense[0] = 0;

    do {
        if (intense[0] == keep1 || intense[0] == keep2) {
            d[-3] = s[-1];
            s[diff] = *s;
            d[-1] = s[1];
            d[0] = s[2];
        } else {
            tagPALETTEENTRY t = *(tagPALETTEENTRY*)(s - 1);
            intense[1] = (unsigned int)t.peRed;
            intense[2] = (unsigned int)*s;
            long local4 = (unsigned int)s[1];

            index1 = 2;
            do {
                long* p = &intense[2];
                int n = 2;
                do {
                    long a = p[-1];
                    long b = p[0];
                    if (a < b) { p[-1] = b; p[0] = a; }
                    p++;
                    n--;
                } while (n != 0);
                index1--;
            } while (index1 != 0);

            long minv = intense[1];
            long midv = intense[2];
            long maxv = local4;
            long inten = (((maxv + midv) * (0xff - minv)) / 512) + minv;
            long v;
            v = ((((unsigned int)color.peRed * inten) / 255) - (unsigned int)t.peRed) * pct;
            d[-3] = (unsigned char)(t.peRed + (v / 100));
            v = ((((unsigned int)color.peGreen * inten) / 255) - (unsigned int)*s) * pct;
            s[diff] = (unsigned char)(*s + (v / 100));
            v = ((((unsigned int)color.peBlue * inten) / 255) - (unsigned int)s[1]) * pct;
            d[-1] = (unsigned char)(s[1] + (v / 100));
            d[0] = s[2];
        }
        intense[0]++;
        s += 4;
        d += 4;
    } while (intense[0] < 0x100);
}
