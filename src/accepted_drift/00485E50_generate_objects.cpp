// 00485E50 RGE_RMM_Object_Generator::generate_objects
// Source: rmm_obj.cpp lines 90-114, size 184 bytes
// Attempt log:
// first: 85% diff — wrong multiply (32-bit overflow instead of 64-bit imul), wrong register allocation, wrong code structure
// second: 62% — multiplied matched (division by 0x5100 triggers imul+shift), code structure better
// third: 98.9% (182/184 equal) — land_id stack spill fixed by using line.land_id directly instead of local
//       Prologue matched (esi=param, ebx=this) by using local RGE_Object_Info_Line* l = &line;
// Remaining: 4 bytes (2 edit bytes) — lea edi,[ebx+12CCh] and jle swapped scheduling
//       lea moved before jle in original, after in rebuilt. Displacement changed by 6.
// Parked: pure VC5 scheduling drift, 2 instructions swapped, no behavioral difference
// Context pass: the shared rmm_obj declaration surface is now used by the full
// owner prefix. Standalone drift is 8 bytes; calls and behavior remain aligned.

#include "..\..\include\game_types.h"
#include <string.h>
#include "..\..\include\rmm_obj_context.h"

void RGE_RMM_Object_Generator::generate_objects(RGE_Object_Info_Line& line) {
    RGE_Object_Info_Line* l = &line;

    if (l->scale_flag) {
        long h = this->map_height;
        long w = this->map_width;
        long g = line.number_of_groups;
        long n = (h * w * g) / 0x5100;
        line.number_of_groups = n;
        if (n < 1) {
            line.number_of_groups = 1;
        }
    }

    if (line.land_id >= 0) {
        long* p = &this->info.lands[0].y;
        for (int i = 0; i < this->info.land_num; i++, p += 4) {
            if (p[1] == line.land_id) {
                this->place_land_objects(line, p[-1], p[0], line.land_inner_radius, line.land_outer_radius, i);
            }
        }
    } else if (line.land_id == -1) {
        this->place_objects(line);
    } else if (line.land_id == -2) {
        this->place_avoid_objects(line, line.land_inner_radius);
    }
}
