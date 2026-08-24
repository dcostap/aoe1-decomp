// VA: 00405C60 RGE_Action_Object::RGE_Action_Object (7-param ctor, EH-framed)
// PDB source: act_obj.cpp

#ifndef ACT_OBJ_CONTEXT_H
class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    RGE_Moving_Object(void* master, void* player, float x, float y, float z, int flag);
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    RGE_Action_Object(void* master, void* player, float x, float y, float z, int flag);
    int setup(void* master, void* player, float x, float y, float z);
};
#endif

RGE_Action_Object::RGE_Action_Object(void* master, void* player, float x, float y, float z, int flag)
    : RGE_Moving_Object(master, player, x, y, z, 0)
{
    *(int*)((char*)this + 0x18C) = -1;
    *(int*)((char*)this + 0x190) = -1;
    *(void**)this = (void*)0x56E420;
    if (flag != 0) {
        this->setup(master, player, x, y, z);
    }
}
