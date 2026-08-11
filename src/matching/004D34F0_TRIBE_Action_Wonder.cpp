// TRIBE_Action_Wonder::~TRIBE_Action_Wonder
// VA: 004D34F0
// PDB: tact_wnd.cpp:50-97
//
// FLAGS: /GX
//
// Attempt log:
// - draft 1: standalone class, no base -> no EH/no base destructor call, 88.9%.
// - baseline: restored the RGE_Action base/EH surface and the action-object/state
//   ownership, but the decompiler-shaped raw locals left a 0x10 frame and 12
//   bytes of excess code.
// - hypothesis 2: use the same-TU typed action/world/player surfaces as set_state,
//   natural moving-player do-loops, and direct countdown/notification calls.
// - hypothesis 3: keep the original player array as a source local and use a
//   branch-local cursor for each state loop; the prior single cursor was
//   behaviorally wrong because state 6 started at the end of state 2's scan.

#include "../../include/game_globals.h"

class RGE_Player;
class RGE_Game_World;
class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Master_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Action_Node {
public:
    RGE_Action_Object* object;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    char gap_00[4];
    RGE_Action_Node* head;
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Action_List* action_list;
    char gap_2C[0x1E];
    short id;
};

class RGE_Game_World {
public:
    char gap_00[0x1D];
    unsigned char game_state;
    char gap_1E[0x1E];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0xC4];
    int countdown_active;
};

class RGE_Base_Game {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void notification(int command, long player_id, long x, long y, long zero);

    char gap_04[0x3F0];
    RGE_Game_World* world;

    void reset_countdown_timer(long player_id);
    void set_countdown_timer(long player_id, long timeout);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Action_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(RGE_Player* player, unsigned char mode, int value);
    virtual void vfDC(RGE_Player* player, unsigned char mode, int value);

    long id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    char gap_40[8];
    unsigned char object_state;
};

class TRIBE_Action_Wonder : public RGE_Action {
public:
    virtual ~TRIBE_Action_Wonder();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void set_state(unsigned char s);

    char gap_04[4];
    RGE_Action_Object* object;
    unsigned char state;
};

TRIBE_Action_Wonder::~TRIBE_Action_Wonder()
{
    RGE_Game_World* world = rge_base_game->world;

    if (world->game_state == 0) {
        RGE_Player** players = world->players;
        int player_num = (int)world->player_num;

        if (this->state == 2) {
            RGE_Player** current = players;
            int i = 1;
            if (1 < player_num) {
                ++current;
                do {
                    if (i != this->object->owner->id) {
                        this->object->vfDC(current[0], 1, -1);
                    }
                    ++i;
                    ++current;
                } while (i < player_num);
            }
        }

        if (this->state == 6) {
            RGE_Player** current = players;
            int i = 1;
            if (1 < player_num) {
                ++current;
                do {
                    if (i != this->object->owner->id) {
                        this->object->vfDC(current[0], 0, -1);
                    }
                    ++i;
                    ++current;
                } while (i < player_num);
            }

            if (rge_base_game->world->countdown_active == 0) {
                int found = 0;
                RGE_Action_Object* object = this->object;
                RGE_Player* owner = object->owner;
                RGE_Action_Node* node = owner->action_list->head;

                while (node != 0) {
                    RGE_Action_Object* action = node->object;
                    if (action != object) {
                        RGE_Master_Object* master = (RGE_Master_Object*)action->master_obj;
                        if (master->id == 0x114 && action->object_state >= 2) {
                            found = 1;
                            break;
                        }
                    }
                    node = node->next;
                }

                rge_base_game->reset_countdown_timer(owner->id);
                if (found) {
                    rge_base_game->set_countdown_timer(this->object->owner->id, 2000);
                }
            }
        }

        rge_base_game->notification(
            0x6E,
            this->object->owner->id,
            (long)this->object->world_x,
            (long)this->object->world_y,
            0);
    }
}
