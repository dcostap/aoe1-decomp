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
#include "../../include/tact_tek_context.h"

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
                this->set_state(1);

                RGE_Action_Object* action_obj = this->action_obj;
                RGE_Base_Game* base_game = (RGE_Base_Game*)rge_base_game;
                float f1 = *(float*)((char*)action_obj + 0x3C);
                float f2 = *(float*)((char*)action_obj + 0x38);

                base_game->notification(
                    0x64,
                    *(short*)((char*)action_obj->obj_ptr + 0x4A), this->tech_id,
                    (int)f2, (int)f1);

                ((TRIBE_Player*)this->action_obj->obj_ptr)->registerResearch((int)this->tech_id, this->action_obj->player_id, this->unique_id);

                this->action_obj->notify(
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
