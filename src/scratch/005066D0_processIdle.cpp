// 005066D0 TribeTradeShipUnitAIModule::processIdle
// PDB: taiuaimd.cpp:1981-2027, 250 bytes
// int __thiscall processIdle(int param_1), ret 4
// FLAGS: default

#include <stdlib.h>
#include <math.h>

typedef unsigned long DWORD;

class RGE_Game_World;

class RGE_Player {
public:
    char _gap_00[0x3C];
    RGE_Game_World* world;           // +0x3C
    int computerPlayer();
};

class RGE_Game_World {
public:
    class RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    char _gap_00[0x38];
    float world_x;                   // +0x38
    float world_y;                   // +0x3C
};

class TribeTradeShipUnitAIModule_Sub {
public:
    void* vtable;                    // +0x00
    char _gap_04[0x08];
    RGE_Player* player;              // +0x0C
    char _gap_10[0x28];
    float x_pos;                     // +0x38
    float y_pos;                     // +0x3C
    int field_40;                    // +0x40
};

class TribeTradeShipUnitAIModule {
public:
    void* vtable;                    // +0x00
    TribeTradeShipUnitAIModule_Sub* sub;  // +0x04

    int processIdle(int param_1);
};

int TribeTradeShipUnitAIModule::processIdle(int param_1)
{
    void* vt;

    if (!this->sub->player->computerPlayer())
        return 5;

    vt = *(void**)this;

    typedef int (__fastcall* FindTargetFunc)(TribeTradeShipUnitAIModule*, int, int, int, int, int, int);
    int targetId = (*((FindTargetFunc*)((DWORD*)vt + 0x40 / 4)))(
        this, 0, -1, -1, -1, -1, 0);

    if (targetId == -1)
        return 5;

    RGE_Static_Object* target = this->sub->player->world->object(targetId);
    if (target == 0)
        return 5;

    typedef float (__fastcall* GetSpeedFunc)(TribeTradeShipUnitAIModule_Sub*, int);
    float speed = (*((GetSpeedFunc*)((DWORD*)this->sub->vtable + 0xFC / 4)))(this->sub, 0);

    float dx = target->world_x - this->sub->x_pos;
    float dy = target->world_y - this->sub->y_pos;
    float speed7 = speed * 7.0f;
    float dist = (float)sqrt(dx * dx + dy * dy);

    float move_x = this->sub->x_pos - (dx / dist) * speed7;
    float move_y = this->sub->y_pos - (dy / dist) * speed7;

    typedef void (__fastcall* MoveFunc)(TribeTradeShipUnitAIModule*, int, float, float, int, int);
    (*((MoveFunc*)((DWORD*)vt + 0x9C / 4)))(
        this, 0, move_x, move_y, this->sub->field_40, 1);

    return 6;
}
