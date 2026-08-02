// VA: 004C5210 RGE_Static_Object::create_doppleganger_when_dying
// PDB source: stat_obj.cpp:2663-2699
// Attempt log:
// 1 baseline: natural reconstruction (value local, mask first, != 0 guard). diff=141:
//   mask/explored got ebx/eax instead of eax/ebp (saved ebx instead of ebp), guard je not jbe.
// 2: guard spelled `> 0` (jbe) - no codegen change (VC5 canonicalizes unsigned >0 to !=0).
// 3: DECLARATION ORDER FIX: `explored` before `mask` flips VC5 into the original register
//   coloring (mask=eax+home, explored=ebp, saved ebp) - diff dropped 141 -> 4.
// 4: guard `> 0` now produces the original `jbe` (1 byte closer); diff=3.
// 5: call statement collapsed to one line - no change (still 3).
// 6: while-loop form - worse (27, assembly-farther 24); reverted to if+do-while.
// 7: for-loop increment-clause form - same 27; reverted.
// 8: variant lab (960 variants; axes guard/cond/access/call/bottom): G0000 = current
//   source is best at 3 bytes; no exact. Remaining 3-byte gap: the mask-home reload
//   `mov eax,[esp+10h]` after the virtual call sits in the CALL block in the original
//   (join at add edi,4) but in the LOOP-BOTTOM block in rebuilt (join at the reload),
//   shifting the three skip-branch displacements by 4 each.
// Left in scratch: canonical reconstruction matches size/calls/frame/registers/CFG 100%
//   shape; only the reload block-membership scheduling differs (3 bytes).

typedef unsigned long ulong;

#define unified_map_offsets ((ulong**)0x00886808)

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;

class RGE_Doppleganger_Creator {
public:
    int add_doppleganger_check(RGE_Static_Object* object, ulong* map_address);
};

class RGE_Master_Static_Object {
public:
    virtual void vf00(void);
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
    char gap_04[0xA6 - 0x04];
    unsigned char create_doppleganger_on_death;   // +0xA6
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;                         // +0x40
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;    // +0x24
    char gap_28[0x3C - 0x28];
    RGE_Game_World* world;                        // +0x3C
    RGE_Doppleganger_Creator* doppleganger_creator; // +0x40
};

class RGE_Static_Object {
public:
    long id;                                      // +4
    RGE_Master_Static_Object* master_obj;         // +8
    RGE_Player* owner;                            // +0xC
    char gap_10[0x38 - 0x10];
    float world_x;                                // +0x38
    float world_y;                                // +0x3C
    float world_z;                                // +0x40

    virtual void create_doppleganger_when_dying();
};

void RGE_Static_Object::create_doppleganger_when_dying() {
    if (this->id >= 0 && this->owner != 0 && this->master_obj != 0 &&
        this->master_obj->create_doppleganger_on_death == 2) {
        ulong value = unified_map_offsets[(int)this->world_y][(int)this->world_x];
        ulong explored = value >> 16;
        ulong mask = value & 0xFFFF;
        if (explored > 0) {
            int i = 0;
            do {
                if ((explored & 1) == 1 && (mask & 1) == 0 && i > 0) {
                    RGE_Player* player = *(RGE_Player**)((char*)this->owner->world->players + i);
                    player->master_objects[243]->make_new_obj(player, this->world_x, this->world_y, this->world_z, this);
                }
                i += 4;
                mask >>= 1;
                explored >>= 1;
            } while (explored != 0);
        }
        this->owner->doppleganger_creator->add_doppleganger_check(
            this, &unified_map_offsets[(int)this->world_y][(int)this->world_x]);
    }
}
