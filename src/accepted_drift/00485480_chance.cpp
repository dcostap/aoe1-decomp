// 00485480 chance
// rmm_land.cpp:146-208, 159 bytes
// Round2 pass: 12 focused variants tried: typed LandInfo at +0x50 vs raw this+id*52
// base, early return vs shared return, >0 vs <=0 fade gate, named/deferred x_chance,
// register hints, direct wall3 reloads, and positive-Y arithmetic order variants.
// Best retained source is exact-size and behavior-equivalent but non-exact:
// MISMATCH 11.9497% positional / 11.9497% edit, first mismatch 37.
// Remaining drift is localized: EBX/EBP allocation swap for wall3/x_chance, equivalent
// positive-Y arithmetic scheduling, and ECX/EDX choice for fade multiply. Candidate only.

#include "../../include/rmm_land_context.h"

// The accepted-drift owner keeps its proved flat address basin. The complete
// RMM land surface is canonical in the shared context; this narrow overlay is
// retained only for the original owner-local codegen shape.
struct LandInfo_00485480 {
    char gap0[0x50];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
};

unsigned char RGE_RMM_Land_Generator::chance(long x, long y, long land_id)
{
    LandInfo_00485480* land_info =
        (LandInfo_00485480*)((char*)this + land_id * 52);
    unsigned char fade = land_info->wall_fade;
    if (fade > 0) {
        long wall_1 = land_info->wall_1_avoidance_line;
        long xpos = x;
        long wall_3 = land_info->wall_3_avoidance_line;
        long a = wall_1 - xpos;
        xpos -= wall_3;
        long x_chance = a;
        if (a <= xpos)
            x_chance = xpos;

        long right = *(long*)((char*)this + 0x14);
        a += wall_1;
        right -= wall_3;
        xpos += right;
        if (a <= xpos)
            a = xpos;

        long wall_2 = land_info->wall_2_avoidance_line;
        if (a > 0) {
            long wall_4 = land_info->wall_4_avoidance_line;
            long ypos = y;
            wall_2 += a;
            a -= wall_4;
            wall_2 -= ypos;
            a += ypos;
        } else {
            a = y;
            long wall_4 = land_info->wall_4_avoidance_line;
            wall_2 -= a;
            a -= wall_4;
        }

        if (wall_2 > a)
            a = wall_2;
        if (x_chance < 0)
            x_chance = 0;
        if (a < 0)
            a = 0;

        a += x_chance;
        a *= (unsigned char)fade;
        if (a >= 100)
            return 101;
        return (unsigned char)a;
    }
    return 0;
}
