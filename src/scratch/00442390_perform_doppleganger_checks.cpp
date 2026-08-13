// VA: 00442390 RGE_Doppleganger_Creator::perform_doppleganger_checks
// dpl_obj.cpp lines 628-677
// Attempt log:
// - Prior matching work established the typed array/object/world/player surface,
//   the seven-call behavior, and the default /O2 /Oy context. The current clean
//   source uses one ordinary scan index, one map-value local, and a persistent
//   object/remove pointer pair; it remains period-plausible and contains no raw
//   cursor, manual vtable, volatility, or register-forcing alias.
// - Removing the cached last-map local and restoring direct Last_Map_Value reads
//   improved the structural basin but did not recover the original frame.
// - Positive valid-object spelling, commutative mask operand order, explicit
//   goto labels, register-local index, and a diagnostic byte-index pointer were
//   tested. The goto/pointer forms were rolled back; the emitted best remains
//   407 bytes versus the original 425, with frame 0x18 versus 0x14, the index
//   colored EBP rather than EDI, and the cold remove-log block laid out inline.
// - Left in scratch: call behavior is modeled but the remaining frame/block/
//   register topology is unresolved; do not promote as accepted drift.
// - Natural negative invalid-object guard spelling was codegen-identical; the
//   remove-log fprintf remains an out-of-order cold call before the remove call.
// - Declaring the persistent remove candidate before scan locals, as the
//   packet's line 632 zeroing precedes the line 634 active-size test, produced
//   identical code; the structural frame and first hunk remain unresolved.
// - A shared cold remove block was a structural diagnostic only. The living
//   source uses an ordinary invalid-object branch.
// - Reusing map_value as the shifted mask reached the original frame, but it
//   saved the shifted mask instead of the observed map value; rolled back.
// - Removing the artificial object local improved source ownership but left a
//   larger frame; the natural mask for-loop restored frame 0x14 and gave EDI
//   the scan index and EBP the mask, with diff 381; it remains the best clean
//   reconstruction.
// - Hoisting mask and reordering locals were codegen duplicates; kept the
//   simpler inner mask declaration.

#include <stdio.h>

class RGE_Static_Object;
class RGE_Player;

class RGE_Master_Object {
public:
#define MPAD(n) virtual void m##n();
    MPAD(0) MPAD(1) MPAD(2) MPAD(3) MPAD(4) MPAD(5) MPAD(6) MPAD(7)
    MPAD(8) MPAD(9) MPAD(10) MPAD(11) MPAD(12) MPAD(13)
#undef MPAD
    virtual void create_doppleganger(void* player, float x, float y, float z, RGE_Static_Object* obj); // +0x38
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    char gap_08[0x38];
    RGE_Player** players; // +0x40
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Object** master_objects; // +0x24
    char gap_28[0x14];
    RGE_Game_World* world; // +0x3C
    char gap_40[0x0A];
    short id; // +0x4A
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    char gap_08[0x30];
    float world_x; // +0x38
    float world_y; // +0x3C
    float world_z; // +0x40
};

class RGE_Doppleganger_Creator {
public:
    RGE_Player* owner;
    int allocated_size;
    int active_size;
    RGE_Static_Object** Objects;
    unsigned long** Map_Addresses;
    unsigned long* Last_Map_Value;
    int* Object_ids;

    void remove_doppleganger_check(RGE_Static_Object* obj);
    void perform_doppleganger_checks();
};

extern FILE* DDlogf;

void RGE_Doppleganger_Creator::perform_doppleganger_checks()
{
    unsigned long map_value;
    int i;
    RGE_Static_Object* remove_me = 0;

    if (this->active_size > 0) {
        i = 0;
        if (this->active_size > 0) {
            do {
                map_value = *this->Map_Addresses[i];
                if (map_value != this->Last_Map_Value[i]) {
                    if (this->Objects[i] != 0 &&
                        this->owner->world->object(this->Object_ids[i]) == this->Objects[i]) {
                        unsigned long mask = ((this->Last_Map_Value[i] ^ map_value) >> 1) &
                            (this->Last_Map_Value[i] >> 1) & 0x7fff;
                        for (int player_id = 1; mask != 0; player_id++, mask >>= 1) {
                            if ((mask & 1) == 1) {
                                    int owner_id = (int)this->owner->id;
                                    if (player_id != owner_id) {
                                        if (DDlogf) {
                                            fprintf(DDlogf, "NEW DOP (@%d) by p=%d for p=%d of id=%d (x=%d, y=%d)\n",
                                                this->owner->world->world_time,
                                                owner_id,
                                                player_id,
                                                this->Objects[i]->id,
                                                (long)this->Objects[i]->world_x,
                                                (long)this->Objects[i]->world_y);
                                        }
                                        RGE_Player* player = (RGE_Player*)this->owner->world->players[player_id];
                                        player->master_objects[0xf3]->create_doppleganger(player,
                                            this->Objects[i]->world_x,
                                            this->Objects[i]->world_y,
                                            this->Objects[i]->world_z,
                                            this->Objects[i]);
                                    }
                                }
                        }
                    } else {
                        remove_me = this->Objects[i];
                        if (DDlogf) {
                            fprintf(DDlogf, "*** REMOVE CHECK (@%d) by p=%d id=%d\n",
                                this->owner->world->world_time,
                                (int)this->owner->id,
                                this->Object_ids[i]);
                        }
                    }
                    this->Last_Map_Value[i] = map_value;
                }
                i++;
            } while (i < this->active_size);
        }
        if (remove_me != 0) {
            this->remove_doppleganger_check(remove_me);
        }
    }

    return;
}
