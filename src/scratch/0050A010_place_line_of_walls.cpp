// VA: 0050A010, TRIBE_Command::place_line_of_walls, 291 bytes
// Source: tcommand.cpp lines 456-503
// FLAGS: default
//
// Attempt log:
// v1-v3: Non-static member. Correct size (291B). 79% match. Main diff:
//   - Original reads start_x into ecx (overwriting this), mine reads into eax
//   - Cascading register swap throughout (ecx↔eax, some stack offset shifts)
// v4-v5: Static member (no this). 288 bytes (3 short), different register alloc.
// v6-v10: Various approaches to force ecx allocation (goto, sign-trick variants,
//   removing vtable local var). Best result: 82% match (238/291 bytes equal).
// 
// Remaining structural mismatches vs original:
// 1. REGISTER: Original uses ecx for start_x (overwrites this). VC5 with
//    modern compiler keeps this alive and uses eax for start_x.
// 2. BYTE EXTENSION: Original `mov cl,[esi+64h]` doesn't zero-extend the
//    type byte before push ecx (relies on old ecx hi-bytes). VC5 always
//    zero-extends via `xor ecx,ecx; mov cl,...` or `movzx`.
// 3. VTABLE READ: Original reads vtable[0x20] into local [esp+18h],
//    then reads vtable[0x3C] fresh from [esi] each loop. My code reads
//    vtable[0x20] once into canPlace local.
// 4. SUB SIZE: Original sub esp,0Ch (3 local dwords). VC5 generates
//    sub esp,10h+ due to extra zero-init or vtable temp.
// All four differences are VC5 codegen policy choices that C++ source
// cannot control without inline asm (forbidden for real functions).

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

class RGE_Static_Object;
class TRIBE_Master_Building_Object;

class TRIBE_Player {
public:
    uchar pay_obj_cost(short obj_id, float cost, int zero);
};

typedef int (__stdcall* CanPlaceFn)(TRIBE_Player*, float, float, int, int, int, int, int, int, int);
typedef RGE_Static_Object* (__fastcall* BuildFn)(TRIBE_Master_Building_Object*, int, TRIBE_Player*, float, float, int, int);

class TRIBE_Command {
public:
    void place_line_of_walls(
        TRIBE_Player* pPlayer,
        TRIBE_Master_Building_Object* pBuilding,
        int param_3,
        int start_x,
        int start_y,
        int end_x,
        int end_y,
        RGE_Static_Object** ppResult
    );
};

void TRIBE_Command::place_line_of_walls(
    TRIBE_Player* pPlayer,
    TRIBE_Master_Building_Object* pBuilding,
    int param_3,
    int start_x,
    int start_y,
    int end_x,
    int end_y,
    RGE_Static_Object** ppResult)
{
    int step_x, step_y;

    if (start_x == end_x)
        step_x = 0;
    else
        step_x = (((int)(end_x <= start_x) - 1) & 2) - 1;

    if (start_y == end_y)
        step_y = 0;
    else
        step_y = (((int)(end_y <= start_y) - 1) & 2) - 1;

    // Reuse param slots
    { int t = start_x; start_x = start_y; start_y = t; }

    void* canPlace = ((void***)pBuilding)[0][8];

    while (1) {
        float fx = (float)start_y - 0.5f;
        float fy = (float)start_x - 0.5f;

        uchar ot = *(uchar*)((char*)pBuilding + 0x64);

        if (((CanPlaceFn)canPlace)(pPlayer, fx, fy, 0, 1, ot, 0, 1, 1, 1) == 0) {
            short oi = *(short*)((char*)pBuilding + 0x10);
            if (pPlayer->pay_obj_cost(oi, 1.0f, 0) != 0) {
                RGE_Static_Object* obj = ((BuildFn)((void***)pBuilding)[0][15])(pBuilding, 0, pPlayer, fx, fy, 0, param_3);
                if (obj != 0 && *ppResult == 0)
                    *ppResult = obj;
            }
        }

        if (start_y == end_x && start_x == end_y)
            break;

        start_y += step_x;
        start_x += step_y;
    }
}
