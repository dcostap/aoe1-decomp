// VA: 004C9D20 TRIBE_Building_Object::empty_production_queue()
// PDB source: t_b_obj.cpp lines 1119-1131 (97 bytes, 23 asm lines)
// Default flags
// Exact match.
// Attempts:
// - Initial scratch with `extern void* rge_base_game` and `(char*)game + pid*4 + off` was behaviorally correct
//   but one byte short / wrong register family around the global table decrement. VC5 used `a1`/shorter global
//   load or different base/index registers, shifting the branches.
// - Tried volatile pointer, reordered pid/game/pointer/old locals, player local, and function-scope locals; all
//   stayed in the same near-miss family.
// - Winning shape: declare the global table base as `extern char* rge_base_game` and index it directly
//   (`(int*)(rge_base_game + pid * 4 + 0xA34)`). This makes VC5 load the global into EDX and materialize
//   the LEA + load + dec + store sequence exactly instead of the shorter/shifted forms.

#include "../../include/t_b_obj_context.h"

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::empty_production_queue() {
    short need_attr = this->production_queue_need_attr;
    if (need_attr != -1) {
        if (need_attr == 4) {
            int pid = (int)(short)this->owner_player->player_id;
            int* val_p = (int*)(rge_base_game + pid * 4 + 0xA34);
            int old = *val_p;
            int result = old - 1;
            *val_p = result;
        }
        this->production_queue_need_attr = -1;
    }

    this->production_queue_count = 0;
    this->production_queue_actions->delete_list();
    this->production_queue_change_flag++;
}
