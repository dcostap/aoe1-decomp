#ifndef ACT_OBJ_CONTEXT_H
class RGE_Master_Static_Object;

class RGE_Action_List {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void copy_obj(RGE_Master_Static_Object* master_obj);
};

class RGE_Moving_Object {
public:
    void copy_obj(RGE_Master_Static_Object* master_obj);
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    char gap_00[0x184];
    RGE_Action_List* actions;

    void copy_obj(RGE_Master_Static_Object* master_obj);
};
#endif

void RGE_Action_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    this->actions->copy_obj(master_obj);
    RGE_Moving_Object::copy_obj(master_obj);
}
