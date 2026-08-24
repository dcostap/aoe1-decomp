// VA: 0052D320 command_place_multi_object (456B)
// tvw_main.cpp, lines 319-376
//
// Attempt log:
// - Reconstructed the period command path from the executable's global/base
//   fields, player/master lookup, wall-line calls, and shared cleanup tail.
// - Positive mode-7 layout restored the original long non-mode branch and all
//   ten ordered call sites; direct player reloads preserve the inherited +100
//   ownership surface.
// - Named int endpoint locals and distance spelling variants were codegen
//   duplicates in the original branch order.
// - Matching the original unequal-branch order, typed abs() distances, and
//   comparison operand order restored the exact wall-call block layout.
// - A direct success guard around command_make_wall restored the original
//   byte-result test and completed the exact match.

#include <stdlib.h>

#ifndef TVW_MAIN_SHARED_CONTEXT
class RGE_Master_Static_Object;
class TRIBE_Master_Building_Object;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;

    unsigned char command_make_wall(
        short type, long p1, long p2, long p3, long p4);
};

class TRIBE_Player : public RGE_Player {
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int value);

    char gap_04[0x1AC];
    int prog_mode;
    char gap_1B4[0x248];
    short master_obj_id;
};

extern int allow_user_commands;
extern RGE_Base_Game* rge_base_game;

class RGE_Main_View {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);

    char gap_04[0xFC];
    RGE_Player* player;

    void set_selection_area(long x0, long y0, long x1, long y1);
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    virtual int command_place_multi_object(
        long a, long b, long c, long d, int mode);

    void place_line_of_walls(
        TRIBE_Player* player, TRIBE_Master_Building_Object* master,
        int x1, int y1, int x2, int y2);
};
#endif

int TRIBE_Main_View::command_place_multi_object(
    long param_1, long param_2, long param_3, long param_4, int mode) {
    int result = 0;

    if (allow_user_commands == 0)
        return 0;

    short master_id = rge_base_game->master_obj_id;

    if (rge_base_game->prog_mode == 7) {
        if (master_id != -1) {
        TRIBE_Master_Building_Object* master =
            (TRIBE_Master_Building_Object*)
                ((TRIBE_Player*)this->player)->master_objects[master_id];

        if (master != 0) {
            int end_y = (int)param_4;
            int start_y = (int)param_2;
            int end_x = (int)param_3;
            int start_x = (int)param_1;

            int row_distance = abs(end_y - start_y);
            int col_distance = abs(end_x - start_x);

            if (row_distance == col_distance) {
                this->place_line_of_walls(
                    (TRIBE_Player*)this->player, master,
                    start_x, start_y, end_x, end_y);
            } else if (row_distance >= col_distance) {
                this->place_line_of_walls(
                    (TRIBE_Player*)this->player, master,
                    start_x, start_y, start_x, end_y);

                if (end_x > start_x) {
                    this->place_line_of_walls(
                        (TRIBE_Player*)this->player, master,
                        start_x + 1, end_y, end_x, end_y);
                    result = 1;
                } else if (start_x > end_x) {
                    this->place_line_of_walls(
                        (TRIBE_Player*)this->player, master,
                        start_x - 1, end_y, end_x, end_y);
                }
            } else {
                this->place_line_of_walls(
                    (TRIBE_Player*)this->player, master,
                    start_x, start_y, end_x, start_y);

                if (end_y > start_y) {
                    this->place_line_of_walls(
                        (TRIBE_Player*)this->player, master,
                        end_x, start_y + 1, end_x, end_y);
                    result = 1;
                } else if (start_y > end_y) {
                    this->place_line_of_walls(
                        (TRIBE_Player*)this->player, master,
                        end_x, start_y - 1, end_x, end_y);
                }
            }

            result = 1;
        }
        }
    } else {
        if (master_id != -1 &&
            ((TRIBE_Player*)this->player)->master_objects[master_id] != 0) {
            if (((TRIBE_Player*)this->player)->command_make_wall(
                    master_id, param_1, param_2, param_3, param_4) != 0)
                result = 1;
        }

        if (mode != 0)
            rge_base_game->set_game_mode(0, 0);
    }

    this->set_selection_area(-1, -1, -1, -1);
#ifdef TVW_MAIN_SHARED_CONTEXT
    this->set_redraw(1);
#else
    this->vf20(1);
#endif
    return result;
}
