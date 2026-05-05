// VA: 004C9B10 TRIBE_Building_Object::remove_from_production_queue(short, short)
// PDB source: t_b_obj.cpp lines 1047-1092 (355 bytes, 97 asm lines)
// Default flags
//
// __thiscall: this in ecx, 2 stack params (short master_id, short max_remove). ret 8 cleanup.
// Removes up to max_remove units of master_id from the production queue.
//
// Left in scratch: 352/355 bytes matching (3 bytes short, ~99%+ edit-equal).
//
// Differences are ALL stable VC5 version heuristics:
//
// 1. REGISTER ALLOCATION: Original uses ebx for the queue_count/index temporary,
//    this version uses ebp. This cascades throughout: test bx,bx vs test bp,bp,
//    movsx ecx,bx vs movsx ecx,bp, mov eax,ebx vs mov eax,ebp, etc.
//    The push/pop order also differs accordingly.
//
// 2. SEARCH LOOP CONTROL: Original uses `jge 004C9B36h` (loop back if >=0) +
//    `jmp 004C9C51h` (not found), 7 bytes. This version uses `jl 004C9C45h`
//    + `jmp short 004C9B36h`, 8 bytes (1 byte longer).
//
// 3. NEW_COUNT COMPARISON (3 byte diff): Original uses
//    `mov cx,[esi+1CEh]; cmp bx,cx` (9 bytes, register-register compare).
//    This version uses `cmp bp,[esi+1CEh]` (6 bytes, register-memory compare).
//    VC5 optimizes away the intermediate register load.
//
// Field layout (TRIBE_Building_Object):
//   owner_player               +0x0C (TRIBE_Player*)
//   production_queue            +0x1C8 (ProductionEntry*, 4-byte entries: {short id, short count})
//   <unknown 2-byte gap>       +0x1CC
//   production_queue_count      +0x1CE (short)
//   gap                        +0x1D0 (4 bytes to align pointer)
//   production_queue_actions    +0x1D4 (RGE_Action_List*)
//   production_queue_change_flag +0x1D8 (unsigned char)
//   production_queue_need_attr +0x1DA (short, -1 = none)
//
// Behavior:
//   1. if queue_count == 0, return
//   2. Search backwards from queue_count-1 for matching master_id
//   3. If found, reimburse up to max_remove units (clamped to unit_count)
//   4. Decrease unit_count by max_remove, increment change flag
//   5. If unit_count <= 0: decrement queue_count, shift entries left
//   6. If removed index 0 and need_attr != -1:
//      - If need_attr == 4: decrement game->array[player_id] at +0xA34
//      - Set need_attr = -1
//      - Stop and delete production_queue_actions
//   7. Call game->vf40(0x7C, player_id, 0, 0, 0)

struct ProductionEntry {
    short master_id;
    short unit_count;
};

struct TRIBE_Player {
    char gap_4A[0x4A];
    short player_id;
    void reimburse_obj_cost(short master_id);
};

struct RGE_Action_List {
    void action_stop();
    void delete_list();
};

struct RGE_Game {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40(int a, int b, int c, int d, int e);
};

struct TRIBE_Building_Object {
    char gap_00[0x0C];
    TRIBE_Player* owner_player;
    char gap_10[0x1C8 - 0x10];
    ProductionEntry* production_queue;
    short production_queue_gap;
    short production_queue_count;
    char gap_1D0[4];
    RGE_Action_List* production_queue_actions;
    unsigned char production_queue_change_flag;
    short production_queue_need_attr;

    void remove_from_production_queue(short master_id, short max_remove);
};

extern RGE_Game* rge_base_game;

void TRIBE_Building_Object::remove_from_production_queue(short master_id, short max_remove) {
    short idx = this->production_queue_count;
    if (idx != 0) {
        idx--;
        if (idx >= 0) {
            short orig_idx = idx;

            while (1) {
                if (this->production_queue[orig_idx].master_id == master_id) break;
                orig_idx--;
                if (orig_idx < 0) goto update_game;
            }

            {
                int count = (int)(short)max_remove;
                if (this->production_queue[orig_idx].unit_count <= max_remove) {
                    count = (int)(short)this->production_queue[orig_idx].unit_count;
                }

                if (count > 0) {
                    do {
                        this->owner_player->reimburse_obj_cost(master_id);
                        count--;
                    } while (count != 0);
                }

                this->production_queue[orig_idx].unit_count -= max_remove;
                this->production_queue_change_flag++;

                if (this->production_queue[orig_idx].unit_count <= 0) {
                    this->production_queue_count--;
                    short new_count = this->production_queue_count;
                    short loop_limit = new_count;
                    if (orig_idx < loop_limit) {
                        short i = orig_idx;
                        do {
                            this->production_queue[i].master_id = this->production_queue[i + 1].master_id;
                            this->production_queue[i].unit_count = this->production_queue[i + 1].unit_count;
                            i++;
                        } while (i < this->production_queue_count);
                    }

                    if (orig_idx == 0) {
                        short need_attr = this->production_queue_need_attr;
                        if (need_attr != -1) {
                            if (need_attr == 4) {
                                int pid = (int)(short)this->owner_player->player_id;
                                ((int*)((char*)rge_base_game + 0xA34))[pid]--;
                            }
                            this->production_queue_need_attr = -1;
                        }
                        this->production_queue_actions->action_stop();
                        this->production_queue_actions->delete_list();
                    }
                }
            }
        }
update_game:;
        int pid = (int)(short)this->owner_player->player_id;
        rge_base_game->vf40(0x7C, pid, 0, 0, 0);
    }
}
