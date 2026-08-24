#ifndef TACT_LST_CONTEXT_H
#define TACT_LST_CONTEXT_H

// Local declaration surface for the original tact_lst.cpp module.
// The class sizes and virtual slots follow the reviewed tactical-action
// layouts.  Owner bodies remain in PDB source order in tact_lst_tu.cpp.

typedef unsigned char uchar;

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Node;
class RGE_Action_Object;
class RGE_Master_Action_Object;
class RGE_Static_Object;
class RGE_Task;
class TRIBE_Action_List;

class RGE_Task {
public:
    char gap_00[6];
    short action_type;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type;
    char gap_06[0x3A];
};

typedef char tact_lst_action_abi[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_lst_task_abi[(sizeof(RGE_Task) == 0x08) ? 1 : -1];

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();
    virtual void get_action_name(char*);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual ~RGE_Action_List();

    RGE_Action_List(RGE_Action_Object* object);

    RGE_Action_Object* obj;
    RGE_Action_Node* list;
};

typedef char tact_lst_list_abi[(sizeof(RGE_Action_List) == 0x0C) ? 1 : -1];

class TRIBE_Action_List : public RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual void get_action_name(char*);

    TRIBE_Action_List(RGE_Action_Object* object);
};

typedef char tact_lst_tribe_list_abi[(sizeof(TRIBE_Action_List) == 0x0C) ? 1 : -1];

class RGE_Action_Enter : public RGE_Action {
public:
    RGE_Action_Enter(int, RGE_Action_Object*);
    RGE_Action_Enter(RGE_Action_Object*, RGE_Task*, RGE_Action_Object*);
};

class RGE_Action_Transport : public RGE_Action {
public:
    RGE_Action_Transport(int, RGE_Action_Object*);
    RGE_Action_Transport(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Build : public RGE_Action {
public:
    TRIBE_Action_Build(int, RGE_Action_Object*);
    TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Build(RGE_Action_Object*, RGE_Task*, float, float, float);
};

typedef char tact_lst_build_abi[(sizeof(TRIBE_Action_Build) == 0x40) ? 1 : -1];

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    char gap_40[0x10];
    TRIBE_Action_Make_Obj(int, RGE_Action_Object*);
};

typedef char tact_lst_make_obj_abi[(sizeof(TRIBE_Action_Make_Obj) == 0x50) ? 1 : -1];

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    char gap_40[0x08];
    TRIBE_Action_Make_Tech(int, RGE_Action_Object*);
};

typedef char tact_lst_make_tech_abi[(sizeof(TRIBE_Action_Make_Tech) == 0x48) ? 1 : -1];

class TRIBE_Action_Convert : public RGE_Action {
public:
    char gap_40[0x08];
    TRIBE_Action_Convert(int, RGE_Action_Object*);
    TRIBE_Action_Convert(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Convert(RGE_Action_Object*, RGE_Task*, float, float, float);
};

typedef char tact_lst_convert_abi[(sizeof(TRIBE_Action_Convert) == 0x48) ? 1 : -1];

class TRIBE_Action_Heal : public RGE_Action {
public:
    TRIBE_Action_Heal(int, RGE_Action_Object*);
    TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    TRIBE_Action_Artifact(int, RGE_Action_Object*);
    TRIBE_Action_Artifact(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Artifact(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Wonder : public RGE_Action {
public:
    TRIBE_Action_Wonder(int, RGE_Action_Object*);
    TRIBE_Action_Wonder(RGE_Action_Object*);
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    char gap_40[0x04];
    TRIBE_Action_Discovery_Artifact(int, RGE_Action_Object*);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object*, RGE_Task*, float, float, float);
};

typedef char tact_lst_discovery_abi[(sizeof(TRIBE_Action_Discovery_Artifact) == 0x44) ? 1 : -1];

class TRIBE_Action_Hunt : public RGE_Action {
public:
    char gap_40[0x04];
    TRIBE_Action_Hunt(int, RGE_Action_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Repair : public RGE_Action {
public:
    char gap_40[0x04];
    TRIBE_Action_Repair(int, RGE_Action_Object*, int);
    TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, float, float, float);
};

class TRIBE_Action_Trade : public RGE_Action {
public:
    char gap_40[0x08];
    TRIBE_Action_Trade(int, RGE_Action_Object*);
    TRIBE_Action_Trade(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Trade(RGE_Action_Object*, RGE_Task*, float, float, float);
};

typedef char tact_lst_trade_abi[(sizeof(TRIBE_Action_Trade) == 0x48) ? 1 : -1];

#endif
