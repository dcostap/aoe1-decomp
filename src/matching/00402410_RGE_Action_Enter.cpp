class RGE_Sprite;
class RGE_Task;
class RGE_Action_List;
class RGE_Action;
class RGE_Player;
class RGE_Static_Object;

class XYPoint {
public:
    int x;
    int y;
};

class RGE_Player {
public:
    char gap_00[0x0C];

    int computerPlayer();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void vf01(void);
    virtual void vf02(void);
    virtual void vf03(void);
    virtual void vf04(void);
    virtual void vf05(void);
    virtual void vf06(void);
    virtual void vf07(void);
    virtual void vf08(void);
    virtual void vf09(void);
    virtual void vf10(void);
    virtual void vf11(void);
    virtual void vf12(void);
    virtual void vf13(void);
    virtual void vf14(void);
    virtual void vf15(void);
    virtual void vf16(void);
    virtual void vf17(void);
    virtual void vf18(void);
    virtual void vf19(void);
    virtual void vf20(void);
    virtual void vf21(void);
    virtual void vf22(void);
    virtual void vf23(void);
    virtual void vf24(void);
    virtual void vf25(void);
    virtual void vf26(void);
    virtual void vf27(void);
    virtual void vf28(void);
    virtual void vf29(void);
    virtual void vf30(void);
    virtual void vf31(void);
    virtual void vf32(void);
    virtual void vf33(void);
    virtual void vf34(void);
    virtual void vf35(void);
    virtual void vf36(void);
    virtual void vf37(void);
    virtual void vf38(void);
    virtual void vf39(void);
    virtual void vf40(void);
    virtual void vf41(void);
    virtual void vf42(void);
    virtual void vf43(void);
    virtual void vf44(void);
    virtual void vf45(void);
    virtual void vf46(void);
    virtual void vf47(void);
    virtual void vf48(void);
    virtual void vf49(void);
    virtual void vf50(void);
    virtual void vf51(void);
    virtual void vf52(void);
    virtual void vf53(void);
    virtual void vf54(void);
    virtual void vf55(void);
    virtual void vf56(void);
    virtual void vf57(void);
    virtual void vf58(void);
    virtual void vf59(void);
    virtual void vf60(void);
    virtual void vf61(void);
    virtual void vf62(void);
    virtual void vf63(void);
    virtual void vf64(void);
    virtual void vf65(void);
    virtual void vf66(void);
    virtual void vf67(void);
    virtual void vf68(void);
    virtual void vf69(void);
    virtual void vf70(void);
    virtual void vf71(void);
    virtual void vf72(void);
    virtual void vf73(void);
    virtual void vf74(void);
    virtual void vf75(void);
    virtual void vf76(void);
    virtual unsigned char actionState();
    virtual void vf78(void);
    virtual void vf79(void);
    virtual void vf80(void);
    virtual void vf81(void);
    virtual void vf82(void);
    virtual void vf83(void);
    virtual void vf84(void);
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
    virtual void vf86(void);
    virtual void vf87(void);
    virtual void vf88(void);
    virtual void vf89(void);
    virtual void vf90(void);
    virtual void vf91(void);
    virtual void vf92(void);
    virtual void vf93(void);
    virtual void vf94(void);
    virtual void vf95(void);
    virtual void vf96(void);
    virtual void vf97(void);
    virtual void vf98(void);
    virtual void vf99(void);
    virtual void vf100(void);
    virtual void vf101(void);
    virtual void vf102(void);
    virtual void vf103(void);
    virtual void vf104(void);
    virtual void vf105(void);
    virtual void vf106(void);
    virtual void vf107(void);
    virtual void vf108(void);
    virtual int firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6);

    int id;
    void* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x24];
    float world_x;
    float world_y;
    float world_z;

    unsigned char more_room();
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_44[0x140];
    RGE_Action_List* actions;
};

class RGE_Action_List {
public:
    RGE_Action* get_action();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object* param_1);
    virtual int vf08(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* vf0C(RGE_Action_Object* param_1);
    virtual void vf10(void);
    virtual void vf14(int param_1);
    virtual short vf18(void);
    virtual void vf1C(unsigned char param_1);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int vf34(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char vf38(RGE_Static_Object* param_1);
    virtual unsigned char vf3C(long param_1, unsigned char param_2);
    virtual void vf40(void* param_1);
    virtual void vf44(void* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void vf48(char* param_1);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void vf58(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    unsigned short action_type;
    unsigned short gap_06;
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x03];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[0x03];

    RGE_Action(RGE_Action_Object* param_1, int param_2);
    float targetX();
    float targetY();
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
    RGE_Action_Enter(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Action_Object* param_3);
};

RGE_Action_Enter::RGE_Action_Enter(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Action_Object* param_3)
    : RGE_Action(param_1, 1) {
    XYPoint start;
    XYPoint dest;
    XYPoint rVal;
    RGE_Action* action;

    this->action_type = 3;
    this->task = param_2;
    this->set_target_obj(param_3);
    if (param_3 == 0) {
        return;
    }

    this->target_x = param_3->world_x;
    this->target_y = param_3->world_y;
    this->target_z = param_3->world_z;

    if (param_3->actionState() == 2) {
        if (param_3->more_room() == 1) {
            if (this->obj->owner->computerPlayer() == 0) {
                goto line_path;
            }
        }

        if (this->obj->owner->computerPlayer() == 1) {
            goto line_path;
        }
    }

    if (param_3->actionState() == 11) {
        action = param_3->actions->get_action();
        if (action->target2ID == 0) {
            goto line_path;
        }
    }

    if (param_3->actionState() == 11) {
        action = param_3->actions->get_action();
        this->target_x = action->targetX();
        action = param_3->actions->get_action();
        this->target_y = action->targetY();
    }

    return;

line_path:
    dest.x = (int)param_1->world_x;
    dest.y = (int)param_1->world_y;
    start.x = (int)param_3->world_x;
    start.y = (int)param_3->world_y;

    if (param_1->firstTileAlongLine(&dest, &start, &rVal, 2, 2, 1) == 1) {
        this->target_x = (float)rVal.x + 0.5f;
        this->target_y = (float)rVal.y + 0.5f;
        param_3->moveTo((float)rVal.x, (float)rVal.y, param_3->world_z, 0.5f, 1);
    } else {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        param_3->moveTo(param_1->world_x, param_1->world_y, param_3->world_z, 0.5f, 1);
    }
}
