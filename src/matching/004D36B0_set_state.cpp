// TRIBE_Action_Wonder::set_state
// VA: 004D36B0
// PDB: tact_wnd.cpp:108-148
//
// Attempt log:
// - prior drafts used raw offset/function-pointer scaffolding and did not compile
//   against the local global surface; this is the clean typed baseline.
// - baseline hypothesis: period-style switch with case 6 first, a moving player
//   pointer, the real action-object virtual slots, and the base-game notification
//   slot.  The inherited action fields are kept at their proven offsets.
// - widened the local player bound to int after the oracle's early word movsx;
//   correcting RGE_Base_Game's polymorphic gap placed world at +0x3F4.
// - direct world expressions and declaration-order/ABI variants were unchanged;
//   a player temporary regressed the loop basin and was rolled back.
// - exact: advancing players once before the do-loop and again after incrementing
//   i recovered the oracle's add/inc/compare topology and all 345 bytes.

#include "../../include/game_globals.h"

class RGE_Player;
class RGE_Game_World;

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
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

void TRIBE_Action_Wonder::set_state(unsigned char param_1)
{
    this->state = param_1;

    switch (param_1) {
    case 6: {
        int player_num = (int)rge_base_game->world->player_num;
        RGE_Player** players = rge_base_game->world->players;
        int i = 1;

        if (1 < player_num) {
            ++players;
            do {
                if (i != this->object->owner->id) {
                    this->object->vfDC(players[0], 1, -1);
                    this->object->vfD8(players[0], 0, -1);
                }
                ++i;
                ++players;
            } while (i < player_num);
        }

        if (rge_base_game->world->countdown_active == 0) {
            rge_base_game->set_countdown_timer(this->object->owner->id, 2000);
        }

        rge_base_game->notification(
            0x6D,
            this->object->owner->id,
            (long)this->object->world_x,
            (long)this->object->world_y,
            0);
        return;
    }

    case 2: {
        int player_num = (int)rge_base_game->world->player_num;
        RGE_Player** players = rge_base_game->world->players;
        int i = 1;

        if (1 < player_num) {
            ++players;
            do {
                if (i != this->object->owner->id) {
                    this->object->vfD8(players[0], 1, -1);
                }
                ++i;
                ++players;
            } while (i < player_num);
        }

        rge_base_game->notification(
            0x6C,
            this->object->owner->id,
            (long)this->object->world_x,
            (long)this->object->world_y,
            0);
        return;
    }

    default:
        return;
    }
}
