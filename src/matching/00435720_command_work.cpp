// MATCH: 00435720 RGE_Command::command_work (231B)
// PDB: Command.cpp lines 1474-1516
// Packet-copy command builder, modeled from original asm and matched command_stop idioms.
#include <stdlib.h>

#define STR_SEND_CMD_WORK2 ((const char*)0x00583C24)
#define STR_X              ((const char*)0x00583B74)
#define PTR_L              ((void*)0x0062C4FC)

class RGE_Game_World;
class RGE_Static_Object;
class RGE_Command {
public:
    virtual ~RGE_Command() {}
    RGE_Game_World* world;
    void command_work(int player, int* arr, int count, int target, int unused, float x, float y);
    void submit(void* buf, int size);
};
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class RGE_Static_Object { public: char pad_00[8]; void* master_obj; };
void __cdecl RGE_Log(void* log, const char* fmt, int count, int player, const char* unit_name, const char* target_name);

void RGE_Command::command_work(int player, int* arr, int count, int target, int unused, float x, float y)
{
    int* src;
    if (arr != 0 && count >= 1) {
        src = arr;
        int size = count * 4 + 0x14;
        char* buf = (char*)calloc(1, size);
        int* dst = (int*)(buf + 0x14);
        if (buf != 0) {
            if (count > 0) { int delta = (char*)src - (char*)dst; int n = count; do { *dst = *(int*)((char*)dst + delta); dst++; } while (--n); }
            *(float*)(buf + 0x0C) = x;
            buf[0] = 2;
            buf[8] = (char)count;
            *(int*)(buf + 4) = target;
            *(float*)(buf + 0x10) = y;
            RGE_Static_Object* unit_obj = this->world->object(src[0]);
            RGE_Static_Object* target_obj = this->world->object(target);
            const char* target_name; if (target_obj != 0) target_name = *(const char**)((char*)target_obj->master_obj + 8); else target_name = STR_X;
            const char* unit_name; if (unit_obj != 0) unit_name = *(const char**)((char*)unit_obj->master_obj + 8); else unit_name = STR_X;
            RGE_Log(*(void**)PTR_L, STR_SEND_CMD_WORK2, count, player, unit_name, target_name);
            this->submit(buf, size);
        }
    }
}
