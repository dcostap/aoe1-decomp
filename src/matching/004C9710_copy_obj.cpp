#ifndef T_B_OBJ_CONTEXT_H
class RGE_Master_Static_Object {
public:
    char gap_00[0x168];
    int field_168;
    unsigned char field_16C;
};

class RGE_Action_Object {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38(int value);
    virtual void copy_obj(RGE_Master_Static_Object* master_obj);

    int field_04;
    RGE_Master_Static_Object* master_obj;
    int field_0C;
    int field_10;
};

class TRIBE_Building_Object : public RGE_Action_Object {
public:
    void connect();
    void copy_obj(RGE_Master_Static_Object* master_obj);
};
#endif

void TRIBE_Building_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    if (this->field_10 == this->master_obj->field_168) {
        this->vf38(master_obj->field_168);
    }
    RGE_Action_Object::copy_obj(master_obj);
    if (this->master_obj->field_16C != 0) {
        this->connect();
    }
}
