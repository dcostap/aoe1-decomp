// VA: 004C9490 TRIBE_Building_Object::cancel_build
// PDB source: t_b_obj.cpp
// Baseline: named building/master ownership with the natural percent refund
// calculation and three-element Attribute_Cost scan.
// Attempt log:
// - Baseline natural inventory-element pointer alias matched frame/calls but
//   chose ESI for this, added a loop LEA, and emitted a double-to-float clamp.
// - Direct typed build_inventory[i] accesses plus a float 1.0f clamp matched
//   all 206 bytes; the array element stride produced the original ESI cursor.
// - Moved proven master/owner/hp/selected/state fields into the local
//   RGE_Static_Object base; code remained exact and ownership is canonical.

extern float DAT_005749f4;
extern double DAT_005749f8;
extern double DAT_00574a00;

class TRIBE_Master_Combat_Object;
class RGE_Player;

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
    TRIBE_Master_Combat_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x20];
    float hp;
    char gap_34[2];
    unsigned char selected;
    char gap_37[0x11];
    unsigned char object_state;
    char gap_49[0x3f];
};

class RGE_Player {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void add_attribute_num(short type, float amount, unsigned char flag);

    void unselect_one_object(RGE_Static_Object* object);
};

class Attribute_Cost {
public:
    short type;
    short amount;
    unsigned char flag;
    unsigned char gap_05;
};

class TRIBE_Master_Combat_Object {
public:
    char gap_00[0x148];
    Attribute_Cost build_inventory[3];
    short build_pts_required;
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    char gap_88[0x154];
    float build_pts;

    void cancel_build();
};

void TRIBE_Building_Object::cancel_build()
{
    if ((this->selected & 1) != 0) {
        this->owner->unselect_one_object(this);
    }

    float percent;
    if (this->object_state >= 2 || this->hp <= DAT_005749f4) {
        percent = 0.0f;
    } else {
        percent = ((float)(int)this->master_obj->build_pts_required - this->build_pts) /
                  (float)(int)this->master_obj->build_pts_required * DAT_005749f8;
    }

    if (percent > DAT_00574a00) {
        percent = 1.0f;
    }

    for (int i = 0; i < 3; i++) {
        if (this->master_obj->build_inventory[i].type >= 0 &&
            this->master_obj->build_inventory[i].flag != 0) {
            int amount = this->master_obj->build_inventory[i].amount;
            this->owner->add_attribute_num(this->master_obj->build_inventory[i].type,
                                           (float)amount * percent, 0);
        }
    }

    this->hp = 0.0f;
}
