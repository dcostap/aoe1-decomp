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

#ifndef T_B_OBJ_CONTEXT_H
struct TRIBE_Player {
    char gap_4A[0x4A];
    short player_id;
};

struct RGE_Action_List {
    void delete_list();
};

struct TRIBE_Building_Object {
    char gap_00[0x0C];
    TRIBE_Player* owner_player;                    // +0x0C
    char gap_10[0x1C8 - 0x10];
    void* production_queue;                        // +0x1C8
    short production_queue_gap;                    // +0x1CC
    short production_queue_count;                  // +0x1CE
    char gap_1D0[4];
    RGE_Action_List* production_queue_actions;      // +0x1D4
    unsigned char production_queue_change_flag;      // +0x1D8
    short production_queue_need_attr;              // +0x1DA

    void empty_production_queue();
};
#endif

#ifndef T_B_OBJ_CONTEXT_H
extern char* rge_base_game;  // 0x62C574
#endif

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
