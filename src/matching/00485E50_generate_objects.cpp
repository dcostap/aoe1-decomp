// 00485E50 RGE_RMM_Object_Generator::generate_objects
// Source: rmm_obj.cpp lines 90-114, size 184 bytes
// MATCH: the authentic rmm_obj prefix emits all 184 bytes exactly.
// The configured matching owner needs both PDB-backed context views: the
// complete base method order and the complete world virtual surface. The old
// narrow world view matched only under the accepted_drift include path. Moving
// that unchanged source restored the two-byte width/height load-order drift.
// Exact-finish reduction removed scale temporaries and the input pointer alias.
// Direct width * height source, its reversed form, and compound products emit
// the same exact body. The conventional direct product remains.
// The typed land-record loop is also required. Running-field cursors, explicit
// count guards, and do-while forms lose exactness.

#include "..\..\include\game_types.h"
#include <string.h>
#include "..\..\include\rmm_obj_context.h"

void RGE_RMM_Object_Generator::generate_objects(RGE_Object_Info_Line& line) {
    if (line.scale_flag) {
        long n = (this->map_width * this->map_height *
                  line.number_of_groups) / 0x5100;
        line.number_of_groups = n;
        if (n < 1) {
            line.number_of_groups = 1;
        }
    }

    if (line.land_id >= 0) {
        for (int i = 0; i < this->info.land_num; i++) {
            RGE_Land_Point_Info_Line& land = this->info.lands[i];
            if (land.id == line.land_id) {
                this->place_land_objects(line, land.x, land.y, line.land_inner_radius, line.land_outer_radius, i);
            }
        }
    } else if (line.land_id == -1) {
        this->place_objects(line);
    } else if (line.land_id == -2) {
        this->place_avoid_objects(line, line.land_inner_radius);
    }
}
