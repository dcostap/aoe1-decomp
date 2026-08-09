// VA: 004C50F0 RGE_Static_Object::remove_visible_resource
// PDB source: stat_obj.cpp:2605-2659
// Attempt log:
// - baseline: natural typed reconstruction using the matching
//   create_doppleganger_when_dying source shape, canonical map/player/master
//   ownership, and the two binary-observed resource/doppleganger calls.
// - declaration/liveness probes: swapped mask/explored declarations,
//   separated assignments, mutating the full map word, split copies, and
//   low-mask-first expressions. The mutating full-word form was the best
//   natural emitted basin (182 positional bytes differing; size/calls/frame
//   aligned), but the original keeps explored in EBP while the low mask is
//   the stack-reloaded value in EBX.
// - control-flow probe: direct nonzero explored-bit testing moved away from
//   the original `and/cmp` shape; restored the equality form.
// - variant lab: 180 focused map/bit-test/player-surface variants; no exact
//   result. Best eligible group remained a localized map/liveness mismatch.
// - final: retained the best period-plausible full-word mutation source;
//   unresolved VC5 register/stack coloring remains in scratch.
// - Main-agent audit restored canonical destructor slots, symbol-backed map
//   ownership, and natural player-array indexing. The validated 182-byte gap
//   remains, without raw absolute addresses or byte-indexed player plumbing.

typedef unsigned long ulong;

extern ulong* DAT_00886808[];
#define unified_map_offsets DAT_00886808

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;

class Visible_Resource_Manager {
public:
    int Remove_Resource(int object_id, int type);
};

class RGE_Doppleganger_Creator {
public:
    int remove_doppleganger_check(RGE_Static_Object* object);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float location_x,
                                            float location_y, float location_z,
                                            RGE_Static_Object* object);
    char gap_04[0xA5 - 0x04];
    unsigned char track_as_resource;             // +0xA5
    unsigned char create_doppleganger_on_death;  // +0xA6
    unsigned char resource_group;                // +0xA7
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x3C];
    RGE_Player** players;                        // +0x40
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;    // +0x24
    char gap_28[0x3C - 0x28];
    RGE_Game_World* world;                        // +0x3C
    RGE_Doppleganger_Creator* doppleganger_creator;// +0x40
    char gap_44[0x110 - 0x44];
    Visible_Resource_Manager* VR_List;            // +0x110
};

class RGE_Static_Object {
public:
#define STATIC_PAD(n) virtual void static_pad##n();
    virtual ~RGE_Static_Object();
    STATIC_PAD(1) STATIC_PAD(2) STATIC_PAD(3) STATIC_PAD(4) STATIC_PAD(5)
    STATIC_PAD(6) STATIC_PAD(7) STATIC_PAD(8) STATIC_PAD(9) STATIC_PAD(10)
    STATIC_PAD(11) STATIC_PAD(12) STATIC_PAD(13) STATIC_PAD(14) STATIC_PAD(15)
    STATIC_PAD(16) STATIC_PAD(17) STATIC_PAD(18) STATIC_PAD(19) STATIC_PAD(20)
    STATIC_PAD(21) STATIC_PAD(22) STATIC_PAD(23)
    virtual void remove_visible_resource();
#undef STATIC_PAD

    long id;                                      // +0x04
    RGE_Master_Static_Object* master_obj;         // +0x08
    RGE_Player* owner;                            // +0x0C
    char gap_10[0x38 - 0x10];
    float world_x;                                // +0x38
    float world_y;                                // +0x3C
    float world_z;                                // +0x40
};

void RGE_Static_Object::remove_visible_resource() {
    if (this->id >= 0 && this->owner != 0 && this->master_obj != 0 &&
        (this->master_obj->create_doppleganger_on_death != 0 ||
         this->master_obj->track_as_resource != 0)) {
        ulong explored = unified_map_offsets[(int)this->world_y][(int)this->world_x];
        ulong mask = explored & 0xFFFF;
        explored >>= 16;
        if (explored > 0) {
            int player_index = 0;
            do {
                if ((explored & 1) == 1) {
                    if (this->master_obj->track_as_resource != 0) {
                        RGE_Player* player = this->owner->world->players[player_index];
                        player->VR_List->Remove_Resource(
                            this->id, this->master_obj->resource_group);
                    }
                    if (this->master_obj->create_doppleganger_on_death == 1 &&
                        (mask & 1) == 0 && player_index > 0) {
                        RGE_Player* player = this->owner->world->players[player_index];
                        player->master_objects[243]->make_new_obj(
                            player, this->world_x, this->world_y, this->world_z, this);
                    }
                }
                player_index++;
                mask >>= 1;
                explored >>= 1;
            } while (explored != 0);
        }
        if (this->master_obj->create_doppleganger_on_death == 2) {
            this->owner->doppleganger_creator->remove_doppleganger_check(this);
        }
    }
}
