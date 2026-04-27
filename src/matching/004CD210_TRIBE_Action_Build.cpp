// VA: 004CD210 TRIBE_Action_Build::TRIBE_Action_Build (EH-framed, ret 0Ch)
// PDB source: tact_bld.cpp

class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(void* obj, int flag);
    void set_target_obj(void* obj);
};

class TRIBE_Action_Build : public RGE_Action {
public:
    TRIBE_Action_Build(void* action_obj, void* task, void* target);
};

TRIBE_Action_Build::TRIBE_Action_Build(void* action_obj, void* task, void* target)
    : RGE_Action(action_obj, 1)
{
    *(void**)this = (void*)0x574F18;
    *(short*)((char*)this + 4) = 0x65;
    *(void**)((char*)this + 0x30) = task;
    
    if (!target || (*(short*)(*(char**)((char*)action_obj + 0xC) + 0x4A) == *(short*)(*(char**)((char*)target + 0xC) + 0x4A))) {
        set_target_obj(target);
        *(float*)((char*)this + 0x20) = *(float*)((char*)target + 0x38);
        *(float*)((char*)this + 0x24) = *(float*)((char*)target + 0x3C);
        *(float*)((char*)this + 0x28) = *(float*)((char*)target + 0x40);
    }
}
