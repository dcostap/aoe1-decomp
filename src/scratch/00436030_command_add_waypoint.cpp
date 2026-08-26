// RGE_Command::command_add_waypoint (__thiscall)
// VA: 00436030
// Command.cpp:2031-2070
// 155 bytes
//
// Attempt 3: Indexed loop and the binary Log helper.

#include <stdlib.h>
#include <stdio.h>

#ifndef COMMAND_TU_CONTEXT
struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Master_Static_Object {
public:
    char gap_00[8];
    char* name;                    // +8
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master_obj;  // +8
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int obj_id);
};

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;         // +4

    void command_add_waypoint(int player, int obj_id, XYZBYTEPoint* pts, int count);
    void submit(void* buf, int size);
};
#endif

#ifndef COMMAND_TU_CONTEXT
extern void __cdecl Log(void* log, const char* fmt, int, const char*);
extern void* L;                     // 0x62C4FC
#endif

void RGE_Command::command_add_waypoint(int player, int obj_id, XYZBYTEPoint* pts, int count)
{
    unsigned char* buf = (unsigned char*)calloc(1, 0x18);
    buf[0] = 0x0C;
    buf[1] = (unsigned char)player;
    *(int*)(buf + 4) = obj_id;
    buf[8] = (unsigned char)count;

    for (int i = 0; i < count; i++) {
        buf[9 + i * 3 + 0] = pts[i].x;
        buf[9 + i * 3 + 1] = pts[i].y;
        buf[9 + i * 3 + 2] = pts[i].z;
    }

    RGE_Static_Object* obj = this->world->object(obj_id);
    char* name;
    if (obj != 0)
        name = obj->master_obj->name;
    else
        name = "X";

    Log(L, "      >SEND CMD ADD WAY (PLR=%d,REC=%s)", player, name);

    submit(buf, 0x18);
}
