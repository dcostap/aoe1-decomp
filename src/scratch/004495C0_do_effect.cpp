// VA: 004495C0 RGE_Effects::do_effect
// effects.cpp lines 186-274
// 301 bytes
// BLOCKER: typed dispatch and all seven call targets match, but VC5 emits
// integer float pushes instead of the oracle's fld/reserved-stack/fstp form.
// Remaining differences:
// 1. Float arg passing: rebuilt uses mov edx,[mem];push edx while
//    original uses fld dword [mem]; push ecx/temp; fstp [esp]
// 2. CALL instructions are placeholder relocations (e800000000) in rebuilt
// 3. Jump table address is placeholder (00000000) instead of 4496F0h
// 4. Case 1 vtable call at offset 0x78: uses extern function ptr
//
// Attempt log:
// - best version (no extra locals): first 14 bytes match, 53.8% overall
// - with float f local: regressed to 68% (extra stack slot)
// - real member functions through RGE_Player: placeholder CALL relocations
// - extern __fastcall wrappers: different calling convention
// - union to cast int to MFP: compile error possible
// - __declspec(naked) vtable thunk: inline asm forbidden by policy
// - removed outer if(effect_list_num>0): no change
// - for(short) with correct loop structure: matches cmp [mem],di pattern
// - replaced the fake extern with the typed virtual add_attribute_num at vslot 0x78
// - changed the modify_tobj family's final argument to unsigned char
// - restored case order 4,5,0,1,2,3 and > -1 predicates; call sites became aligned
// - per-case float locals did not produce the original FPU staging; rolled back
// - full effects.cpp ABI and RGE_Player destructor slot did not change emission
// - explicit float casts and typed-float address expressions were codegen duplicates
// - an inline float-return accessor reproduced FPU staging but changed load order
//   and block layout; it was rejected as a compiler-steering helper
// - first-short locals with the accessor were unchanged; restored direct fields
// - typed command reference ownership emitted a codegen duplicate; restored the pointer form
// FLAGS: none
// NOTE: Natural source keeps the proven RGE_Effect layout, full polymorphic ABI,
// switch order, signed guards, and all call targets. Remaining drift is local
// float argument staging plus jump-table placement/relocation context.
// Readiness audit restored executable field-read behavior: cases 0, 4, and 5
// read the full change_num3 short before narrowing it for the byte parameter.
// Case 1 reads both shorts and the float before it tests change_num1.

struct RGE_Effect_Command {
    unsigned char command; unsigned char _pad_0;
    short change_num1; short change_num2; short change_num3; float change_amount;
};

struct RGE_Effect {
    short id; char name[31]; unsigned char _pad_0;
    short string_table_id; short effect_list_num;
    unsigned char _pad_1[2]; RGE_Effect_Command* effect_list;
};

struct RGE_Player {
    virtual ~RGE_Player();
    virtual void v04();  virtual void v08();
    virtual void v0C();  virtual void v10();  virtual void v14();
    virtual void v18();  virtual void v1C();  virtual void v20();
    virtual void v24();  virtual void v28();  virtual void v2C();
    virtual void v30();  virtual void v34();  virtual void v38();
    virtual void v3C();  virtual void v40();  virtual void v44();
    virtual void v48();  virtual void v4C();  virtual void v50();
    virtual void v54();  virtual void v58();  virtual void v5C();
    virtual void v60();  virtual void v64();  virtual void v68();
    virtual void v6C();  virtual void v70();  virtual void v74();
    virtual void add_attribute_num(short a, float b, unsigned char c);

    void modify_tobj(short a, short b, float c, unsigned char d);
    void new_attribute_num(short a, float b);
    void make_available(short a, unsigned char b);
    void copy_obj(short a, short b);
    void modify_tobj_delta(short a, short b, float c, unsigned char d);
    void modify_tobj_percent(short a, short b, float c, unsigned char d);
};

struct RGE_Effects {
    virtual ~RGE_Effects();
    virtual void save(int fd);
    virtual void do_effect(short effect_id, RGE_Player* player);
    RGE_Effect* effects; long effect_num;
};

void RGE_Effects::do_effect(short effect_id, RGE_Player* player) {
    if (effect_id < effect_num) {
        RGE_Effect* eff = &effects[effect_id];
        if (eff) {
            for (short i = 0; i < eff->effect_list_num; i++) {
                RGE_Effect_Command* cmd = &eff->effect_list[i];
                switch (cmd->command) {
                case 4: {
                    short operation = cmd->change_num3;
                    player->modify_tobj_delta(cmd->change_num1, cmd->change_num2, cmd->change_amount,
                                              (unsigned char)operation);
                    break;
                }
                case 5: {
                    short operation = cmd->change_num3;
                    player->modify_tobj_percent(cmd->change_num1, cmd->change_num2, cmd->change_amount,
                                                (unsigned char)operation);
                    break;
                }
                case 0: {
                    short operation = cmd->change_num3;
                    player->modify_tobj(cmd->change_num1, cmd->change_num2, cmd->change_amount,
                                        (unsigned char)operation);
                    break;
                }
                case 1: {
                    short attribute = cmd->change_num1;
                    short mode = cmd->change_num2;
                    float amount = cmd->change_amount;
                    if (attribute > -1) {
                        if (mode == 0) {
                            player->new_attribute_num(attribute, amount);
                        } else {
                            player->add_attribute_num(attribute, amount, 0);
                        }
                    }
                    break;
                }
                case 2:
                    if (cmd->change_num1 > -1) {
                        player->make_available(cmd->change_num1, (unsigned char)cmd->change_num2);
                    }
                    break;
                case 3:
                    player->copy_obj(cmd->change_num1, cmd->change_num2);
                    break;
                }
            }
        }
    }
}
