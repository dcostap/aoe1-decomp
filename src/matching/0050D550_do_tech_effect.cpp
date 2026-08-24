// VA: 0050D550 TRIBE_Effects::do_tech_effect
// MATCHED: writing the kind dispatch as a switch on raw byte values (case 0x65 skip,
// case 0x66 call) makes VC5 emit the original `sub ecx,65; je; dec ecx; jne` sequence
// and use `push 0`, unlike equivalent nested if/decrement forms.
// Previous state: rebuilt matched prolog/index/record setup and main loop topology, but
// drifted in condition/codegen around effect kind and zero enable arg.
// 2026-05-09 GraniteCub: tried 18 focused variants around the stubborn hunk: `--kind == 0`,
// `kind--; if/else`, goto labels after dec, switch on adjusted kind, switch/direct byte tests,
// signed/long kind, explicit zero locals/volatile zero/constant spellings, and tech_abling second
// parameter widths (`int`, `long`, `short`, `char`, `unsigned char`). All stayed in the same
// 33 positional / 13 edit diff basin or regressed. Blocker remains VC5's redundant post-dec
// `test ecx,ecx` plus `push ecx` instead of original flag-preserving `dec ecx; jne` and `push 0`.

#include "../../include/teffects_context.h"

void TRIBE_Effects::do_tech_effect(short tech_id, RGE_Player* player) {
    int index = tech_id;
    unsigned char* base = (unsigned char*)this->effects;
    int scaled = index + index * 4;
    int recIndex = index + scaled * 2;
    unsigned char* record = base + recIndex * 4;
    int i = 0;

    if (*(short*)(record + 0x24) > 0) {
        int offset = 0;
        do {
            unsigned char* effect = *(unsigned char**)(record + 0x28) + offset;
            unsigned int kind = *effect;
            switch (kind) {
            case 0x65:
                break;
            case 0x66:
                ((TRIBE_Player*)player)->tech_abling((long)*(float*)(effect + 8), 0);
                break;
            }
            i++;
            offset += 0x0C;
        } while (i < *(short*)(record + 0x24));
    }
}
