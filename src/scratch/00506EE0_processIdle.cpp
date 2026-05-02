// VA: 00506EE0 TribeFishingShipUnitAIModule::processIdle (250 bytes)
// PDB: taiuaimd.cpp lines 2281-2306
//
// Status: PARKED — calling convention issues prevent match
//
// Attempt log:
// v1: Direct goto-based flow with external __cdecl calls — 250 bytes, 86.8% diff
// v2: Changed to __fastcall for external calls — 250 bytes, 83.2% diff
// v3: Removed player local variable — 250 bytes, 77.2% diff
// v4: Added ebx vtable cache, used nested if/return pattern — 250 bytes, 62.4% diff
//     (23 bytes matching from start)
//
// Remaining issues:
// - Virtual calls through function pointers are __cdecl (push this on stack)
//   instead of __thiscall (ecx=this). Affects both find_id (vtable+0x40)
//   and move_to (vtable+0x9C) calls. Original uses:
//     mov ecx, esi; call [ebx+0x40]      (clean, no stack)
//   My version generates:
//     push esi; call [ebx+0x40]; add esp, 18h  (cdecl caller cleanup)
// - FPU computation order differs from original. Original interleaves
//   dx/dy computation with speed*7.0 multiply in a specific stack pattern.
// - sqrt is now inlined as fsqrt ✓
// - Frame setup matches ✓ (sub esp,8; push ebx/esi/edi)
// - Control flow now uses je near pattern ✓
// - Need proper __thiscall for vtable dispatch

#include <math.h>
#include <stddef.h>

struct RGE_Static_Object {
    void* vtable;
    char pad[0x34];
    float world_x;
    float world_y;
    int facing;
};

struct RGE_Game_World {
    RGE_Static_Object* object(int id);
};

int __fastcall RGE_Player__computerPlayer(void* player);

class TribeFishingShipUnitAIModule {
public:
    void* vtable;
    RGE_Static_Object* obj;
    char pad_08[0x12C];

    int processIdle(int param_1);
};

int TribeFishingShipUnitAIModule::processIdle(int param_1) {
    if (!RGE_Player__computerPlayer(*(void**)((char*)this->obj + 0xC)))
        return 5;

    {
        void* this_vt = this->vtable;
        int id = ((int (*)(void*, int, int, int, int, int))(((void**)this_vt)[0x10]))
            (this, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0);

        if (id != -1) {
            RGE_Static_Object* fish = ((RGE_Game_World*)*(void**)((char*)*(void**)((char*)this->obj + 0xC) + 0x3C))->object(id);

            if (fish) {
                float speed = ((float (__fastcall*)(void*))(((void***)this->obj)[0][0x3F]))(this->obj);
                float factor = speed * 7.0f;
                float dx = fish->world_x - this->obj->world_x;
                float dy = fish->world_y - this->obj->world_y;
                float dist = sqrt(dx * dx + dy * dy);

                ((int (*)(void*, float, float, int, int))(((void**)this_vt)[0x27]))
                    (this, -((dx / dist) * factor) + this->obj->world_x,
                     -((dy / dist) * factor) + this->obj->world_y,
                     this->obj->facing, 1);

                return 6;
            }
        }
    }

    return 5;
}
