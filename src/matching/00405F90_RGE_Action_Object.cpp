// VA: 00405F90 RGE_Action_Object::RGE_Action_Object (3-param ctor, EH-framed)
// PDB source: act_obj.cpp

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    RGE_Moving_Object(int id, void* world, int flag);
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    RGE_Action_Object(int id, void* world, int flag);
    int setup(int id, void* world);
};

RGE_Action_Object::RGE_Action_Object(int id, void* world, int flag)
    : RGE_Moving_Object(id, world, 0)
{
    *(int*)((char*)this + 0x18C) = -1;
    *(int*)((char*)this + 0x190) = -1;
    *(void**)this = (void*)0x56E420;
    if (flag != 0) {
        this->setup(id, world);
    }
}
