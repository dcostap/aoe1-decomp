#ifndef RMM_LAND_H
#define RMM_LAND_H

// Owner declarations for C:\\msdev\\work\\age1_x1\\rmm_land.cpp.
// Map, tile, stack, and random-map base ownership comes from canonical
// headers. This header owns only the Land records and generator surface.
//
// PDB order: ctor 25-29, generate 33-51, check_terrain_and_zone 57-140,
// chance 146-208, and base_land_generate 213-353.

#include "rmm_base.h"

class RGE_Map;

struct RGE_Land_Info_Line {
    long land_size;                         // +0x00
    long terrain_type;                      // +0x04
    long x;                                  // +0x08
    long y;                                  // +0x0C
    long base_size;                         // +0x10
    long area;                              // +0x14
    uchar zone;                             // +0x18
    long clumpiness_factor;                 // +0x1C
    long wall_1_avoidance_line;             // +0x20
    long wall_2_avoidance_line;             // +0x24
    long wall_3_avoidance_line;             // +0x28
    long wall_4_avoidance_line;             // +0x2C
    uchar wall_fade;                        // +0x30
};

typedef char rmm_land_info_line_size_check[
    (sizeof(RGE_Land_Info_Line) == 0x34) ? 1 : -1];

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];            // +0x0000
    long land_num;                          // +0x141C
    uchar base_terrain;                     // +0x1420
    long wall_1_avoidance_line;             // +0x1424
    long wall_2_avoidance_line;             // +0x1428
    long wall_3_avoidance_line;             // +0x142C
    long wall_4_avoidance_line;             // +0x1430
    uchar wall_fade;                        // +0x1434
};

typedef char rmm_land_info_size_check[
    (sizeof(RGE_Land_Info) == 0x1438) ? 1 : -1];

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
protected:
    uchar check_terrain_and_zone(uchar unused, uchar land_id,
        long x, long y);
    uchar chance(long x, long y, long land_id);
    uchar base_land_generate();

public:
    RGE_Land_Info info;                     // +0x30

    RGE_RMM_Land_Generator(RGE_Map* map,
        RGE_Random_Map_Module* parent, RGE_Land_Info* info);
    virtual uchar generate();
};

typedef char rmm_land_generator_size_check[
    (sizeof(RGE_RMM_Land_Generator) == 0x1468) ? 1 : -1];

#endif
