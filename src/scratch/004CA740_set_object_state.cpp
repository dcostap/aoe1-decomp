// tried the natural condition chain; remaining gap is the byte-compare / register basin before the fallback call
class TRIBE_Combat_Object_Status {
public:
    char gap_00[0x3C];
    unsigned char flag_1D;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Static_Object* master_obj;
    void set_object_state(unsigned char p);
};

class TRIBE_Combat_Object {
public:
    char gap_00[0x8];
    RGE_Master_Static_Object* master_obj;
    TRIBE_Combat_Object_Status* status;
    char gap_10[0x38];
    unsigned char field_48;

    void reposition_artifact();
    void set_object_state(unsigned char param_1);
};

void TRIBE_Combat_Object::set_object_state(unsigned char param_1) {
    if ((this->status->flag_1D == 0) && (param_1 > 2) && (this->field_48 <= 2) && (this->master_obj->object_group == 1)) {
        this->reposition_artifact();
        return;
    }
    ((RGE_Static_Object*)this)->set_object_state(param_1);
}
