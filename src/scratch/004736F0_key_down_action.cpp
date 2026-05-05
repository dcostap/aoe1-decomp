// VA: 004736F0 TButtonPanel::key_down_action(long, short, int, int, int)
// PDB source: Pnl_btn.cpp lines 1071-1110 (359 bytes, 98 asm lines)
// Default flags
//
// __thiscall: this in ecx, 5 stack params, ret 14h. Returns long.
//
// Left in scratch: stable VC5 version heuristic differences.
//
// Key differences from original:
// 1. Switch dispatch: Original uses a jump table + bitmask map (2 tables,
//    64 bytes of .text data) for cases 0x0D-0x28. VC5 generates if/else
//    chains (`sub eax,0x26; je; sub eax,2; je`). The bitmask compress
//    table is an optimization the newer VC5 doesn't use for sparse switches.
// 2. Shared return 0 path: Original has a single shared `xor eax,eax;
//    pop edi; pop esi; ret 14h` at the end. VC5 places `je short` to
//    the return code instead of `jne near` to a shared tail. Both are
//    functionally equivalent but have different branch direction.
// 3. Result: 336-400 bytes generated vs 359 original, depending on
//    switch formulation. Dense switch (28 cases) = 400 bytes (too big).
//    If/else = 336 bytes (too small). Jump table + bitmask = 359 bytes
//    (original, unreachable via C++).
//
// Matched portions:
// - Prologue: push esi; mov esi,ecx; push edi ✓
// - key_down check at +0x2AC ✓
// - Bounds check: lea eax,[edi-0Dh]; cmp eax,1Bh; ja ✓
// - Field layout: field_40@+0x40, field_74@+0x74, digital_sound@+0x148,
//   cur_state@+0x1F6, is_down@+0x1F8, button_down_time@+0x204,
//   key_down@+0x2AC, field_2B0@+0x2B0 ✓
// - Virtual dispatch: vf08@vtable+0x20 (call [eax+20h]) ✓
// - Virtual dispatch: vf45@vtable+0xB4 (call [edx+0B4h]) ✓
// - set_curr_child: direct __thiscall, ecx=parent, stack=child ✓
// - TDigital: is_playing, stop, play calls (relocation targets) ✓
// - id arrays: id@+0x0F4, id2@+0x118 ✓

struct TDigital {
    int is_playing();
    void stop();
    int play();
};

struct VfTable {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int arg);     // vtable+0x20
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();            // vtable+0xB0 (slot 44)
    virtual void vf45(void* panel, int mode, int id, int id2);  // vtable+0xB4
};

struct TPanel {
    void set_curr_child(void* child);
};

struct TButtonPanel {
    VfTable* vtable;                    // +0x00
    char gap_04[0x0C - 0x04];
    void* field_0C;                     // +0x0C
    void* field_10;                     // +0x10
    char gap_14[0x40 - 0x14];
    TPanel* field_40;                   // +0x40 (parent panel)
    char gap_44[0x60 - 0x44];
    void* up_panel;                     // +0x60
    void* down_panel;                   // +0x64
    char gap_68[0x74 - 0x68];
    void* field_74;                     // +0x74
    char gap_78[0x0F4 - 0x78];
    int id[12];                         // +0x0F4 (0x0F4 to 0x124)
    char gap_124[0x148 - 0x124];
    TDigital* digital_sound;            // +0x148
    char gap_14C[0x1F6 - 0x14C];
    short cur_state;                    // +0x1F6
    int is_down;                        // +0x1F8
    char gap_1FC[0x204 - 0x1FC];
    unsigned long button_down_time;     // +0x204
    char gap_208[0x2AC - 0x208];
    long key_down;                      // +0x2AC
    int field_2B0;                      // +0x2B0

    long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
};

extern unsigned long debug_timeGetTime(char* file, int line);

long TButtonPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    if (this->key_down) {
        return 0;
    }

    switch (param_1) {
    case 0x28: // DOWN arrow
        if (param_3) return 1;
        if (param_4) return 1;
        if (!this->field_74) return 1;
        if (!this->field_40) return 1;
        if (!this->down_panel) return 1;
        this->field_40->set_curr_child(this->down_panel);
        return 1;

    case 0x26: // UP arrow
        if (param_3) return 1;
        if (param_4) return 1;
        if (!this->field_74) return 1;
        if (!this->field_40) return 1;
        if (!this->up_panel) return 1;
        this->field_40->set_curr_child(this->up_panel);
        return 1;

    default:
        if (this->field_2B0) return 0;
        if (param_3) return 0;
        if (param_4) return 0;

        if (this->digital_sound) {
            if (this->digital_sound->is_playing()) {
                this->digital_sound->stop();
            }
            this->digital_sound->play();
        }

        this->key_down = param_1;
        this->is_down = 1;
        this->button_down_time = debug_timeGetTime("Pnl_btn.cpp", 0x44B);
        ((VfTable*)this)->v08(1);

        if (this->field_40) {
            int state = this->cur_state;
            int id_val = ((int*)((char*)this + 0x0F4))[state];
            int id2_val = ((int*)((char*)this + 0x118))[state];
            ((VfTable*)this->field_40)->vf45(this, 2, id_val, id2_val);
        }
        return 1;
    }
}
