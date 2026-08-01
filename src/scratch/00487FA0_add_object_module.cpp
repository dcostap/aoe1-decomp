// 00487FA0 TRIBE_RMM_Database_Controller::add_object_module
// Attempt log (condensed after 89 total meaningful probes):
// - Natural typed reconstruction recovered the exact 1749-byte size, 0x14 frame, saved
//   registers, and 11/11 ordered direct calls. Direct indexed aggregate assignment restored
//   the original rep movsd land shift. Precomputing land_size_adjustment recovered the target
//   idiv/test/pointer loop; the positive `done` guard recovered the 73-insn collision island.
// - Current best: 93.60% instruction shape, 57.29% exact-block coverage, raw edit cost 194
//   (5.55% bounded), 480/484 instructions, and first strict mismatch +0x161. The mismatch is
//   still structural, so this function is not eligible for accepted drift.
// - DIA/asm stack topology (entry-relative after sub esp,14h and four pushes): compiler
//   temporary local_4 at -0x04; collision index home local_8 at -0x08; long index1 retry
//   counter at -0x0C; long count island count at -0x10; uchar done at -0x11; and long
//   extra_island_roll at -0x14. The last two homes overlap after their disjoint lifetimes.
//   PDB line changes for 449-521 and 525-567 are consistent with the retained statement order.
// - Exact layouts are RGE_Random_Map_Module 0x30, land_info 0x1438 at +0x3C,
//   object_info 0x18C8 at +0x270C, and controller size 0x4F5C. A full polymorphic RGE_Map
//   declaration emitted the same target code; broader same-TU context remains uncalibrated.
// - Exhausted natural loop/index spellings: operand order, casts, typed/raw member surfaces,
//   pointer subscripting, aliases, scopes, for/do forms, zone order, and grouped assignments.
//   Focused micro-tests also emit the rebuilt two-op `load member; add index` form. Corpus-only
//   motif hits 0044B950 (scratch) and 004D84E0 (unclaimed) have no exact source donor.
// - Exhausted tail spellings: case order, direct/local loads, separate/goto/shared-label arms,
//   assignment forms, rereads, and line grouping. VC5 keeps merging the two /6 source arms;
//   original blocks B050/B051 remain absent. Flag presets plus /G5 and /G6 were worse.
// - Diagnostic only: `volatile long extra_island_roll` improved shape to 94.375% and strict
//   diff to 1191, but added stores/reloads absent from the original and restored no blocks.
//   Its emitted changes begin only at +0x5F3, proving tail liveness sensitivity but not a
//   shared cause for the earlier index blocks. The valid best was restored afterward.
// - Remaining independent gaps: B025's eleven three-op index sums, B036/B039 index scheduling,
//   and the late switch blocks B050/B051. Do not run more broad expression, tail, or flag labs.
//   Next leads are an exact-register-environment micro-test for the early index basin and one
//   defined two-predecessor tail-local experiment that does not rely on an uninitialized value.

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);
extern double DAT_00571f38;
extern double DAT_00571f40;

class TDebuggingLog {
public:
    static void Log(TDebuggingLog* log, char* format, ...);
};

class RGE_Game_World;

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
};

class TRIBE_Game {
public:
    enum Age { Age_0 = 0, Age_1 = 1 };
    Age startingAge();
};

#define rge_base_game (*(TRIBE_Game**)0x62C574)
#define debug_log (*(TDebuggingLog**)0x62C4FC)

struct RGE_Land_Info_Line {
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    uchar zone;
    uchar gap_19[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar gap_31[3];
};

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];
    long land_num;
    uchar base_terrain;
    uchar gap_1421[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
    uchar gap_1435[3];
};

struct RGE_Land_Point_Info_Line {
    long x;
    long y;
    long id;
    long player_id;
};

struct RGE_Object_Info_Line {
    long obj_id;
    long terrain;
    uchar group_flag;
    uchar scale_flag;
    uchar gap_0a[2];
    long object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
    long object_exclusion_zone;
};

struct RGE_Object_Info {
    RGE_Object_Info_Line objects[99];
    long object_num;
    RGE_Land_Point_Info_Line lands[99];
    long land_num;
};

