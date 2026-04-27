// 004D1550_stop
// Probe 1: structural stub

class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type;
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    char _gap_08[0x48];
    TRIBE_Action_Make_Obj(int a,int b,int c);
    ~TRIBE_Action_Make_Obj();
    int first_in_stack();
    unsigned char update(int a,int b,int c,int d,int e);
    void place_obj(int a,int b,int c,int d,int e);
    void stop();
    int get_info(int* a,int* b);
};

void TRIBE_Action_Make_Obj::stop() { {} }
