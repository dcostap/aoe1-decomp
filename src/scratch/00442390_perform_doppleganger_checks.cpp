// VA: 00442390 RGE_Doppleganger_Creator::perform_doppleganger_checks
// dpl_obj.cpp lines 628-677
// Attempt log:
// 1: natural structured source based on packet/decompiler and sibling add_doppleganger_check types: 416 B, frame 0x18 not original 0x14, index in EBP not EDI; broad branch/register drift.
// 2: explicit for loop/no `last` local matched configured size but worsened badly: positional 67.5294%, edit 100.7059%, first mismatch offset 2; rolled back.
// 3: flags /O2 no-/Oy, /Ox, /GX unchanged; /O1 too short (410 B).
// 4: volatile remove_me: no size/codegen improvement.
// 5: volatile map_value: no size/codegen improvement.
// 6: signed int map values/mask: no size improvement.
// 7: register mask/player_id: no codegen/size improvement.
// 8: while(mask) loop instead of if+do/while: no size improvement.
// 9: nonzero low-bit test instead of ==1 shortened to 400 B, worse; rolled back.
// 10: pointer locals for Objects/Map_Addresses/Last_Map_Value matched configured size but was very broad drift (87.7647% positional), first mismatch 2; rolled back.
// Left in scratch: behavior/call surface modeled, but standalone VC5 chooses different local frame/register topology and shorter section. Not accepted_drift-safe.

#include <stdio.h>

class RGE_Static_Object;

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
    void* vtable;
    unsigned long world_time;
    char gap_08[0x38];
    void** players; // +0x40
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    void* vtable;
    char gap_04[0x20];
    RGE_Master_Object** master_objects; // +0x24
    char gap_28[0x14];
    RGE_Game_World* world; // +0x3C
    char gap_40[0x0A];
    short id; // +0x4A
};

class RGE_Static_Object {
public:
    void* vtable;
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
    RGE_Static_Object* remove_me = 0;

    if (this->active_size > 0) {
        int i = 0;
        if (this->active_size > 0) {
            do {
                unsigned long map_value = *this->Map_Addresses[i];
                unsigned long last = this->Last_Map_Value[i];
                if (map_value != last) {
                    RGE_Static_Object* obj = this->Objects[i];
                    if (obj == 0 || this->owner->world->object(this->Object_ids[i]) != obj) {
                        remove_me = obj;
                        if (DDlogf) {
                            fprintf(DDlogf, "*** REMOVE CHECK (@%d) by p=%d id=%d\n",
                                this->owner->world->world_time,
                                (int)this->owner->id,
                                this->Object_ids[i]);
                        }
                    } else {
                        unsigned long mask = ((map_value ^ last) >> 1) & (last >> 1) & 0x7fff;
                        if (mask != 0) {
                            int player_id = 1;
                            do {
                                if ((mask & 1) == 1) {
                                    int owner_id = (int)this->owner->id;
                                    if (player_id != owner_id) {
                                        if (DDlogf) {
                                            obj = this->Objects[i];
                                            fprintf(DDlogf, "NEW DOP (@%d) by p=%d for p=%d of id=%d (x=%d, y=%d)\n",
                                                this->owner->world->world_time,
                                                owner_id,
                                                player_id,
                                                obj->id,
                                                (long)obj->world_x,
                                                (long)obj->world_y);
                                        }
                                        RGE_Player* player = (RGE_Player*)this->owner->world->players[player_id];
                                        obj = this->Objects[i];
                                        player->master_objects[0xf3]->create_doppleganger(player, obj->world_x, obj->world_y, obj->world_z, obj);
                                    }
                                }
                                player_id++;
                                mask >>= 1;
                            } while (mask != 0);
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
}
