#include <windows.h>
#include <stdio.h>

class RGE_Game_World;
class TCommunications_Handler;
class RGE_Static_Object;
struct RGE_Obj_Info {
    int id;
};

class RGE_Command {
public:
    virtual void vfunc0() = 0;
    virtual ~RGE_Command() {}
    virtual void vfunc8() = 0;
    virtual void vfuncC() = 0;

    RGE_Game_World* world;
    void* last_order;
    int last_order_size;
    unsigned int last_order_time;
    TCommunications_Handler* com_hand;

    RGE_Static_Object* get_obj(RGE_Obj_Info info);
};

class RGE_Player {
public:
    virtual void vfunc0() = 0;
    virtual void vfunc4() = 0;
    virtual void vfunc8() = 0;
    virtual void vfuncC() = 0;
    virtual void vfunc10() = 0;
    virtual void vfunc14() = 0;
    virtual void vfunc18() = 0;
    virtual void vfunc1C() = 0;
    virtual void vfunc20() = 0;
    virtual void vfunc24() = 0;
    virtual void vfunc28() = 0;
    virtual void vfunc2C() = 0;
    virtual void vfunc30() = 0;
    virtual void vfunc34(int a1, int a2, int a3, int a4, int a5, float a6, float a7, int a8, float a9, int a10, int a11, int a12) = 0;

    char gap0[0x4A - 4];
    short id;
};

class RGE_Static_Object {
public:
    virtual void vfunc0() = 0;
    virtual void vfunc4() = 0;
    virtual void vfunc8() = 0;
    virtual void vfuncC() = 0;

    int id;
    void* master_obj;
    RGE_Player* owner;

    void removeAllFromPathingGroup();
};

struct TRIBE_Command_Unload {
    unsigned char command;
    unsigned char unit_num;
    char gap2[2];
    float location_x;
    float location_y;
    RGE_Obj_Info unit_ids[1];
};

class TRIBE_Command : public RGE_Command {
public:
    void do_command_unload(TRIBE_Command_Unload* cmd);
};

void TRIBE_Command::do_command_unload(TRIBE_Command_Unload* cmd)
{
    TRIBE_Command* v_this = this;
    RGE_Obj_Info* v_ids = cmd->unit_ids;
    for (int v_count = (int)cmd->unit_num; v_count > 0; v_count--) {
        RGE_Static_Object* obj = v_this->get_obj(*v_ids);
        if (obj) {
            obj->removeAllFromPathingGroup();
            RGE_Player* owner = obj->owner;
            owner->vfunc34(owner->id, obj->id, 0x2D1, obj->id, owner->id, cmd->location_x, cmd->location_y, 0, 1.0f, 1, 0, 100);
        }
        v_ids++;
    }
}
