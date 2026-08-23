#ifndef COMMAND_OWNER_CONTEXT_H
#define COMMAND_OWNER_CONTEXT_H

// Shared owner surface for the ordered Command.cpp methods.
struct RGE_Obj_Info;
struct RGE_Command_Formation;
class RGE_Command_Stop;
class RGE_Static_Object;

struct RGE_Command_Add_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char attr_id;
    unsigned char gap_03;
    int attr_amount;
};

class RGE_Player {
public:
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68();
    virtual void v6C(); virtual void v70(); virtual void v74();
    virtual void add_attribute_num(unsigned short attr_id, int attr_amount, int zero);
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
};

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;
    RGE_Command_Stop* last_order;

protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_add_attribute(RGE_Command_Add_Attribute* command);
    void do_command_formation(RGE_Command_Formation* command);

public:
    unsigned char duplicate_check_command_stop(RGE_Command_Stop* command);
};

#endif

#ifndef COMMAND_CONTEXT_CORE_ONLY
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

#endif
#endif
