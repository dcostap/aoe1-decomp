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

#include "..\..\include\game_types.h"
#include <string.h>

class RGE_Map;
class RGE_Random_Map_Module;
class RGE_Game_World;

class RGE_Land_Point_Info_Line {
public:
    long x;         // +0x00
    long y;         // +0x04
    long id;        // +0x08
    long player_id; // +0x0C
};

class RGE_Object_Info_Line {
public:
    long obj_id;                    // +0x00
    long terrain;                   // +0x04
    unsigned char group_flag;       // +0x08
    unsigned char scale_flag;       // +0x09
    unsigned char _pad_0[2];        // +0x0A
    long object_number_per_group;   // +0x0C
    long object_number_varience;    // +0x10
    long number_of_groups;          // +0x14
    long group_area;                // +0x18
    long player_id;                 // +0x1C
    long land_id;                   // +0x20
    long land_inner_radius;         // +0x24
    long land_outer_radius;         // +0x28
    long object_exclusion_zone;     // +0x2C
};

class RGE_Object_Info {
public:
    RGE_Object_Info_Line objects[99];   // +0x00 (size 0x1290)
    long object_num;                    // +0x1290
    RGE_Land_Point_Info_Line lands[99]; // +0x1294 (size 0x630)
    long land_num;                      // +0x18C4
};

class RGE_Random_Map_Module {
public:
    void* vtable_ptr;                   // +0x00
    RGE_Random_Map_Module* parent;      // +0x04
    void* list;                         // +0x08
    RGE_Map* map;                       // +0x0C
    void* map_row_offset;               // +0x10
    long map_width;                     // +0x14
    long map_height;                    // +0x18
    float schedule;                     // +0x1C
    unsigned char* search_map;          // +0x20
    unsigned char** search_map_rows;    // +0x24
    void* stack_array;                  // +0x28
    void** stack_offsets;               // +0x2C

    RGE_Random_Map_Module(RGE_Map* param_1, RGE_Random_Map_Module* param_2, unsigned char param_3);
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;                  // +0x30
    RGE_Object_Info info;                    // +0x34 (size 0x18C8)

    void generate_objects(RGE_Object_Info_Line& line);
    void place_objects(RGE_Object_Info_Line& line);
    void place_land_objects(RGE_Object_Info_Line& line, long x, long y, long inner_radius, long outer_radius, long index);
    void place_avoid_objects(RGE_Object_Info_Line& line, long radius);
};

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
