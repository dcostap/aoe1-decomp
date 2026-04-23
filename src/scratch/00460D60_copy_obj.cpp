// tried the direct nested-if shape; VC5 kept widening the prolog with an extra saved register
// tried collapsing the class to only obj/master pointers and then adding the 0x10 gap, but the entry load order still drifted
// leaving in scratch: remaining delta is the prolog/register basin and the exact obj/master field order

class RGE_Master_Static_Object;

class RGE_Static_Object {
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
    virtual void vf38(int value);
    virtual void copy_obj(RGE_Master_Static_Object* master_obj);

    char gap_04[0xB8];
    int field_BC;
    int field_C0;
};

class RGE_Moving_Object {
public:
    char gap_00[0x8];
    RGE_Static_Object* obj;
    char gap_0C[0x4];
    RGE_Master_Static_Object* master_obj;

    void copy_obj(RGE_Master_Static_Object* master_obj);
};

class RGE_Master_Static_Object {
public:
    char gap_00[0xB8];
    int field_BC;
    int field_C0;
};

void RGE_Moving_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    int value = 0;
    RGE_Static_Object* obj = this->obj;
    RGE_Master_Static_Object* old = this->master_obj;

    if (obj->field_BC == old->field_BC) {
        value = master_obj->field_BC;
    } else if (obj->field_BC == old->field_C0) {
        value = master_obj->field_C0;
    }
    if (value != 0) {
        obj->vf38(value);
    }
    ((RGE_Static_Object*)this)->copy_obj(master_obj);
}
