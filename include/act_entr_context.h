#ifndef ACT_ENTR_CONTEXT_H
#define ACT_ENTR_CONTEXT_H

class RGE_Sprite;
class RGE_Task;
class RGE_Action_List;
class RGE_Action;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Action_Object;

class XYPoint {
public:
    int x;
    int y;
};

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds;

    RGE_Static_Object* object(int param_1);
};

class RGE_Player {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual int vf1C(int param_1);

    int computerPlayer(void);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
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
    virtual void new_sprite(RGE_Sprite* param_1);
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
    virtual void enter_obj(RGE_Static_Object* param_1);
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
    virtual unsigned char actionState(void);
    virtual void vf78(void);
    virtual void vf79(void);
    virtual void vf80(void);
    virtual void vf81(void);
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
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
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x24];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    char gap_49[0x03];

    float distance_to_object(RGE_Static_Object* param_1);
    unsigned char is_dying(void);
    unsigned char more_room(void);
};

/*
 * BINARY NOTE: act_entr.cpp proves action-object calls at +38, +D0, +134,
 * +148, +154, and +1B4.  The inherited static-object surface owns these
 * slots.  The action-object tail retains the observed +184 action-list field.
 */
class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_4C[0x138];
    RGE_Action_List* actions;
};

class RGE_Action_List {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char update(void);

    void delete_list(void);
    void add_action(RGE_Action* param_1);
    RGE_Action* get_action(void);
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
    virtual void first_in_stack(unsigned char param_1);
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
    virtual void set_target_obj2(RGE_Static_Object* param_1);
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
    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
    float targetX(void);
    float targetY(void);
    void setSubAction(unsigned char param_1);
};

class RGE_Task {
public:
    char gap_00[0x24];
    float work_range;
    char gap_28[0x0C];
    RGE_Sprite* move_sprite;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, float param_5, RGE_Sprite* param_6);

    float range;
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
    RGE_Action_Enter(int param_1, RGE_Action_Object* param_2);
    RGE_Action_Enter(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Action_Object* param_3);
    virtual void first_in_stack(unsigned char param_1);
    virtual void set_state(unsigned char param_1);
    virtual unsigned char update(void);
};

extern float DAT_0056e1a0;
extern float DAT_0056e1a4;
extern float DAT_0056e1a8;

#endif
