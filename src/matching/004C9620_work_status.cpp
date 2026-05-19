// VA: 004C9620 TRIBE_Building_Object::work_status(short*, short*, short*, char*, short)
// PDB source: t_b_obj.cpp lines 872-898 (150 B, 48 asm)
// Attempt log:

class RGE_Action {
public:
    char gap_00[4];
    short action_type; // +0x04
};

class RGE_Action_List {
public:
    RGE_Action* get_action();
};

class RGE_Moving_Object {
public:
    char gap_000[0x180];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    char waiting;          // +0x180
    char pad_181[3];       // +0x181-0x183
    RGE_Action_List* actions; // +0x184
};

class TRIBE_Building_Object : public RGE_Action_Object {
public:
    int work_status(short* p1, short* p2, short* p3, char* p4, short p5);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    void get_info(short* p2, short* p3, char* p4, short p5);
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    void get_info(short* p2, short* p3, char* p4, short p5);
};

int TRIBE_Building_Object::work_status(short* p1, short* p2, short* p3, char* p4, short p5)
{
    RGE_Action* action = this->actions->get_action();
    
    if (action != 0) {
        *p1 = action->action_type;
    } else {
        *p1 = 0;
    }
    
    switch (*p1) {
    case 0x66:
        ((TRIBE_Action_Make_Obj*)action)->get_info(p2, p3, p4, p5);
        return 1;
    case 0x67:
        ((TRIBE_Action_Make_Tech*)action)->get_info(p2, p3, p4, p5);
        return 1;
    default:
        *p2 = -1;
        *p3 = 0;
        if (p4 != 0) *p4 = 0;
        return 0;
    }
}
