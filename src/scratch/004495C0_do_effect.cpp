// VA: 004495C0 RGE_Effects::do_effect
// effects.cpp lines 186-274
// 301 bytes
// BLOCKER: 53.8% diff (best result). First 14 bytes match perfectly.
// The core loop structure now matches: xor edi, edi; cmp [mem], di; jle
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
