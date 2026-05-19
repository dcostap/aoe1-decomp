// VA: 0048D040 RGE_Scenario_File_Info::save
// PDB source: sceninfo.cpp
// Default flags: /nologo /c /O2 /Oy
//
// Attempt log:
// Attempt 1-3: Iterated on loop structure (for → do-while → early decl).
//   Best result: 130/152 bytes match (85.5%), 22 bytes edit diff (14.5%).
// Attempt 4-5: Tried int* psn to force LEA into ESI. VC5 used EAX instead.
// Attempt 6: off < scenario_num*0x10C — added multiplication (shl/add/lea/shl).
// Attempt 7: Declared vars before fd — pushed ebp/esi in wrong order.
// Attempt 8: Struct-wrap to bias ESI — no change.
//
// Left in scratch: Best result (attempt 3) at 130/152 matching bytes.
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

    rge_write_uncompressed(fd, &this->scenario_num, 4);

    if (this->scenario_num > 0) {
        int off = 0;
        int cnt = 0;
        do {
            rge_write_uncompressed(fd, (char*)this->scenarios + off, 4);
            rge_write_uncompressed(fd, (char*)this->scenarios + off + 8, 0x104);

            RGE_Scenario_Header* h = *(RGE_Scenario_Header**)((char*)this->scenarios + off + 4);
            h->save(fd);

            cnt++;
            off += 0x10C;
        } while (cnt < this->scenario_num);
    }

    rge_close(fd);
}
