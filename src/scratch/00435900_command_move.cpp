// VA: 00435900 RGE_Command::command_move
// PDB: Command.cpp lines 1586-1628
// Modeled after matched command_stop packet-copy/log/submit topology.
// 2026-05-31: Probed guard order, src locals/register hints, int-vs-float x/y, typed packet,
// top-declared locals, and a 240-variant lab over local/store/class surfaces. Competitive
// variants collapse to the same 192B shifted-alignment basin: VC5 colors arr in EBP and
// size in EDI, while the original colors arr in EDI and size in EBP.
#include <stdlib.h>

#define STR_SEND_CMD_MOVE2 ((const char*)0x00583C8C)
#define STR_X              ((const char*)0x00583B74)
#define PTR_L              ((void*)0x0062C4FC)

class RGE_Game_World;
class RGE_Static_Object;
class RGE_Command {
public:
    virtual ~RGE_Command() {}
    RGE_Game_World* world;
    void command_move(int player, int* arr, int count, int param4, int unused, float x, float y);
    void submit(void* buf, int size);
};
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class RGE_Static_Object { public: char pad_00[8]; void* master_obj; };
void __cdecl RGE_Log(void* log, const char* fmt, int count, int player, const char* name);

void RGE_Command::command_move(int player, int* arr, int count, int param4, int unused, float x, float y)
{
    if (arr != 0 && count >= 1) {
        int size = count * 4 + 0x14;
        char* buf = (char*)calloc(1, size);
        int* dst = (int*)(buf + 0x14);
        if (buf != 0) {
            if (count > 0) { int delta = (char*)arr - (char*)dst; int n = count; do { *dst = *(int*)((char*)dst + delta); dst++; } while (--n); }
            buf[0] = 3; buf[8] = (char)count;
            *(int*)(buf + 4) = param4;
            *(float*)(buf + 0x0C) = x;
            *(float*)(buf + 0x10) = y;
            RGE_Static_Object* obj = this->world->object(arr[0]);
            const char* name; if (obj != 0) name = *(const char**)((char*)obj->master_obj + 8); else name = STR_X;
            RGE_Log(*(void**)PTR_L, STR_SEND_CMD_MOVE2, count, player, name);
            this->submit(buf, size);
        }
    }
}
