// first pass reconstructed the natural tcommand.cpp unload packet builder; control flow and behavior are close but VC5 chooses a different esi/edi role split and loop counter topology.
// tried explicit pointer-delta/countdown loop; VC5 still kept count in esi and packet in edi, with size-short object.
// next kept command_explore-style TU/class surface to test donor-file context.
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

class RGE_Static_Object {
public:
    char gap_00[4];
    int id;
};

class TRIBE_Command : public RGE_Command {
public:
    void command_unload(RGE_Static_Object** objs, short count, float x, float y);
};

struct TDebuggingLog {
    void Log(const char* format, ...);
};

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_unload(RGE_Static_Object** objs, short count, float x, float y)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = obj_count * 4 + 12;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 12);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    dest[i] = objs[i]->id;
                } else {
                    dest[i] = -1;
                }
            }
            cmd[0] = 0x6F;
            cmd[1] = (unsigned char)count;
            *(float*)(cmd + 4) = x;
            *(float*)(cmd + 8) = y;

            L->Log("      >SEND CMD UNLOAD (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}
