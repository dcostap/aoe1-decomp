// VA: 00406010 RGE_Action_Object::~RGE_Action_Object (112 B)
// PDB source: act_obj.cpp lines 76-82
// Flags: config/flags/00406010_RGE_Action_Object.rsp (default + /GX)

#ifndef ACT_OBJ_CONTEXT_H
extern void operator_delete(void* ptr);

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char body[0x180 - 4];
};

class RGE_Action_List {
public:
    ~RGE_Action_List();
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();

    unsigned char waiting;
    char pad_181[3];
    RGE_Action_List* actions;   // +0x184
    char command_flag;
    char pad_189[3];
    int lastActionValue;        // +0x18C
    int lastActionStateValue;   // +0x190
};
#endif

RGE_Action_Object::~RGE_Action_Object()
{
    RGE_Action_List* p = this->actions;
    if (p != 0) {
        p->RGE_Action_List::~RGE_Action_List();
        operator_delete(p);
        this->actions = 0;
    }
    // No explicit ~RGE_Moving_Object() call — VC5 auto-generates it.
}
