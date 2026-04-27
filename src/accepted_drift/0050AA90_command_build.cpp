// ACCEPTED_DRIFT: localized packet-tail codegen drift after the exact list-copy loop. Rebuilt uses edx rather than eax for the L load, making the tail one byte longer and shifting branch/call displacements; packet fields, log args, submit args, copied ids, and stack cleanup are behavior-equivalent.
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

class TRIBE_Command : public RGE_Command {
public:
    void command_build(int player_id, int* ids, int count, int build_id, float x, float y, int terrain);
};

extern "C" void* L;
extern "C" void Log(void* log, const char* format, ...);
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_build(int player_id, int* ids, int count, int build_id, float x, float y, int terrain)
{
    if (ids && count >= 1) {
        int size = count * 4 + 0x14;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 0x14);
        if (cmd) {
            for (int i = 0; i < count; ++i) {
                dest[i] = ids[i];
            }
            short build_short = (short)build_id;
            int cat_for_log = build_id;
            *(float*)(cmd + 4) = x;
            *(float*)(cmd + 8) = y;
            cmd[0] = 0x66;
            cmd[1] = (unsigned char)count;
            *(short*)(cmd + 12) = build_short;
            *(int*)(cmd + 0x10) = terrain;
            cmd[2] = (unsigned char)player_id;

            Log(L, "      >SEND CMD BUILD2 (CNT=%d,CAT=%d)", count, cat_for_log);

            this->submit(cmd, size);
        }
    }
}
