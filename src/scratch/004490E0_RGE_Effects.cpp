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
// - corrected the binary-proven outer record ownership: the original rereads
//   `effects` for the name but applies the running byte offset only to the
//   count/list fields; the prior indexed `eff` source changed this behavior.
// - structural reconstruction now matches the 10-call set, exact 352-byte
//   boundary, frame-size neighborhood, and original zero/list CFG; the
//   remaining gap is VC5 register/local-home scheduling (this is not an
//   unresolved field-width or call-ABI question).
// - final diagnostic used a volatile list-field pointer to reproduce the
//   stack-lived field address, but that qualifier is not binary-proven source
//   and was removed from the living candidate; keep the natural typed pointer.
// Fresh pass:
// - baseline retained the prior canonical candidate at diff 321.
// - named the offset-bearing RGE_Effect owner and took list_ptr from its typed
//   effect_list field; this reached exact size/frame and diff 300.
// - combined that ownership model with the known effects.cpp polymorphic class
//   surface; diff moved to 298.
// - reread the typed count pointer in the inner loop condition. This restored
//   the original inner instruction order, reached 62.5% exact-block coverage,
//   and reduced the positional diff to 262, but left an extra outer entry jump
//   and eight bytes past the original boundary.
// - outer while form, self->effect_num as the repeated bound, typed short count,
//   and function-scope owner locals produced no new codegen.
// Best current source keeps the natural typed ownership and the binary-proven
// count reread. Remaining gap is structural outer-entry sharing plus vtable
// relocation context; no unresolved field layout or call ABI issue remains.

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

class RGE_Player;

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    virtual void save(int fd);
    virtual void do_effect(short effect_id, RGE_Player* player);
    RGE_Effect* effects;
    long effect_num;
    RGE_Effects(int fd);
};

RGE_Effects::RGE_Effects(int fd) {
    RGE_Effects* self = this;
    int file = fd;
    long* peffect = &self->effect_num;
    int outer_count;
    int index;
    int inner_count;
    RGE_Effect_Command** list_ptr;
    RGE_Effect* effect;
    RGE_Effect* fields;
    short* count_ptr;
    rge_read(file, peffect, 4);
    if (*peffect > 0) {
        self->effects = (RGE_Effect*)calloc(*peffect, 0x2C);
        outer_count = 0;
        if (outer_count < *peffect) {
            index = 0;
            do {
                effect = self->effects;
                fields = (RGE_Effect*)((char*)self->effects + index);
                rge_read(file, effect->name, 0x1F);
                count_ptr = &fields->effect_list_num;
                list_ptr = &fields->effect_list;
                rge_read(file, count_ptr, 2);
                if (fields->effect_list_num > 0) {
                    RGE_Effect_Command* allocated =
                        (RGE_Effect_Command*)calloc(fields->effect_list_num, 0x0C);
                    inner_count = 0;
                    *list_ptr = allocated;
                    if (fields->effect_list_num > 0) {
                        fd = 0;
                        do {
                            char* command = (char*)
                                *list_ptr + fd;
                            rge_read(file, command, 1);
                            rge_read(file, command + 2, 2);
                            rge_read(file, command + 4, 2);
                            rge_read(file, command + 6, 2);
                            rge_read(file, command + 8, 4);
                            inner_count++;
                            fd += 0x0C;
                        } while (inner_count < *(short*)count_ptr);
                    }
                } else {
                    *list_ptr = 0;
                }
                outer_count++;
                index += 0x2C;
            } while (outer_count < self->effect_num);
        }
    } else {
        self->effects = 0;
        self->effect_num = 0;
    }
}
