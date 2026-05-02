// 00506A70 TribeTransportShipUnitAIModule::processIdle (taiuaimd.cpp:2122-2147)
// int __thiscall processIdle(int param_1)
//
// PARKED - VC5 FPU scheduling basin mismatch.
// Remaining drift: FPU register scheduling in the math block (different fxch/fst/faddp patterns),
// and extra `xor edx,edx` from __fastcall workaround for vtable function calls.
// 
// Attempts:
// 1. __fastcall function pointers, early returns → inline epilogues (88.4%)
// 2. Result variable approach → shared epilogue but extra ebp (86.4%)
// 3. Nested if/return 6 → shared epilogue, ebx=vt cache, but FPU math differs (66.4%)
// 4-6. Split speed7 local, various FPU expression forms → same 55-byte edit diff basin
//
// The control flow, register allocation (esi=this, ebx=vt, edi=target), and all non-FPU
// code paths match the original. Only the FPU scheduling in the dx/dy/dist/speed7 block
// diverges (fxch/fst/faddp/fchs patterns, fsubr vs fchs+fadd).

#include <math.h>

typedef unsigned long DWORD;

class RGE_Game_World;

class RGE_Player {
public:
    char _gap_00[0x3C];
    RGE_Game_World* world;
    int computerPlayer();
};

class RGE_Game_World {
public:
    class RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    char _gap_00[0x38];
    float world_x;
    float world_y;
};

class TribeTransportShipUnitAIModule_Sub {
public:
    void* vtable;
    char _gap_04[0x08];
    RGE_Player* player;
    char _gap_10[0x28];
    float x_pos;
    float y_pos;
    int field_40;
};

class TribeTransportShipUnitAIModule {
public:
    void* vtable;
    TribeTransportShipUnitAIModule_Sub* sub;

    int processIdle(int param_1);
};

int TribeTransportShipUnitAIModule::processIdle(int param_1)
{
    if (this->sub->player->computerPlayer()) {
        void* vt = this->vtable;

        typedef int (__fastcall* FindTargetFunc)(void* _this, int _edx, int, int, int, int, int);
        int targetId = (*(FindTargetFunc*)((DWORD*)vt + 0x10))(
            this, 0, -1, -1, -1, -1, 0);

        if (targetId != -1) {
            RGE_Static_Object* target = this->sub->player->world->object(targetId);

            if (target != 0) {
                typedef float (__fastcall* GetSpeedFunc)(void* _this);
                float speed = (*(GetSpeedFunc*)((DWORD*)this->sub->vtable + 0x3F))(this->sub);

                float dx = target->world_x - this->sub->x_pos;
                float dy = target->world_y - this->sub->y_pos;
                float dist = (float)sqrt(dx * dx + dy * dy);

                float move_x = this->sub->x_pos - (dx / dist) * (speed * 7.0f);
                float move_y = this->sub->y_pos - (dy / dist) * (speed * 7.0f);

                typedef void (__fastcall* MoveFunc)(void* _this, int _edx, float, float, int, int);
                (*(MoveFunc*)((DWORD*)vt + 0x27))(this, 0, move_x, move_y, this->sub->field_40, 1);

                return 6;
            }
        }
    }

    return 5;
}
