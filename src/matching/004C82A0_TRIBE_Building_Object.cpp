// VA: 004C82A0 TRIBE_Building_Object::~TRIBE_Building_Object
// PDB source: t_b_obj.cpp:129-151
// Baseline: period-plausible derived destructor with the production queue and
// action-list ownership shown by the executable.
// Attempt log:
// - Natural virtual action-list destruction emitted an indirect call; the
//   qualified derived destructor call below preserves the observed direct
//   RGE_Action_List::~RGE_Action_List call at 00403EC0.

#include "../../include/t_b_obj_context.h"

TRIBE_Building_Object::~TRIBE_Building_Object()
{
    this->world->creator->remove_doppleganger_check(this);

    RGE_Action_List* actions = this->production_queue_actions;
    if (actions != 0) {
        actions->RGE_Action_List::~RGE_Action_List();
        operator delete(actions);
        this->production_queue_actions = 0;
    }

    if (this->production_queue != 0) {
        free(this->production_queue);
        this->production_queue = 0;
        if (this->production_queue_need_attr == 4) {
            this->production_queue_need_attr = -1;
            TRIBE_Game* game = rge_base_game;
            int map_id = (int)(short)this->world->map_id;
            long* count = &game->queue_is_waiting_on_pop_counter[map_id];
            *count = *count - 1;
        }
    }
}
