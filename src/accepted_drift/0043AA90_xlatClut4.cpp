// ACCEPTED_DRIFT: VC5 AND-before-SHR preference for byte-nibble operations.
// VC5 always computes AND (low nibble) in eax before SHR (high nibble) in edx,
// requiring ebx/bl for the clut[low] lookup result. The original does SHR first,
// letting both lookup results reuse eax/edx. This is a stable VC5 register
// allocation heuristic; no source restructuring can flip it.
// VA: 0043AA90 xlatClut4 (50B, Dib.cpp)

void __cdecl xlatClut4(unsigned char *buf, unsigned int count, unsigned char *clut)
{
    while (count) {
        unsigned int v = *buf;
        unsigned int h = v >> 4;
        *buf = (unsigned char)(clut[h] << 4) | clut[v & 0x0F];
        ++buf;
        --count;
    }
}
