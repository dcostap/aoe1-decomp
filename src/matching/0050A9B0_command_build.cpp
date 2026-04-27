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

class RGE_Player { public: char gap_00[0x4A]; short id; };
class RGE_Static_Object { public: char gap_00[4]; int id; char gap_08[4]; RGE_Player* owner; };

class TRIBE_Command : public RGE_Command {
public:
    void command_build(RGE_Static_Object** objs, short count, short build_id, float x, float y);
};

struct TDebuggingLog { void Log(const char* format, ...); };
extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_build(RGE_Static_Object** objs, short count, short build_id, float x, float y)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = obj_count * 4 + 0x14;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 0x14);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    dest[i] = objs[i]->id;
                } else {
                    dest[i] = -1;
                }
            }
            cmd[0] = 0x66;
            cmd[1] = (unsigned char)count;
            int owner_id;
            if (objs[0]) {
                owner_id = objs[0]->owner->id;
            } else {
                owner_id = -1;
            }
            *(float*)(cmd + 4) = x;
            *(float*)(cmd + 8) = y;
            cmd[2] = (unsigned char)owner_id;
            *(short*)(cmd + 12) = build_id;
            *(int*)(cmd + 0x10) = -1;

            L->Log("      >SEND CMD BUILD (CNT=%d,CAT=%d)", obj_count, (int)build_id);

            this->submit(cmd, size);
        }
    }
}
