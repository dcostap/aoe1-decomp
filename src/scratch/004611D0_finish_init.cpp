// RGE_Master_Player::finish_init
// VA: 004611D0
// mst_play.cpp:107-128
// 153 bytes
//
// Attempt log:
// 1: Basic pass with calloc, rge_read, loop, virtual call — 153B, 120B diff
// 2: Removed all locals except loop counter — 153B, 72B diff (35 matching at start!)
// 3-4: Function pointer cast for vtbl call — regressed
// 5: short i loop counter — regressed
// 6: extern calloc — same as 2
// 7: int n cache — regressed
// 8: No count local — same as 2
// 9: *(void***)(&sprites) cast — same as 2
// 10: rge_read(fd, &fd, 1) param reuse — regressed prologue
// 11: /O1 flag test — 144B (too small)
//
// Best result (attempts 2/6/8/9): 153B, 47% positional diff, 28.76% edit diff.
// First 35 bytes match exactly (prologue, first rge_read, calloc setup).
//
// Persistent remaining diffs:
// 1. jle offset (+6B vs +70): 1 byte — else branch is at different distance
// 2. ebp register: original keeps ebp=&this->master_object_num throughout;
//    rebuilt overwrites ebp with sounds param (pre-loaded as loop-invariant)
// 3. Zero extension: original avoids it by byte load into CL;
//    rebuilt uses and ecx,0xFF (5 bytes extra)
// 4. Loop comparison: original uses cmp di,[ebp] (3 bytes);
//    rebuilt uses movsx edx,word[esi+18h]; cmp edi,edx (7 bytes)
//    — reloads count from struct vs using cached pointer
// 5. param_3 load: original loads from stack at call site;
//    rebuilt pre-loads into ebp outside loop
//
// Root cause: VC5 register allocator chooses different strategy.
// Original keeps ebp as struct member pointer; rebuilt pre-loads
// sounds param in ebp, losing the struct pointer.
// Cannot control this from single-function TU.

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    virtual void vt_pad_04();
    virtual void load_master_object(int fd, int temp, void** sprites, void** sounds, int i);

    char gap_04[0x14];
    short master_object_num; // +0x18
    void** master_objects;   // +0x1C

    void finish_init(int fd, void** sprites, void** sounds);
};

void RGE_Master_Player::finish_init(int fd, void** sprites, void** sounds)
{
    rge_read(fd, &this->master_object_num, 2);

    if (this->master_object_num > 0) {
        this->master_objects = (void**)calloc((int)this->master_object_num, 4);
        rge_read(fd, this->master_objects, (int)this->master_object_num * 4);

        for (int i = 0; i < (int)this->master_object_num; i++) {
            if (this->master_objects[i] != 0) {
                unsigned char temp;
                rge_read(fd, &temp, 1);
                this->load_master_object(fd, (int)temp, sprites, sounds, i);
            }
        }
    } else {
        this->master_objects = 0;
    }
}
