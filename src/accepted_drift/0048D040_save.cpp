// VA: 0048D040 RGE_Scenario_File_Info::save
// PDB source: sceninfo.cpp
// Default flags: /nologo /c /O2 /Oy
// ACCEPTED_DRIFT 2026-05-20 Boss: exact size; nonzero diff is localized to the scenario loop's equivalent address-generation/register scheduling plus consequent short-branch displacement/SIB-order shifts. Calls, stack cleanup, memory targets, loop bounds, virtual save dispatch, close path, and observable behavior match.
//
// Attempt log:
// Attempt 1-3: Iterated on loop structure (for → do-while → early decl).
//   Best result: 130/152 bytes match (85.5%), 22 bytes edit diff (14.5%).
// Attempt 4-5: Tried int* psn to force LEA into ESI. VC5 used EAX instead.
// Attempt 6: off < scenario_num*0x10C — added multiplication (shl/add/lea/shl).
// Attempt 7: Declared vars before fd — pushed ebp/esi in wrong order.
// Attempt 8: Struct-wrap to bias ESI — no change.
// Boss retry 2026-05-19:
// - Revalidated baseline: exact size, 98/152 positional, 37 edit bytes, first mismatch +29.
// - Hoisted `cnt` declaration before first write but initialized after it: preserved original push ebp
//   before count write and moved best to 76/152 positional, 26 edit bytes.
// - Typed ScenarioInfoEntry pointer variant worsened badly (sub esp 8, 81.6% positional), rolled back.
// - Reordered `+8+off` expression for name write; no encoding change.
//
// Left in scratch: Best result below at 136/152 equal bytes, 26 edit bytes.
// Remaining differences (22 bytes / 14.5%):
//   1. LEA destination: eax vs esi (lea eax,[ebx+104h] vs lea esi,[ebx+104h])
//   2. Register for push arg: eax vs esi (consequence of #1)
//   3. Dereference: mov eax,[ebx+104h] vs mov eax,[esi] — same result,
//      different addressing mode
//   4. Initial xor order: xor esi,esi before xor ebp,ebp (swapped)
//   5. Two instruction sequence: mov edx,[ebx+108h]; mov eax,esi; add eax,edx
//      vs mov eax,[ebx+108h]; add eax,esi (extra instruction)
//   6. Branch offsets differ by 2-6 bytes (consequence of #1-#5)
//   ALL are register allocation / instruction scheduling only.
//   Not proposing accepted_drift because positional diff is 59%.
// Retry 2026-05-20 assigned pass: 18 more probes. Tried direct-index/off-plus-base/base-local/entry-local/void*/int address forms for scenario entries, changing scenarios member type to char*/uchar*/int, for/while/goto loop shapes, rge_write return type/calling-convention declarations, out-of-line virtual declarations and unsigned save fd. Best remains current exact-size 152B with 136/152 equal bytes, edit diff 26 (17.1%), first mismatch at the early close-branch displacement caused by a two-byte-longer equivalent address setup in the loop. Propose accepted_drift: remaining delta is localized to register allocation/address-generation/scheduling in the loop (extra `mov edx,[base]; mov eax,esi; add eax,edx` vs original `mov eax,[base]; push 4; add eax,esi`) plus consequent branch displacements/SIB register order; calls, stack cleanup, memory targets, loop bounds, virtual call, close path, and behavior are equivalent.

#include <stdlib.h>

extern "C" {
    int rge_open(char* filename, int mode, int share);
    void rge_write_uncompressed(int fd, void* buf, int size);
    void rge_close(int fd);
}

struct RGE_Scenario_Header {
    virtual void dummy() {}
    virtual void save(int fd) {}
};

class RGE_Scenario_File_Info {
public:
    char filename[0x104];
    int scenario_num;     // +0x104
    void* scenarios;      // +0x108

    void save();
};

void RGE_Scenario_File_Info::save()
{
    int fd = rge_open(this->filename, 0x8301, 0x180);
    if (fd == -1)
        return;

    int cnt;
    rge_write_uncompressed(fd, &this->scenario_num, 4);
    cnt = 0;

    if (this->scenario_num > 0) {
        int off = 0;
        do {
            rge_write_uncompressed(fd, (char*)this->scenarios + off, 4);
            rge_write_uncompressed(fd, (char*)this->scenarios + 8 + off, 0x104);

            RGE_Scenario_Header* h = *(RGE_Scenario_Header**)((char*)this->scenarios + off + 4);
            h->save(fd);

            cnt++;
            off += 0x10C;
        } while (cnt < this->scenario_num);
    }

    rge_close(fd);
}
