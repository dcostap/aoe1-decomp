// RGE_Command::command_stop — MATCH (171B)
// VA: 004354F0
// Key fixes: use the real member-call/logging surface instead of helper wrappers; compute
// `dst = buf + 2` before the null check to match the original `lea eax,[esi+2]` before `je`;
// copy via a char-byte delta from source array to destination so VC5 emits the exact
// `[ecx+eax]` addressing form in the packed id copy loop.
#include <stdlib.h>

#define STR_SEND_CMD_STOP2 ((const char*)0x00583BA8)
#define STR_X              ((const char*)0x00583B74)
#define PTR_L              ((void*)0x0062C4FC)

class RGE_Game_World;
class RGE_Static_Object;
class RGE_Command {
public:
    virtual ~RGE_Command() {}
    RGE_Game_World* world;
    void command_stop(int player, int* arr, int count);
    void submit(void* buf, int size);
};
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class RGE_Static_Object { public: char pad_00[8]; void* master_obj; };
void __cdecl RGE_Log(void* log, const char* fmt, int count, int player, const char* name);

void RGE_Command::command_stop(int player, int* arr, int count)
{
    if (arr != 0 && count >= 1) {
        int size = count * 4 + 2;
        char* buf = (char*)calloc(1, size);
        int* dst = (int*)(buf + 2);
        if (buf != 0) {
            if (count > 0) { int delta = (char*)arr - (char*)dst; int n = count; do { *dst = *(int*)((char*)dst + delta); dst++; } while (--n); }
            buf[0] = 1; buf[1] = (char)count;
            RGE_Static_Object* obj = this->world->object(arr[0]);
            const char* name; if (obj != 0) name = *(const char**)((char*)obj->master_obj + 8); else name = STR_X;
            RGE_Log(*(void**)PTR_L, STR_SEND_CMD_STOP2, count, player, name);
            this->submit(buf, size);
        }
    }
}
