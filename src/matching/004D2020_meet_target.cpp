// VA: 004D2020 TRIBE_Action_Repair::meet_target (388 B)
// PDB: tact_rep.cpp:501-557
// Baseline reconstruction uses the typed action/object/player ownership chain.
// The target's owner list supplies repair actions. The original source uses
// ordinary virtual calls for target/state/path queries and direct action helpers.
// Attempt log:
// - Baseline matched size/frame/calls and left six bytes from master-field and receiver offsets.
// - Split master id (+10) from object_group (+14); the candidate gate uses id.
// - Restored RGE_Static_Object size through +88; command_flag then landed at +188.
// - Corrected moveTo and command_flag receivers to target_obj; exact match followed.

#ifndef TACT_REP_CONTEXT_H
class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    short copy_id;
    short object_group;
};

class RGE_Player;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;

class XYPoint {
public:
    int x;
    int y;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual RGE_Static_Object* get_target_obj();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual unsigned char actionState();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual int moveTo(float x, float y, float z, float range, int flag);
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual int firstTileAlongLine(XYPoint* dest, XYPoint* start, XYPoint* result, int a, int b, int c);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x44];
};

class RGE_Object_Node {
public:
    RGE_Action_Object* object;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    void* vtable_ptr;
    RGE_Object_Node* list;
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_88[0xF8];
    unsigned char waiting;
    char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
};

class RGE_Action_List {
public:
    RGE_Action* get_action();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    unsigned short action_type;
    unsigned short gap_06;
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    RGE_Action_Object* target_obj;
    RGE_Action_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    float targetX();
    float targetY();
};

class TRIBE_Action_Repair : public RGE_Action {
public:
    unsigned char save_target_command_flag;

    void meet_target();
};
#endif

void TRIBE_Action_Repair::meet_target() {
    XYPoint rVal;
    XYPoint start;
    XYPoint dest;
    short type = this->target_obj->master_obj->object_group;

    if (type == 2 || type == 0x14 || type == 0x15 || type == 0x16) {
        RGE_Object_Node* node = this->obj->owner->objects->list;
        while (node != 0) {
            RGE_Action_Object* action = node->object;
            if (action != this->obj && action->master_obj->id == 0x9C) {
                if (action->get_target_obj() == this->target_obj && action->actionState() != 2) {
                    if (this->target_obj->actionState() == 0x0B) {
                        this->target_x = this->target_obj->actions->get_action()->targetX();
                        this->target_y = this->target_obj->actions->get_action()->targetY();
                    } else {
                        this->target_x = this->target_obj->world_x;
                        this->target_y = this->target_obj->world_y;
                    }
                    return;
                }
            }
            node = node->next;
        }

        dest.x = (int)this->obj->world_x;
        dest.y = (int)this->obj->world_y;
        start.x = (int)this->target_obj->world_x;
        start.y = (int)this->target_obj->world_y;
        if (this->obj->firstTileAlongLine(&dest, &start, &rVal, 2, 2, 1) == 1) {
            this->target_x = (float)rVal.x + 0.5f;
            this->target_y = (float)rVal.y + 0.5f;
            this->target_obj->moveTo((float)rVal.x + 0.5f, (float)rVal.y + 0.5f,
                                     this->target_obj->world_z, 0.0f, 1);
            this->save_target_command_flag = this->target_obj->command_flag;
        }
    }
}
