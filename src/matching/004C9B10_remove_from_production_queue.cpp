// VA: 004C9B10 TRIBE_Building_Object::remove_from_production_queue(short, short)
// PDB source: t_b_obj.cpp lines 1047-1092 (355 bytes, 97 asm lines)
// Default flags
//
// __thiscall: this in ecx, 2 stack params (short master_id, short max_remove). ret 8 cleanup.
// Removes up to max_remove units of master_id from the production queue.
//
// The natural single-index form with top-declared locals recovers the original
// EBX index, EDI record stride, EBP reimbursement countdown, frame, calls, and
// queue ownership. It is now an exact default-flag reconstruction.
//
// Attempt log:
// - Replaced the two-index decompiler-shaped search with one named queue index
//   plus an int reimbursement count and copy index; this restored the original
//   saved-register coloring and substantially improved CFG/size parity.
// - Tried positive continuation, do/while, and labeled-search spellings for the
//   jge-back/jmp-final search topology; all were worse or introduced extra
//   blocks, so the ordinary while form remains the living source.
// - Recovered the proven RGE_Base_Game virtual surface and named counter field;
//   raw save_music_file pointer arithmetic was rejected as noncanonical.
// - A natural while(index >= 0) match-arm with break reproduced the oracle's
//   jge-back search and shared notification tail.
// - Restored the typed game-global counter array and notification surface.
//   Exact after validation; no pointer cursor or register-forcing scaffold.
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
//      - If need_attr == 4: decrement the named game counter at +0xA34
//      - Set need_attr = -1
//      - Stop and delete production_queue_actions
//   7. Call the RGE_Base_Game notification slot with (0x7C, player_id, 0, 0, 0)
// Main-agent audit restored canonical polymorphic player/game/building ownership
// and retained the natural indexed queue search/copy.

struct ProductionEntry {
    short master_id;
    short unit_count;
};

struct TRIBE_Player {
    virtual ~TRIBE_Player();
    char gap_04[0x46];
    short player_id;
    void reimburse_obj_cost(short master_id);
};

struct RGE_Action_List {
    void action_stop();
    void delete_list();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
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
    virtual void notification(int a, long b, long c, long d, long e);
    char gap_44[0xA30];
    long queue_is_waiting_on_pop_counter[9]; // +0xA34
};

struct TRIBE_Building_Object {
    virtual ~TRIBE_Building_Object();
    char gap_04[0x08];
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

extern RGE_Base_Game* rge_base_game;

void TRIBE_Building_Object::remove_from_production_queue(short master_id, short max_remove) {
    int remove_count;
    short index;
    short copy_index;

    index = this->production_queue_count;
    if (index != 0) {
        index--;
        while (index >= 0) {
            if (this->production_queue[index].master_id == master_id) {
                remove_count = max_remove;
                if (this->production_queue[index].unit_count <= max_remove) {
                    remove_count = this->production_queue[index].unit_count;
                }

                if (remove_count > 0) {
                    do {
                        this->owner_player->reimburse_obj_cost(master_id);
                        remove_count--;
                    } while (remove_count != 0);
                }

                this->production_queue[index].unit_count -= max_remove;
                this->production_queue_change_flag++;

                if (this->production_queue[index].unit_count <= 0) {
                    this->production_queue_count--;
                    copy_index = index;
                    if (index < this->production_queue_count) {
                        do {
                            this->production_queue[copy_index].master_id =
                                this->production_queue[copy_index + 1].master_id;
                            this->production_queue[copy_index].unit_count =
                                this->production_queue[copy_index + 1].unit_count;
                            copy_index++;
                        } while (copy_index < this->production_queue_count);
                    }

                    if (index == 0) {
                        if (this->production_queue_need_attr != -1) {
                            if (this->production_queue_need_attr == 4) {
                                int pid = (int)(short)this->owner_player->player_id;
                                long* counter =
                                    &rge_base_game->queue_is_waiting_on_pop_counter[pid];
                                long old_counter = *counter;
                                long new_counter = old_counter - 1;
                                *counter = new_counter;
                            }
                            this->production_queue_need_attr = -1;
                        }
                        this->production_queue_actions->action_stop();
                        this->production_queue_actions->delete_list();
                    }
                }
                break;
            }
            index--;
        }

        int pid = (int)(short)this->owner_player->player_id;
        rge_base_game->notification(0x7C, pid, 0, 0, 0);
    }
}
