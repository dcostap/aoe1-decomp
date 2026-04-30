// VA: 004490E0 RGE_Effects::RGE_Effects(int fd)
// effects.cpp lines 21-63
// 352 bytes
// BLOCKER: register allocation chooses esi/edi for this (needs ebx).
// All C++ variants tried produce esi=this (or edi=this) while the original
// uses ebx=this. This stems from a VC5 heuristic we couldn't influence.
//
// Attempt log:
// - natural C++ with vtable_ptr member: esi=this, ebx=&effect_num, ebp=0/running offset
// - int* peffect = &effect_num: same pattern
// - vtable_ptr before/after peffect: same
// - comma-separated for loops with explicit offset: edi=this (worse prologue)
// - Ghidra decomp literal with long* plVar1 and do-while: same esi=this
// - RGE_Effect* eff vs direct effects[i] access: same
// - (int*)(this)+2 for &effect_num: same esi=this
// - compound for(;;) with off+=0x2C: edi=this, changed frame size
// - __thiscall standalone function: does not link properly
// - vtable written first in body: esi=this
// - destroy() declared in class: no effect
// FLAGS: none
// NOTE: The int ctor and save have the same register allocation problem.
// A combined-TU compile might fix this but requires infrastructure changes.

void __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl calloc(int count, int size);

struct RGE_Effect_Command {
    unsigned char command; unsigned char _pad_0;
    short change_num1; short change_num2; short change_num3; float change_amount;
};

struct RGE_Effect {
    short id; char name[31]; unsigned char _pad_0;
    short string_table_id; short effect_list_num;
    unsigned char _pad_1[2]; RGE_Effect_Command* effect_list;
};

struct RGE_Effects {
    void* vtable_ptr; RGE_Effect* effects; long effect_num;
    RGE_Effects(int fd);
};

RGE_Effects::RGE_Effects(int fd) {
    long* peffect = &effect_num;
    vtable_ptr = (void*)0x570430;
    rge_read(fd, peffect, 4);
    if (*peffect > 0) {
        effects = (RGE_Effect*)calloc(*peffect, 0x2C);
        if (*peffect > 0) {
            for (int i = 0; i < *peffect; i++) {
                RGE_Effect* eff = &effects[i];
                rge_read(fd, eff->name, 0x1F);
                rge_read(fd, &eff->effect_list_num, 2);
                if (eff->effect_list_num > 0) {
                    eff->effect_list = (RGE_Effect_Command*)calloc(eff->effect_list_num, 0x0C);
                    if (eff->effect_list_num > 0) {
                        for (int j = 0; j < eff->effect_list_num; j++) {
                            RGE_Effect_Command* cmd = &eff->effect_list[j];
                            rge_read(fd, &cmd->command, 1);
                            rge_read(fd, &cmd->change_num1, 2);
                            rge_read(fd, &cmd->change_num2, 2);
                            rge_read(fd, &cmd->change_num3, 2);
                            rge_read(fd, &cmd->change_amount, 4);
                        }
                    }
                } else {
                    eff->effect_list = 0;
                }
            }
        }
    } else {
        effects = 0;
        effect_num = 0;
    }
}
