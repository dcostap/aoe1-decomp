// 00423EE0 RGE_translate_palette (color.cpp:23-67)
// Attempt log:
// 1: Pointer implementation with s/d locals: size 448, broad diff; compiler kept pct in EBP and used different pointer basis.
// 2: d-before-s and d[-3] stores: no material improvement.
// 3: Natural indexed PALETTEENTRY loop: worse (95.3% diff), rolled back.
// 4: Pointer form with register d/s hints: no material change, still 448 bytes.
// 5: Use unsigned int color parameter: worsened padded diff to 96.2%; rolled back to struct color.
// 6: Fresh typed PALETTEENTRY array reconstruction: 476 bytes and a 0x24 frame; rolled back.
// 7: Removed unsigned channel casts in the typed pointer form; signed VC5 divisions improved resync similarity.
// 8: Separated the palette index from the three intensity values; 0x14 frame and no positional gain.
// 9: Reordered locals, counted loops, and pointer declarations; emitted code stayed unchanged.
// Left in scratch: this is the best period-plausible typed reconstruction. The original uses a 0x10 frame,
// reuses a parameter home for the byte delta, and starts the channel loop seven bytes earlier.

struct tagPALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };

void __cdecl RGE_translate_palette(tagPALETTEENTRY* src, tagPALETTEENTRY* dst, tagPALETTEENTRY color, long pct, int keep1, int keep2)
{
    unsigned char* d = &dst->peFlags;
    unsigned char* s = &src->peGreen;
    int diff = (int)dst - (int)src;
    int index = 0;
    int intense[3];

    do {
        if (index == keep1 || index == keep2) {
            d[-3] = s[-1];
            s[diff] = *s;
            d[-1] = s[1];
            d[0] = s[2];
        } else {
            tagPALETTEENTRY t = *(tagPALETTEENTRY*)(s - 1);
            intense[1] = t.peRed;
            intense[2] = *s;
            int local4 = s[1];

            for (int index1 = 2; index1 != 0; index1--) {
                int* p = &intense[2];
                for (int n = 2; n != 0; n--) {
                    int a = p[-1];
                    int b = p[0];
                    if (a < b) { p[-1] = b; p[0] = a; }
                    p++;
                }
            }

            long minv = intense[1];
            long midv = intense[2];
            long maxv = local4;
            long inten = (((maxv + midv) * (0xff - minv)) / 512) + minv;
            long v;
            v = ((color.peRed * inten) / 255 - t.peRed) * pct;
            d[-3] = (unsigned char)(t.peRed + (v / 100));
            v = ((color.peGreen * inten) / 255 - *s) * pct;
            s[diff] = (unsigned char)(*s + (v / 100));
            v = ((color.peBlue * inten) / 255 - s[1]) * pct;
            d[-1] = (unsigned char)(s[1] + (v / 100));
            d[0] = s[2];
        }
        index++;
        s += 4;
        d += 4;
    } while (index < 0x100);
}
