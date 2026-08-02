// VA: 004CA210 ~TRIBE_Combat_Object (225 B) — exact match
// PDB source: t_c_obj.cpp:81-104
//
// /GX EH-framed virtual destructor. Canonical ownership (ground truth +
// same-TU exact donors):
//   TRIBE_Combat_Object (base RGE_Combat_Object, size 0x1C8) owns
//   master_obj (+0x08) and owner (+0x0C); own_master flag at +0x1C4.
//   RGE_Master_Static_Object: master_type +0x04, id +0x10, copy_id +0x12,
//   object_group +0x14.
//   RGE_Player: master_objects (+0x24), attributes (+0x50, float[]).
// The virtual slot-0 call with `push 1` is the vector-deleting destructor
// (delete master). The FPU decays reference the shared 1.0f global
// DAT_00574c78 (attributes[37] = +0x94, attributes[40] = +0xA0).
//
// Attempt log:
// - baseline: natural dtor; VC5 kept master in edi and branched before the
//   id load. Original keeps master in ecx and hoists `movsx edi,[ecx+10h]`
//   before the null-check branch.
// - probe 2: hoisted `int id = master->id;` before the if; master stayed in
//   ecx, id in edi. short id emitted `mov di`; int id (from short field)
//   emits the exact `movsx edi,word [ecx+10h]`.
// - probe 4: added copy_id at +0x12 so object_group lands at +0x14; exact.
//
// Note: the original binary loads master->id unconditionally (movsx executes
// before the `je` over the delete), i.e. it would fault on a null master
// inside the own_master gate. The `int id = master->id;` above the null
// check preserves that binary-observed evaluation order.

extern float DAT_00574c78;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type; // +0x04
    char gap_05[0x0B];
    short id; // +0x10
    short copy_id; // +0x12
    short object_group; // +0x14
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects; // +0x24
    char gap_28[0x28];
    float* attributes; // +0x50
};

class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    char gap_04[0x04];
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner; // +0x0C
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    char gap_10[0x1B4];
    unsigned char own_master; // +0x1C4
    virtual ~TRIBE_Combat_Object();
};

TRIBE_Combat_Object::~TRIBE_Combat_Object()
{
    if (this->own_master) {
        RGE_Master_Static_Object* master = this->master_obj;
        int id = master->id;
        if (master != 0) {
            delete master;
        }
        this->master_obj = this->owner->master_objects[id];
    }

    RGE_Master_Static_Object* master = this->master_obj;
    short group = master->object_group;
    if (group == 4 || group == 0x15 || group == 2) {
        this->owner->attributes[37] -= DAT_00574c78; // +0x94
    } else if ((group != 0x12 && master->master_type == 'F') ||
               master->id == 'O' || master->id == 'E' || master->id == 0xC7) {
        this->owner->attributes[40] -= DAT_00574c78; // +0xA0
    }
}
