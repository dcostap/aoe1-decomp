// TRIBE_Action_Make_Tech::update
// VA: 004D2450
// PDB: tact_tek.cpp:109-134
// No EH framing (push ecx creates a local slot)
// tried fixing local RGE_Action_Object layout to vptr/player_id/field_08/obj_ptr and removed fake base virtual dtor; vfn23 slot and object offsets now align better
// tried natural RGE_Base_Game member-call surface instead of cdecl function-pointer notify; removed caller stack cleanup drift in notify block
// current gap: status dispatch and several success-path blocks still have shifted layout/register drift; edit diff improved but not exact
// tried low-level state--/state-=5 spelling and result-variable form; result form worsened by introducing BL as carrier
// fixed success-path object model: after vfn23 the original uses EDI=this->action_obj, loads float x/y from action_obj+3c/+38, then uses action_obj->obj_ptr for scenario calls
// tried top-declared locals plus gotos to force original shared fail/success tails; it moved fail tail later but VC5 still emits add/test for state-5 and success block remains shifted

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
    virtual void vfn82(int, int, int, int, int, int);

    int player_id;
    void* field_08;  // +0x08
    void* obj_ptr;   // +0x0C
};

class TRIBE_Player_Tech {
public:
    unsigned char research(short tech_id, float value);
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
    virtual void vfn70(int, int, int, int); // slot 70, offset 0x118
    virtual void vfn71(int, int, int); // slot 71, offset 0x11C
};

class RGE_Action {
public:
    V_DUMMY(0); V_DUMMY(1); V_DUMMY(2); V_DUMMY(3); V_DUMMY(4);
    V_DUMMY(5); V_DUMMY(6); V_DUMMY(7); V_DUMMY(8); V_DUMMY(9);
    V_DUMMY(10); V_DUMMY(11); V_DUMMY(12); V_DUMMY(13); V_DUMMY(14);
    V_DUMMY(15); V_DUMMY(16); V_DUMMY(17); V_DUMMY(18); V_DUMMY(19);
    V_DUMMY(20); V_DUMMY(21); V_DUMMY(22);
    virtual void vfn23(int);

    char gap_04[4];
    RGE_Action_Object* action_obj;
    unsigned char status;
    char pad_0D[0x40 - 0x0D];
    short tech_id;
    char pad_42[2];
    int unique_id;
};

class RGE_Base_Game {
public:
    V_DUMMY(0); V_DUMMY(1); V_DUMMY(2); V_DUMMY(3); V_DUMMY(4);
    V_DUMMY(5); V_DUMMY(6); V_DUMMY(7); V_DUMMY(8); V_DUMMY(9);
    V_DUMMY(10); V_DUMMY(11); V_DUMMY(12); V_DUMMY(13); V_DUMMY(14); V_DUMMY(15);
    virtual void vfn16(int, int, int, int, int);
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    unsigned char update();
};

unsigned char TRIBE_Action_Make_Tech::update()
{
    switch ((int)this->status) {
    case 1:
        goto success_initial;
    case 6:
        {
            float val;
            void* some_obj = *(void**)((char*)rge_base_game + 0x9A8);
            if (some_obj) {
                val = 1000.0f;
            } else {
                void* scn = this->action_obj->obj_ptr;
                float* p1 = *(float**)((char*)scn + 0x3C);
                void* fb = this->action_obj->field_08;
                val = p1[0x84/4] * *(float*)((char*)fb + 0xE4);
            }

            TRIBE_Player_Tech* pt = *(TRIBE_Player_Tech**)((char*)this->action_obj->obj_ptr + 0x220);
            if (!pt->research(this->tech_id, val)) {
                this->vfn23(1);

                RGE_Action_Object* action_obj = this->action_obj;
                RGE_Base_Game* base_game = (RGE_Base_Game*)rge_base_game;
                float f1 = *(float*)((char*)action_obj + 0x3C);
                float f2 = *(float*)((char*)action_obj + 0x38);

                base_game->vfn16(
                    0x64,
                    *(short*)((char*)action_obj->obj_ptr + 0x4A), this->tech_id,
                    (int)f2, (int)f1);

                ((RGE_Scenario*)this->action_obj->obj_ptr)->vfn71((int)this->tech_id, this->action_obj->player_id, this->unique_id);

                this->action_obj->vfn82(
                    this->action_obj->player_id, this->action_obj->player_id,
                    0x1FA, 0x26C, 0, 0);

                return 1;
            }
        }
        goto fail;
    }

fail:
    return 0;

success_initial:
    return 1;
}
