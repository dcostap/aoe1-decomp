// VA: 0049A8F0 calc_text_msg (542B)
// scr_game.cpp:4044-4097
//
// Natural reconstruction of the item-cost text formatter.  The four explicit
// arguments are the output buffer, item record, an unused value, and the
// command string id.
//
// Attempt log:
// - baseline: named Item_Avail fields and typed virtual string APIs had the
//   right calls but omitted one live 512-byte scratch buffer.
// - layout: restored the scratch buffer and the six-buffer stack frame; size,
//   calls, and all item-cost blocks aligned.
// - behavior: used the command buffer base. The decompiler's stack plus-four
//   label was not source ownership. This moved the first mismatch to the
//   final return path.
// - control-flow: separate command-and-cost and command predicates reproduced
//   the loaded command byte, duplicate test, and all earlier bytes.
// - liveness and variant probes did not change the final empty-output tail.
//   The retained source uses ordinary assignment and return statements.
// - left in scratch: 15 bytes in the empty-output epilogue. Calls, memory
//   effects, frame, size, and all earlier blocks match; the remaining lead is
//   VC5 register choice for the final output pointer.

#include <stdio.h>

class Item_Avail {
public:
    char* name;
    short id;
    short pict;
    short inventory_item_1;
    unsigned char gap_0A[2];
    float inventory_cost_1;
    short inventory_item_2;
    unsigned char gap_12[2];
    float inventory_cost_2;
    short inventory_item_3;
    unsigned char gap_1A[2];
    float inventory_cost_3;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int value);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int id, char* buffer, int length);
    virtual char* get_string(long id, char* buffer, int length);
    virtual char* get_string(long id);
    virtual char* get_string2(int id, long value1, long value2,
                              char* buffer, int length);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char* calc_text_msg(char* text, Item_Avail* item, long unused,
                        long command_id);
};

char* TRIBE_Screen_Game::calc_text_msg(char* text, Item_Avail* item,
                                       long unused, long command_id) {
    char command_str[512];
    char str[512];
    char cost_str[512];
    char cost_str1[512];
    char cost_str2[512];
    char inven_str[512];

    rge_base_game->get_string(command_id, command_str, 0x200);
    cost_str1[0] = 0;

    if (item != 0) {
        if (item->inventory_item_1 == -1 || item->inventory_item_1 > 3) {
            cost_str2[0] = 0;
        } else {
            rge_base_game->get_string2(0x64, item->inventory_item_1, 0,
                                       str, 0x200);
            sprintf(cost_str2, "%s: %d", str,
                    (int)item->inventory_cost_1);
        }

        if (item->inventory_item_2 == -1 || item->inventory_item_2 > 3) {
            inven_str[0] = 0;
        } else {
            rge_base_game->get_string2(0x64, item->inventory_item_2, 0,
                                       str, 0x200);
            sprintf(inven_str, "  %s: %d", str,
                    (int)item->inventory_cost_2);
        }

        if (item->inventory_item_3 == -1 || item->inventory_item_3 > 3) {
            cost_str[0] = 0;
        } else {
            rge_base_game->get_string2(0x64, item->inventory_item_3, 0,
                                       str, 0x200);
            sprintf(cost_str, "  %s: %d", str,
                    (int)item->inventory_cost_3);
        }

        if (cost_str2[0] != 0 || inven_str[0] != 0 || cost_str[0] != 0) {
            sprintf(cost_str1, "(%s%s%s)", cost_str2, inven_str, cost_str);
        }
    }

    if (command_str[0] != 0 && cost_str1[0] != 0) {
        sprintf(text, "%s %s", command_str, cost_str1);
        return text;
    }
    if (command_str[0] != 0) {
        sprintf(text, "%s", command_str);
        return text;
    }
    text[0] = 0;
    return text;
}
