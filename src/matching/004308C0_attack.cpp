// 004308C0 RGE_Combat_Object::attack(int target_id, int force)
// Attempt log:
// 1: Natural reconstruction from packet, modeled after matching 00430A90 attack(float,float,float,int); with /GX flag, close but initial object lookup used [this+0x0c] directly instead of owner->world.
// 2: Model +0x0c as owner/player with world at +0x3c, matching original first call and special group branch.
// FLAGS: config/flags/004308C0_attack.rsp uses /GX for original EH frame.

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual short type();
    char gap_04[4];
    void* master; // +8
    char gap_0c[0x2c];
    float x; // +38
    float y; // +3c
    float z; // +40
};

class RGE_Action {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14();
    virtual short action_type(); // +18
    virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28();
    virtual void v2c(); virtual void v30();
    virtual void set_target(RGE_Static_Object* obj, float x, float y, float z); // +34
    virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48();
    virtual RGE_Static_Object* target_obj(); // +4c
};

class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Owner {
public:
    char gap_00[0x24];
    void* table24;
    char gap_28[0x14];
    RGE_Game_World* world;
};

class RGE_Master_Combat_Object {
public:
    char gap_000[0x14];
    short object_group;
    char gap_016[0xfe];
    float field_114;
    char gap_118[0x0c];
    short field_124;
    char gap_126[4];
    short field_12a;
    char gap_12c[0x0c];
    float field_138;
};

class RGE_Action_Attack {
public:
    char gap_00[0x5c];
    RGE_Action_Attack(void* obj, RGE_Static_Object* target, int a, int b, int c, float f1, float f2, short s1, short s2);
};

class RGE_Combat_Object {
public:
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00C();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01C();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02C();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03C();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04C();
    virtual void v050();
    virtual void set_something(int v); // +54
    virtual void v058(); virtual void v05C(); virtual void v060(); virtual void v064();
    virtual void v068(); virtual void v06C(); virtual void v070(); virtual void v074();
    virtual void v078(); virtual void v07C(); virtual void v080(); virtual void v084();
    virtual void v088(); virtual void v08C(); virtual void v090(); virtual void v094();
    virtual void v098(); virtual void v09C(); virtual void v0A0(); virtual void v0A4();
    virtual void v0A8(); virtual void v0AC(); virtual void v0B0(); virtual void v0B4();
    virtual void v0B8(); virtual void v0BC(); virtual void v0C0(); virtual void v0C4();
    virtual void v0C8(); virtual void v0CC(); virtual void v0D0(); virtual void v0D4();
    virtual void v0D8(); virtual void v0DC(); virtual void v0E0(); virtual void v0E4();
    virtual void v0E8(); virtual void v0EC(); virtual void v0F0(); virtual void v0F4();
    virtual void v0F8(); virtual void v0FC(); virtual void v100(); virtual void v104();
    virtual void v108(); virtual void v10C(); virtual void v110(); virtual void v114();
    virtual void v118(); virtual void v11C(); virtual void v120(); virtual void v124();
    virtual void v128(); virtual void v12C(); virtual void v130(); virtual void v134();
    virtual void v138(); virtual void v13C(); virtual void v140(); virtual void v144();
    virtual void v148(); virtual void v14C(); virtual void v150(); virtual void v154();
    virtual void v158(); virtual void v15C(); virtual void v160(); virtual void v164();
    virtual void v168(); virtual void v16C(); virtual void v170(); virtual void v174();
    virtual void v178(); virtual void v17C(); virtual void v180(); virtual void v184();
    virtual void v188(); virtual void v18C(); virtual void v190(); virtual void v194();
    virtual void v198(); virtual void v19C(); virtual void v1A0(); virtual void v1A4();
    virtual void v1A8(); virtual void v1AC(); virtual void v1B0(); virtual void v1B4();
    virtual void v1B8(); virtual void v1BC(); virtual void v1C0(); virtual void v1C4();
    virtual void v1C8(); virtual void v1CC(); virtual void v1D0(); virtual void v1D4();
    virtual void v1D8(); virtual void v1DC(); virtual void v1E0(); virtual void v1E4();
    virtual void v1E8(); virtual void v1EC(); virtual void v1F0(); virtual void v1F4();
    virtual void v1F8(); virtual void v1FC(); virtual void v200(); virtual void v204();
    virtual void add_action(RGE_Action_Attack* action); // +208

    char gap_004[4];
    RGE_Master_Combat_Object* master; // +08
    RGE_Owner* owner; // +0c
    char gap_010[0x174];
    RGE_Action_List* action_list; // +184

    int attack(int target_id, int force);
};
#endif

int RGE_Combat_Object::attack(int target_id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(target_id);
    if (target == 0) {
        return 0;
    }

    if (force == 0) {
        if (this->action_list->have_action() == 1) {
            if (this->action_list->get_action()->target_obj() == target) {
                if (this->action_list->get_action()->action_type() == 9) {
                    return 1;
                }
                if (this->action_list->get_action()->action_type() == 7) {
                    return 1;
                }
            }
        }
    }

    if (this->action_list->have_action() == 1) {
        if (this->action_list->get_action()->target_obj() == target) {
            if (this->action_list->get_action()->action_type() == 9) {
                this->action_list->get_action()->set_target(target, target->x, target->y, target->z);
                return 1;
            }
        }
    }

    if (this->master->object_group == 4) {
        int value = *(int*)((char*)this->owner + 0x24);
        value = *(int*)((char*)value + 0x14c);
        if (value != 0) {
            this->set_something(value);
        }
    }

    RGE_Action_Attack* action = new RGE_Action_Attack(this, target, 0, 0, 0,
        this->master->field_114, this->master->field_138, this->master->field_124, this->master->field_12a);
    if (action == 0) {
        return 0;
    }
    this->action_list->delete_list();
    this->add_action(action);
    return 1;
}
