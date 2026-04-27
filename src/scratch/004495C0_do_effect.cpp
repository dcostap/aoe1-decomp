// VA: 004495C0 RGE_Effects::do_effect
// effects.cpp lines 186-274
// 301 bytes

// attempt 1: switch on command type, ret 8, __thiscall

class RGE_Player;

struct RGE_Effect_Command {
    char command;       // +0x00
    char pad;           // +0x01
    short change_num1;  // +0x02
    short change_num2;  // +0x04
    short change_num3;  // +0x06
    float change_amount; // +0x08
};

struct RGE_Effect {
    short id;                   // +0x00
    char name[0x22];            // +0x02
    short effect_list_num;      // +0x24
    short pad2;                 // +0x26
    RGE_Effect_Command* effect_list; // +0x28
};

struct RGE_Effects {
    int* vtable;        // +0x00
    RGE_Effect* effects; // +0x04
    int effect_num;      // +0x08
};

void __thiscall modify_tobj(RGE_Player* player, short a, short b, float amt, short c);
void __thiscall modify_tobj_delta(RGE_Player* player, short a, short b, float amt, short c);
void __thiscall modify_tobj_percent(RGE_Player* player, short a, short b, float amt, short c);
void __thiscall new_attribute_num(RGE_Player* player, short a, float amt);
void __thiscall make_available(RGE_Player* player, short a, char b);
void __thiscall copy_obj(RGE_Player* player, short a, short b);

int __thiscall RGE_Player::_virtual_0x78(short a, float amt, int zero);

void __thiscall RGE_Effects::do_effect(short effect_id, RGE_Player* player) {
    if (effect_id < effect_num) {
        RGE_Effect* eff = &effects[effect_id];
        if (eff != 0 && eff->effect_list_num > 0) {
            int i;
            for (i = 0; i < eff->effect_list_num; i++) {
                RGE_Effect_Command* cmd = &eff->effect_list[i];
                switch (cmd->command) {
                case 0:
                    modify_tobj(player, cmd->change_num1, cmd->change_num2, cmd->change_amount, cmd->change_num3);
                    break;
                case 1:
                    if (cmd->change_num1 >= 0) {
                        if (cmd->change_num2 == 0) {
                            new_attribute_num(player, cmd->change_num1, cmd->change_amount);
                        } else {
                            player->_virtual_0x78(cmd->change_num1, cmd->change_amount, 0);
                        }
                    }
                    break;
                case 2:
                    if (cmd->change_num1 >= 0) {
                        make_available(player, cmd->change_num1, cmd->change_num2);
                    }
                    break;
                case 3:
                    copy_obj(player, cmd->change_num1, cmd->change_num2);
                    break;
                case 4:
                    modify_tobj_delta(player, cmd->change_num1, cmd->change_num2, cmd->change_amount, cmd->change_num3);
                    break;
                case 5:
                    modify_tobj_percent(player, cmd->change_num1, cmd->change_num2, cmd->change_amount, cmd->change_num3);
                    break;
                }
            }
        }
    }
}