class RGE_Random_Map_Module {
public:
    virtual uchar generate();
    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    uchar** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    uchar* search_map;
    uchar** search_map_rows;
    void* stack_array;
    void* stack_offsets;
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    long map_type;
    long number_of_players;
    RGE_Land_Info land_info;
    uchar terrain_info[0x1298];
    RGE_Object_Info object_info;
    uchar elevation_info[0xF80];
    long map_num;
    void* maps;

protected:
    virtual void add_land_module(uchar param_1);
    virtual void add_terrain_module();
    virtual void add_object_module();
    virtual void add_elevation_module();
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    virtual void add_object_module();
};

void TRIBE_RMM_Database_Controller::add_object_module()
{
    uchar done;
    long count;
    long index1;
    int local_8;
    int i;
    int x;
    int y;
    long extra_island_roll;

    this->RGE_RMM_Database_Controller::add_object_module();
    debug_rand((char*)0x585E04, 0x198);

    if (rge_base_game->startingAge() == 1) {
        i = 0;
        if (this->object_info.object_num > 0) {
            long* p = &this->object_info.objects[0].number_of_groups;
            do {
                if (p[-5] == 0x53)
                    *p = 1;
                ++i;
                p += 12;
            } while (i < this->object_info.object_num);
        }

        i = 0;
        if (this->object_info.object_num > 0) {
            long* p = &this->object_info.objects[0].number_of_groups;
            do {
                if (p[-5] == 0x6D)
                    *p = 0;
                ++i;
                p += 12;
            } while (i < this->object_info.object_num);
        }
    }

    if (this->map_type == 6) {
        i = this->land_info.land_num;
        if (i > 0) {
            for (; i > 0; --i)
                this->land_info.land[i] = this->land_info.land[i - 1];
        }

        long map_width = this->map_width;
        long sixth = map_width / 6;
        long map_height = this->map_height;
        this->land_info.land[0].zone = (uchar)this->land_info.land_num;
        this->land_info.land[0].terrain_type = 1;
        this->land_info.land[0].area = 7;
        this->land_info.land[0].base_size = 2;
        this->land_info.land[0].land_size = (long)((double)((this->map_height - sixth * 2) * (this->map_width - sixth * 2)) * DAT_00571f38);
        this->land_info.land[0].clumpiness_factor = 10;
        this->land_info.land[0].x = this->map->map_width / 2;
        this->land_info.land[0].y = this->map->map_height / 2;
        this->land_info.land[0].wall_1_avoidance_line = sixth;
        this->land_info.land[0].wall_2_avoidance_line = sixth;
        this->land_info.land[0].wall_3_avoidance_line = map_width - sixth;
        this->land_info.land[0].wall_4_avoidance_line = map_height - sixth;
        this->land_info.land[0].wall_fade = 10;
        ++this->land_info.land_num;
    }

    if (this->map_type < 2) {
        count = (debug_rand((char*)0x585E04, 0x1C3) * 4) / 0x7FFF + 1;
        if (count + this->number_of_players > 10)
            count = 10 - this->number_of_players;

        long land_size_adjustment = ((this->map_height + this->map_width) * count) / this->land_info.land_num;
        i = 0;
        if (this->land_info.land_num > 0) {
            long* p = &this->land_info.land[0].land_size;
            do {
                *p -= land_size_adjustment;
                ++i;
                p += 13;
            } while (i < this->land_info.land_num);
        }

        index1 = 0;
        for (i = 0; i < count; ++i) {
            this->land_info.land[this->land_info.land_num + i].terrain_type = 0;
            this->land_info.land[this->land_info.land_num + i].area = 7;
            this->land_info.land[this->land_info.land_num + i].base_size = 3;
            this->land_info.land[this->land_info.land_num + i].zone = (uchar)i + (uchar)this->land_info.land_num;
            this->land_info.land[this->land_info.land_num + i].land_size = (long)((double)(this->map_width + this->map_height) * DAT_00571f40);
            this->land_info.land[this->land_info.land_num + i].clumpiness_factor = 10;
            this->land_info.land[this->land_info.land_num + i].wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
            this->land_info.land[this->land_info.land_num + i].wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
            this->land_info.land[this->land_info.land_num + i].wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
            this->land_info.land[this->land_info.land_num + i].wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
            this->land_info.land[this->land_info.land_num + i].wall_fade = this->land_info.wall_fade;

            local_8 = 0;
            index1 = 0;
            do {
                ++index1;
                done = 1;
                x = (debug_rand((char*)0x585E04, 0x1DE) * (this->map_width - 0x10)) / 0x7FFF + 8;
                y = (debug_rand((char*)0x585E04, 0x1DF) * (this->map_height - 0x10)) / 0x7FFF + 8;
                local_8 = 0;
                if (this->land_info.land_num > 0) {
                    long* p = &this->land_info.land[0].y;
                    do {
                        if (done) {
                            if ((x - p[-1]) * (x - p[-1]) + (y - p[0]) * (y - p[0]) < 400)
                                done = 0;
                        } else {
                            goto found_bad_position;
                        }
                        ++local_8;
                        p += 13;
                    } while (local_8 < this->land_info.land_num);
                }
                if (done)
                    break;
found_bad_position:
                ;
            } while (index1 < 1000);

            if (index1 >= 1000)
                count = i;

            this->land_info.land[this->land_info.land_num + i].x = x;
            this->land_info.land[this->land_info.land_num + i].y = y;

            this->object_info.objects[this->object_info.object_num].terrain = -1;
            this->object_info.objects[this->object_info.object_num].group_flag = 2;
            this->object_info.objects[this->object_info.object_num].scale_flag = 0;
            this->object_info.objects[this->object_info.object_num].object_number_per_group = 8;
            this->object_info.objects[this->object_info.object_num].object_number_varience = 0;
            this->object_info.objects[this->object_info.object_num].number_of_groups = 1;
            this->object_info.objects[this->object_info.object_num].group_area = 4;
            this->object_info.objects[this->object_info.object_num].player_id = 0;
            this->object_info.objects[this->object_info.object_num].land_id = this->land_info.land_num + i;
            this->object_info.objects[this->object_info.object_num].land_inner_radius = 0;
            this->object_info.objects[this->object_info.object_num].land_outer_radius = 0x1A;
            this->object_info.objects[this->object_info.object_num].object_exclusion_zone = 0;
            if (debug_rand((char*)0x585E04, 0x1FD) < 0x3FFF)
                this->object_info.objects[this->object_info.object_num].obj_id = 0x66;
            else
                this->object_info.objects[this->object_info.object_num].obj_id = 0x42;

            ++this->object_info.object_num;
            this->object_info.lands[this->object_info.land_num].y = y;
            this->object_info.lands[this->object_info.land_num].x = x;
            this->object_info.lands[this->object_info.land_num].id = this->land_info.land_num + i;
            this->object_info.lands[this->object_info.land_num].player_id = 0;
            ++this->object_info.land_num;
        }
        this->land_info.land_num += count;
    }

    i = 0;
    if (this->object_info.object_num > 0) {
        long* p = &this->object_info.objects[0].object_exclusion_zone;
        do {
            if (p[-3] >= 0) {
                switch (p[-11]) {
                case 0x3B:
                case 0x41:
                case 0x42:
                case 0x66:
                    *p = 0xC;
                    break;
                }
                goto object_exclusion_done;
            }
            if (p[-3] != -2)
                goto object_exclusion_done;
            switch (p[-11]) {
            case 0x3B:
            case 0x42:
                extra_island_roll = this->map->map_width;
                goto divide_by_six;
            case 0x41:
                extra_island_roll = this->map->map_width;
                *p = extra_island_roll / 8;
                break;
            case 0x66:
                extra_island_roll = this->map->map_width;
divide_by_six:
                *p = extra_island_roll / 6;
                break;
            }
object_exclusion_done:
            ++i;
            p += 12;
        } while (i < this->object_info.object_num);
    }

    int r = debug_rand((char*)0x585E04, 0x236);
    TDebuggingLog::Log(debug_log, (char*)0x585E7C, r);
}
