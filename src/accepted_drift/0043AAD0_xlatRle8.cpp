// 0043AAD0 xlatRle8
// Source: Dib.cpp lines 1720-1763
// Size: 101 bytes, 44 asm lines
// ACCEPTED_DRIFT: manually reviewed localized 3-byte drift only. One SIB byte
// encodes the same `[esi+edx]` address as `[edx+esi]`; the encoded-run path uses
// CL instead of DL for the translated byte and stores through `[eax-1]` equivalently.

// attempt 1: in-place RLE8 translator with the count/value state machine and byte-table translation
// attempt 2: tried decompiler-shaped locals and a volatile spill to reach the 101-byte basin, but the register layout drifted badly
// 2026-05-09 GraniteCub: tried 20 focused variants around signature and source shape:
// 2-arg vs 3-arg surface, explicit p=data local, parameter-stack-slot reuse,
// code==0 arm order, switch vs if-chain vs manual sub/dec selector, value/count
// widths, pre/post-increment encodings, xlat expression order/casts/const/signed,
// pointer temps, and narrow flag probes. Best source below is very close: local
// check is 3 positional bytes / 3 edit bytes. It matches the prologue, stack-slot
// reuse (`mov [esp+0Ch],bl`), zero-code switch (`sub edx,0; dec; dec`), absolute
// run loop, padding skip, delta skip, and return. Remaining blocker is two tiny
// codegen choices: absolute run translates with equivalent SIB byte `[edx+esi]`
// instead of original `[esi+edx]`, and encoded run uses `cl`/`[eax-1]` instead of
// original `dl`/`[eax-1]` when the source is shaped to keep the original and-before-
// increment order. Variants that get `dl` in encoded run move the `inc eax` before
// the mask and regress to 6 bytes. No inline asm/hacks.

void xlatRle8(unsigned char* data, int unused, unsigned char* xlat) {
    unsigned char* p = data;
    while (1) {
        unsigned char code = p[0];
        unsigned char value = p[1];
        ++p;
        if (code == 0) {
            ++p;
            switch (value) {
            case 0:
                continue;
            case 1:
                return;
            case 2:
                p += 2;
                continue;
            }
            unsigned int count = value;
            if (value > 0) {
                do {
                    unsigned int c = *p;
                    ++p;
                    --count;
                    p[-1] = xlat[c];
                } while (count != 0);
            }
            if (value & 1) {
                ++p;
            }
        } else {
            unsigned int v = value;
            ++p;
            p[-1] = xlat[v];
        }
    }
}
