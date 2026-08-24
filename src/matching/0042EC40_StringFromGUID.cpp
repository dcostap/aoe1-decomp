// 0042EC40 StringFromGUID
// honest pass: improved from parked register-allocation mismatch to 2-byte SIB encoding drift.
// tried: mutable output pointer to keep EAX; int loop plus unsigned loop condition to keep ESI and jb; local guid/g pointer and struct byte-array surface.
// remaining scratch gap: two equivalent byte loads encode as [ecx+edi]/[edx+edi] instead of original [edi+ecx]/[edi+edx]; behavior/call/stack/loop shape otherwise byte-identical.
// Additional tries this round: pointer-add temp, int/long/uchar index locals, char* guid surface, raw (unsigned char*)guid loads, map pointer local, volatile guid pointer, commuted subscript spelling idx[g], and signed index. No exact; most perturb register allocation/loop shape, best remains the 2-byte SIB encoding drift.
// ACCEPTED_DRIFT: reviewed by Boss. Only two x86 SIB bytes differ for commutative
// base/index addressing of the same byte loads (`[edi+ecx]` vs `[ecx+edi]`,
// `[edi+edx]` vs `[edx+edi]`). Prologue, loop, branches, stores, table lookups,
// return value, stack/register saves, size, and memory effects are otherwise identical.

extern unsigned char DAT_0056f218[20];
extern unsigned short u_0123456789ABCDEF_0056f230[16];

struct GUIDBytes { unsigned char b[16]; };

extern "C" int __cdecl StringFromGUID(GUIDBytes* guid, unsigned short* output)
{
    int i;
    unsigned char* g;

    g = guid->b;
    *output = 0x7b;
    output = output + 1;
    i = 0;
    do {
        if (DAT_0056f218[i] == '-') {
            *output = '-';
        } else {
            output = output + 1;
            output[-1] = u_0123456789ABCDEF_0056f230[g[DAT_0056f218[i]] >> 4];
            output[0] = u_0123456789ABCDEF_0056f230[g[DAT_0056f218[i]] & 0xf];
        }
        output = output + 1;
        i = i + 1;
    } while ((unsigned int)i < 20);
    *output = '}';
    output[1] = 0;
    return 0x26;
}
