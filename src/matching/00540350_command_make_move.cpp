// 00540350 command_make_move
// RGE_Main_View::command_make_move(long param_1, long param_2)
// Source: vw_main.cpp lines 1818-1846
// Size: 197 bytes
//
// Status: MATCH - exact under config/flags/default.rsp
//
// Attempt log:
// Probe 1 baseline: old type-pun/early-return reconstruction; frame was 0x18
//   instead of 0x1C and the two guard failures were inline.
// Probe 2 layout: canonical list/list_num/pick_info locals, real pick1 and
//   RGE_Player::command_make_move prototypes, nested positive guards, and
//   proven absolute globals restored the 0x1C frame and 98.63% shape.
// Probe 3 liveness: removed the redundant explicit byte cast after using the
//   accurately typed unsigned-char command_make_move return; exact 197 bytes.
// Grouped ABI recovery: the final +10 virtual call is set_game_mode(0, 0),
//   matching the shared RGE_Base_Game surface and the original call slot.
// Frame layout is VC5 TU-context dependent.

#include <stdlib.h>

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Tile;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

struct RGE_Base_Game;

struct RGE_Base_Game {
    virtual void vt_pad_00();
    virtual void vt_pad_01();
    virtual void vt_pad_02();
    virtual void vt_pad_03();
    virtual void set_game_mode(int mode, int sub_mode);
};

extern int allow_user_commands;
extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    virtual void vt_pad_00();
    virtual void vt_pad_01();
    virtual void vt_pad_02();
    virtual void vt_pad_03();
    virtual void vt_pad_04();
    virtual void vt_pad_05();
    virtual void vt_pad_06();
    virtual void vt_pad_07();
    virtual void vt_pad_08();
    virtual void vt_pad_09();
    virtual void vt_pad_10();
    virtual void vt_pad_11();
    virtual void vt_pad_12();
    virtual void vt_pad_13();
    virtual void vt_pad_14();
    virtual void vt_pad_15();
    virtual void vt_pad_16();
    virtual void vt_pad_17();
    virtual void vt_pad_18();
    virtual void vt_pad_19();
    virtual void vt_pad_20();
    virtual void vt_pad_21();
    virtual void vt_pad_22();
    virtual void vt_pad_23();
    virtual void vt_pad_24();
    virtual void vt_pad_25();
    virtual void vt_pad_26();
    virtual void vt_pad_27();
    virtual void vt_pad_28();
    virtual void vt_pad_29();
    virtual void vt_pad_30();
    virtual void vt_pad_31();
    virtual void vt_pad_32();
    virtual void vt_pad_33();
    virtual void vt_pad_34();
    virtual void vt_pad_35();
    virtual void vt_pad_36();
    virtual void vt_pad_37();
    virtual void vt_pad_38();
    virtual void vt_pad_39();
    virtual unsigned char command_make_move(RGE_Static_Object* target, float x, float y);

    unsigned char get_selected_objects_to_command(
        RGE_Static_Object*** list_out, short* list_num_out,
        short min_select_level, short object_group,
        short object_id, short unit_level);
};

class RGE_Main_View {
public:
    virtual void vt_pad_00();
    virtual void vt_pad_01();
    virtual void vt_pad_02();
    virtual void vt_pad_03();
    virtual void vt_pad_04();
    virtual void vt_pad_05();
    virtual void vt_pad_06();
    virtual void vt_pad_07();
    virtual void set_redraw(int mode);

    char pad_004[0xFC];
    RGE_Player* player;

    unsigned char pick1(unsigned char command, unsigned char mode,
                        long x, long y, RGE_Pick_Info* info,
                        RGE_Static_Object* exclude, int flags);
    void fixup_pick_info(RGE_Pick_Info* info);

    int command_make_move(long param_1, long param_2);
};
#endif

int RGE_Main_View::command_make_move(long param_1, long param_2)
{
    RGE_Static_Object** list;
    short list_num;
    RGE_Pick_Info pick_info;
    int result;

    if (allow_user_commands != 0) {
        if (this->player->get_selected_objects_to_command(
                &list, &list_num, -1, -1, -1, -1)) {
            free(list);

            result = 0;
            if (this->pick1(0x2A, 1, param_1, param_2,
                            &pick_info, 0, 1) != 0x32) {
                this->fixup_pick_info(&pick_info);
                result = this->player->command_make_move(
                    pick_info.object, pick_info.x, pick_info.y);
                this->set_redraw(1);
            }

            rge_base_game->set_game_mode(0, 0);
            return result;
        }
    }
    return 0;
}
