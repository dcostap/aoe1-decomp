#include <windows.h>
#include <stdio.h>

class RGE_Game_World;
class TCommunications_Handler;

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

    void submit(void* cmd, int size);
};

class RGE_Master_Static_Object {
public:
    char gap0[8];
    char* name;
};

class RGE_Player {
public:
    char gap0[0x4A];
    char id;
};

class RGE_Static_Object {
public:
    char gap0[4];
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
};

class TRIBE_Command : public RGE_Command {
public:
    void command_research(RGE_Static_Object* obj, short tech_id);
};

struct TDebuggingLog {
    void Log(const char* format, ...);
};

// 0062C4FC
extern "C" TDebuggingLog* L;

// 0054B730
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_research(RGE_Static_Object* obj, short tech_id)
{
    if (obj) {
        unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
        if (cmd) {
            *(int*)(cmd + 4) = obj->id;
            
            RGE_Player* owner = obj->owner;
            short tech_id_copy = tech_id;
            char owner_id = owner->id;
            cmd[8] = owner_id;
            cmd[0] = 0x65;
            *(short*)(cmd + 10) = tech_id_copy;
            *(int*)(cmd + 12) = -1;

            RGE_Master_Static_Object* master = obj->master_obj;
            int tech_id_int = (int)tech_id_copy;
            
            L->Log("      >SEND CMD RESEARCH (UNIT=%s,TECH=%d)", master->name, tech_id_int);
            
            this->submit(cmd, 0x10);
        }
    }
}
