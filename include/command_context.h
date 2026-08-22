#ifndef COMMAND_CONTEXT_H
#define COMMAND_CONTEXT_H

struct RGE_Obj_Info {
    int id;
};

struct RGE_Command_Formation {
    unsigned char command;
    unsigned char gap_01[3];
    int unitNum;
    int formationID;
    RGE_Obj_Info units[1];
};

class RGE_Command_Stop {
public:
    char pad_00[1];
    unsigned char unit_num;
    int items[1];
};

class RGE_Static_Object {
public:
    virtual void vf00(void); virtual void vf04(void); virtual void vf08(void); virtual void vf0C(void);
    virtual void vf10(void); virtual void vf14(void); virtual void vf18(void); virtual void vf1C(void);
    virtual void vf20(void); virtual void vf24(void); virtual void vf28(void); virtual void vf2C(void);
    virtual void vf30(void); virtual void vf34(void); virtual void vf38(void); virtual void vf3C(void);
    virtual void vf40(void); virtual void vf44(void); virtual void vf48(void); virtual void vf4C(void);
    virtual void vf50(void); virtual void vf54(void); virtual void vf58(void); virtual void vf5C(void);
    virtual void vf60(void); virtual void vf64(void); virtual void vf68(void); virtual void vf6C(void);
    virtual void vf70(void); virtual void vf74(void); virtual void vf78(void); virtual void vf7C(void);
    virtual void vf80(void); virtual void vf84(void); virtual void vf88(void); virtual void vf8C(void);
    virtual void vf90(void); virtual void vf94(void); virtual void vf98(void);
    virtual void move_to(void* target, float x, float y, float z);
    virtual void vfA0(void); virtual void vfA4(void); virtual void vfA8(void); virtual void vfAC(void);
    virtual void vfB0(void); virtual void vfB4(void); virtual void vfB8(void); virtual void vfBC(void);
    virtual void vfC0(void); virtual void vfC4(void); virtual void vfC8(void); virtual void vfCC(void);
    virtual void vfD0(void); virtual void vfD4(void); virtual void vfD8(void); virtual void vfDC(void);
    virtual void vfE0(void); virtual void vfE4(void); virtual void vfE8(void); virtual void vfEC(void);
    virtual void vfF0(void); virtual void vfF4(void); virtual void vfF8(void); virtual void vfFC(void);
    virtual void vf100(void); virtual void vf104(void); virtual void vf108(void); virtual void vf10C(void);
    virtual void vf110(void); virtual void vf114(void); virtual void vf118(void); virtual void vf11C(void);
    virtual void vf120(void); virtual void vf124(void); virtual void vf128(void);
    virtual void setWaitingToMove(unsigned char waiting);

    long id;
    void* master_obj;
    void* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    void removeAllFromPathingGroup(void);
    void addToPathingGroup(int group_index);
};

class RGE_Command {
public:
    char gap_00[8];
    union {
        void* world;
        RGE_Command_Stop* last_order;
    };

    unsigned char duplicate_check_command_stop(RGE_Command_Stop* command);

protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_formation(RGE_Command_Formation* command);
};

#endif
