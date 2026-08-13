// VA: 004852D0 RGE_RMM_Land_Generator::check_terrain_and_zone
// rmm_land.cpp lines 57-140
// Attempt log:
// - baseline: restored the typed RGE_Random_Map_Module/RGE_Land_Info ownership
//   and the ordinary terrain/zone scan; 412 B, frame 0x20, one ftol call.
// - layout: an explicit typed land-record pointer and direct two-cell gate
//   removed the ftol call and shortened the function; rolled back.
// - behavior: restoring the radius-derived gate kept the ftol call and moved
//   the resynchronization diff closer, but the original comparisons visibly
//   use y-2/y+2, so this was diagnostic only.
// - layout/context: raw land anchors and the minimal same-TU generator surface
//   preserved the target displacement shape but stayed in the same 0x20-frame
//   basin; no shared ABI fact justified keeping those forms.
// - liveness/abi: declaration-order, y-origin, and long-local probes were
//   duplicate or nonproductive.  Removing one diagnostic radius bound reached
//   the target 0x1c frame (396 B, 67.13% shape) but retained the wrong gate.
// - final canonical reset: named typed ownership and the binary-proven y-2/y+2
//   terrain-zone test are retained.  The remaining issue is the VC5 local-home
//   and register basin (target 0x1c frame, EBP-held row origin, and the observed
//   ftol/radius stack stores); no natural bounded probe found the transition.
// - behavior: added named radius_y1/radius_y2 bounds after the clamp as a
//   redundant vertical gate while leaving the terrain scan otherwise unchanged.

typedef unsigned char uchar;

struct RGE_Land_Info_Line {
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    uchar zone;
    uchar pad_19[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar pad_31[3];
};

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];
    long land_num;
    uchar base_terrain;
    uchar pad_1421[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar pad_1435[3];
};

class RGE_Random_Map_Module {
public:
    virtual uchar generate() = 0;
    RGE_Random_Map_Module* parent;
    void* list;
    void* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    uchar* search_map;
    uchar** search_map_rows;
    void* stack_array;
    void* stack_offsets;
};

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    RGE_Land_Info info;

    uchar check_terrain_and_zone(uchar unused, uchar land_id, long x, long y);
};

extern double dbl_571ED0;

uchar RGE_RMM_Land_Generator::check_terrain_and_zone(uchar unused, uchar land_id, long x, long y)
{
    long count = 0;
    long area = this->info.land[land_id].area;
    long x1 = x - area;
    long y1 = y - area;
    long x2 = x + area;
    long y2 = y + area;
    long cx1 = x - 2;
    long cy1 = y - 2;
    long cx2 = x + 2;
    long cy2 = y + 2;
    long radius = (long)((double)area * dbl_571ED0);
    uchar zone = this->info.land[land_id].zone;
    uchar** rows = this->search_map_rows;

    if ((int)rows[y][x] != this->info.land_num) {
        return 0;
    }

    // The executable performs this radius calculation and clamps it, but its
    // later zone-window comparisons are the independently observed +/-2
    // bounds above rather than the radius result.
    if (radius < 2) {
        radius = 2;
    }
    long radius_y1 = y - radius;
    long radius_y2 = y + radius;

    long yy = y - area;
    long xx;
    if (yy > y + area) {
        return (uchar)count;
    }

    do {
        if (yy < 0) {
            if (yy > cy1) {
                count += 5;
            }
        } else if (yy >= this->map_height) {
            if (yy < cy2) {
                count += 5;
            }
        } else {
            xx = x1;
            if (xx <= x2) {
                do {
                    if (xx < 0) {
                        if (xx > cx1) {
                            count++;
                        }
                    } else if (xx >= this->map_width) {
                        if (xx < cx2) {
                            count++;
                        }
                    } else {
                        if (rows[yy][xx] == zone) {
                            if (yy >= radius_y1 && yy <= radius_y2 &&
                                yy >= cy1 && yy <= cy2 && xx >= cx1 && xx <= cx2) {
                                count++;
                            }
                        } else if ((int)rows[yy][xx] < this->info.land_num) {
                            return 0;
                        }
                    }
                    xx++;
                } while (xx <= x2);
            }
        }
        yy++;
    } while (yy <= y + area);

    return (uchar)count;
}
