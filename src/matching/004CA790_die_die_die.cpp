// attempt 1: unit_type at +8 instead of +C, virtual at vtable slot 0 instead of 3
// attempt 2: fix offsets and vtable layout

#ifndef T_C_OBJ_CONTEXT_H
class RGE_Action;
class RGE_Action_List;
class TRIBE_Action_Convert;

class RGE_Static_Object {
public:
    char gap_00[0xC];
    void die_die_die();
};

class Unit_Type_Data {
public:
    char gap_00[0x50];
    void* field_50;
};

class TRIBE_Combat_Object : public RGE_Static_Object {
public:
    Unit_Type_Data* unit_type;
    char gap_10[0x38];
    unsigned char field_48;
    char gap_49[0x13B];
    RGE_Action_List* action_list;

    void die_die_die();
};

class RGE_Action {
public:
    virtual void vf_0();
    virtual void vf_4();
    virtual void vf_8();
    virtual void vf_c();
    virtual void vf_10();
    virtual void vf_14();
    virtual short get_type();
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    void martyrdom();
};

class RGE_Action_List {
public:
    RGE_Action* get_action();
};
#endif

void TRIBE_Combat_Object::die_die_die() {
    if (field_48 == 2) {
        float val = *(float*)((int)unit_type->field_50 + 0xE4);
        if (val >= 1.0f) {
            RGE_Action* action = action_list->get_action();
            if (action != 0) {
                short type = action->get_type();
                if (type == 0x68) {
                    TRIBE_Action_Convert* convert = (TRIBE_Action_Convert*)action;
                    convert->martyrdom();
                }
            }
        }
    }
    RGE_Static_Object::die_die_die();
}
