// VA: 004495C0 RGE_Effects::do_effect
// effects.cpp lines 186-274
// 301 bytes
// BLOCKER: Deep codegen differences from extern member function calls.
// The original uses direct CALL relocations (resolved by linker) while
// our extern function declarations produce placeholder CALLs. The switch
// case bodies also differ in how they pass float args (fld/fstp vs mov/push).
//
// Attempt log:
// - real member functions through RGE_Player: placeholder CALL relocations
// - extern "C" __fastcall wrappers: different calling convention (ecx/edx vs stack)
// - union to cast int to member function pointer: same issue
// - __declspec(naked) vtable thunk: inline asm forbidden by policy
// - short i declared outside for loop: no prologue change
// - do-while pattern instead of for: same codegen
// - removed outer if(effect_list_num>0): same 70% diff
// FLAGS: none
// NOTE: Would need real function addresses or TU context to match calls.

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
    void* vtable_ptr;
    void modify_tobj(short a, short b, float c, short d);
    void new_attribute_num(short a, float b);
    void make_available(short a, unsigned char b);
    void copy_obj(short a, short b);
    void modify_tobj_delta(short a, short b, float c, short d);
    void modify_tobj_percent(short a, short b, float c, short d);
};

struct RGE_Effects {
    void* vtable_ptr; RGE_Effect* effects; long effect_num;
    void do_effect(short effect_id, RGE_Player* player);
};

extern "C" void __fastcall player_vfunc_78(RGE_Player* player, short a, float b, int c);

void RGE_Effects::do_effect(short effect_id, RGE_Player* player) {
    if (effect_id < effect_num) {
        RGE_Effect* eff = &effects[effect_id];
        if (eff) {
            for (short i = 0; i < eff->effect_list_num; i++) {
                RGE_Effect_Command* cmd = &eff->effect_list[i];
                switch (cmd->command) {
                case 0:
                    player->modify_tobj(cmd->change_num1, cmd->change_num2, cmd->change_amount, cmd->change_num3);
                    break;
                case 1:
                    if (cmd->change_num1 >= 0) {
                        if (cmd->change_num2 == 0) {
                            player->new_attribute_num(cmd->change_num1, cmd->change_amount);
                        } else {
                            player_vfunc_78(player, cmd->change_num1, cmd->change_amount, 0);
                        }
                    }
                    break;
                case 2:
                    if (cmd->change_num1 >= 0) {
                        player->make_available(cmd->change_num1, (unsigned char)cmd->change_num2);
                    }
                    break;
                case 3:
                    player->copy_obj(cmd->change_num1, cmd->change_num2);
                    break;
                case 4:
                    player->modify_tobj_delta(cmd->change_num1, cmd->change_num2, cmd->change_amount, cmd->change_num3);
                    break;
                case 5:
                    player->modify_tobj_percent(cmd->change_num1, cmd->change_num2, cmd->change_amount, cmd->change_num3);
                    break;
                }
            }
        }
    }
}
