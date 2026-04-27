// TRIBE_Action_Make_Tech::stop
// VA: 004D2550
// PDB: tact_tek.cpp:138-147
// No EH framing

#include "../../include/game_globals.h"

#define V_DUMMY(N) virtual void d##N()

class RGE_Action_Object {
public:
    V_DUMMY(0); V_DUMMY(1); V_DUMMY(2); V_DUMMY(3); V_DUMMY(4);
    V_DUMMY(5); V_DUMMY(6); V_DUMMY(7); V_DUMMY(8); V_DUMMY(9);
    V_DUMMY(10); V_DUMMY(11); V_DUMMY(12); V_DUMMY(13); V_DUMMY(14);
    V_DUMMY(15); V_DUMMY(16); V_DUMMY(17); V_DUMMY(18); V_DUMMY(19);
    V_DUMMY(20); V_DUMMY(21); V_DUMMY(22); V_DUMMY(23); V_DUMMY(24);
    V_DUMMY(25); V_DUMMY(26); V_DUMMY(27); V_DUMMY(28); V_DUMMY(29);
    V_DUMMY(30); V_DUMMY(31); V_DUMMY(32); V_DUMMY(33); V_DUMMY(34);
    V_DUMMY(35); V_DUMMY(36); V_DUMMY(37); V_DUMMY(38); V_DUMMY(39);
    V_DUMMY(40); V_DUMMY(41); V_DUMMY(42); V_DUMMY(43); V_DUMMY(44);
    V_DUMMY(45); V_DUMMY(46); V_DUMMY(47); V_DUMMY(48); V_DUMMY(49);
    V_DUMMY(50); V_DUMMY(51); V_DUMMY(52); V_DUMMY(53); V_DUMMY(54);
    V_DUMMY(55); V_DUMMY(56); V_DUMMY(57); V_DUMMY(58); V_DUMMY(59);
    V_DUMMY(60); V_DUMMY(61); V_DUMMY(62); V_DUMMY(63); V_DUMMY(64);
    V_DUMMY(65); V_DUMMY(66); V_DUMMY(67); V_DUMMY(68); V_DUMMY(69);
    V_DUMMY(70); V_DUMMY(71); V_DUMMY(72); V_DUMMY(73); V_DUMMY(74);
    V_DUMMY(75); V_DUMMY(76); V_DUMMY(77); V_DUMMY(78); V_DUMMY(79);
    V_DUMMY(80); V_DUMMY(81);
    virtual void vfn82(int, int, int, int, int, int); // slot 82

    char gap_00[4];
    int player_id;
    char gap_08[4];
    void* obj_ptr;
};

class TRIBE_Player_Tech {
public:
    void cancel_research(short tech_id, int flag);
};

class RGE_Scenario {
public:
    V_DUMMY(0); V_DUMMY(1); V_DUMMY(2); V_DUMMY(3); V_DUMMY(4);
    V_DUMMY(5); V_DUMMY(6); V_DUMMY(7); V_DUMMY(8); V_DUMMY(9);
    V_DUMMY(10); V_DUMMY(11); V_DUMMY(12); V_DUMMY(13); V_DUMMY(14);
    V_DUMMY(15); V_DUMMY(16); V_DUMMY(17); V_DUMMY(18); V_DUMMY(19);
    V_DUMMY(20); V_DUMMY(21); V_DUMMY(22); V_DUMMY(23); V_DUMMY(24);
    V_DUMMY(25); V_DUMMY(26); V_DUMMY(27); V_DUMMY(28); V_DUMMY(29);
    V_DUMMY(30); V_DUMMY(31); V_DUMMY(32); V_DUMMY(33); V_DUMMY(34);
    V_DUMMY(35); V_DUMMY(36); V_DUMMY(37); V_DUMMY(38); V_DUMMY(39);
    V_DUMMY(40); V_DUMMY(41); V_DUMMY(42); V_DUMMY(43); V_DUMMY(44);
    V_DUMMY(45); V_DUMMY(46); V_DUMMY(47); V_DUMMY(48); V_DUMMY(49);
    V_DUMMY(50); V_DUMMY(51); V_DUMMY(52); V_DUMMY(53); V_DUMMY(54);
    V_DUMMY(55); V_DUMMY(56); V_DUMMY(57); V_DUMMY(58); V_DUMMY(59);
    V_DUMMY(60); V_DUMMY(61); V_DUMMY(62); V_DUMMY(63); V_DUMMY(64);
    V_DUMMY(65); V_DUMMY(66); V_DUMMY(67); V_DUMMY(68); V_DUMMY(69);
    virtual void vfn70(int, int, int, int); // slot 70
};

class RGE_Action {
public:
    V_DUMMY(0); V_DUMMY(1); V_DUMMY(2); V_DUMMY(3); V_DUMMY(4);
    V_DUMMY(5); V_DUMMY(6); V_DUMMY(7); V_DUMMY(8); V_DUMMY(9);
    V_DUMMY(10); V_DUMMY(11); V_DUMMY(12); V_DUMMY(13); V_DUMMY(14);
    V_DUMMY(15); V_DUMMY(16); V_DUMMY(17); V_DUMMY(18); V_DUMMY(19);
    V_DUMMY(20); V_DUMMY(21); V_DUMMY(22);
    virtual void vfn23(int); // slot 23

    char gap_04[4];
    RGE_Action_Object* action_obj;  // +0x08
    unsigned char status;           // +0x0C
    char pad_0D[0x40 - 0x0D];
    short tech_id;                  // +0x40
    char pad_42[2];
    int unique_id;                  // +0x44

    RGE_Action(int param_1, void* param_2, int flag);
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    int stop();
};

// RGE_Base_Game fragment with needed vtable slot
// Slot 16 (offset 0x40) — notification-like function

int TRIBE_Action_Make_Tech::stop()
{
    this->vfn23(1);

    RGE_Scenario* scenario = (RGE_Scenario*)this->action_obj->obj_ptr;
    TRIBE_Player_Tech* pt = *(TRIBE_Player_Tech**)((char*)scenario + 0x220);
    pt->cancel_research(this->tech_id, 1);

    // rge_base_game vtable[0x40] — slot 16
    typedef void (*NotifyFn)(void*, int, int, int, int, int);
    ((NotifyFn)((*(void***)rge_base_game)[0x40/4]))(
        rge_base_game, 0x65, *(short*)((char*)scenario + 0x4A),
        this->tech_id, 0, 0);

    scenario->vfn70((int)this->tech_id, this->action_obj->player_id, -1, this->unique_id);

    this->action_obj->vfn82(
        this->action_obj->player_id, this->action_obj->player_id,
        0x1F9, 0x26C, 0, 0);

    return 1;
}
