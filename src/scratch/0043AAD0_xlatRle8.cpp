// attempt 1: in-place RLE8 translator with the count/value state machine and byte-table translation
// attempt 2: tried decompiler-shaped locals and a volatile spill to reach the 101-byte basin, but the register layout drifted badly
// leaving this paused in scratch because the remaining mismatch is a stable codegen-family issue, not a behavior bug
// if this is resumed, the next probe is a leaner source shape that still forces the original BL/CL/stack-temp pattern

void xlatRle8(unsigned char* data, unsigned char* xlat) {
    unsigned char* pbVar2 = data;
    unsigned char* pbVar3;
    unsigned char bVar1;

    while (1) {
        while (1) {
            pbVar3 = pbVar2;
            bVar1 = pbVar3[1];
            pbVar2 = pbVar3 + 1;
            if (*pbVar3 == 0) {
                break;
            }
            pbVar3[1] = xlat[bVar1];
            pbVar2 = pbVar3 + 2;
        }

        pbVar2 = pbVar3 + 2;
        if (bVar1 == 0) {
            continue;
        }
        if (bVar1 == 1) {
            return;
        }
        if (bVar1 == 2) {
            pbVar2 = pbVar3 + 4;
            continue;
        }
        pbVar3 = pbVar2;
        if (bVar1 != 0) {
            do {
                pbVar2 = pbVar3 + 1;
                bVar1 = (unsigned char)(bVar1 - 1);
                *pbVar3 = xlat[*pbVar3];
                pbVar3 = pbVar2;
            } while (bVar1 != 0);
        }
        if ((bVar1 & 1) != 0) {
            pbVar2 = pbVar2 + 1;
        }
    }
}
