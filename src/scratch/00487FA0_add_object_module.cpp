// 00487FA0 TRIBE_RMM_Database_Controller::add_object_module
// Attempt log:
// baseline: natural reconstruction from the packet with exact random-map record layouts.
// moved locals to function scope and removed cached record indices; recovered 0x14 frame,
// 1749-byte output, and 89.9% instruction-shape similarity.
// typed aggregate land-line shift is the closest copy basin; raw dword cursors changed
// the saved-this register and were rolled back. Protected base declaration matches the
// original direct-call symbol. Final land-id gate follows the observed test/jl.
// paused after the hypothesis budget: remaining mismatch begins in the backward land-line
// shift/register coloring, with later drift largely a resynchronization consequence.
// resumed: direct indexed aggregate assignment exactly restored the original rep movsd shift.
// direct map member reads plus moving wall_1 after the center calculations now match the
// complete map_type==6 block through 004880F5; the unresolved basin begins in the first
// land-size adjustment loop (count/register and pointer topology).
// rolled back counter initialization inside the land-count guard; it worsened edit alignment.
// paused after the second budget: best rebuilt size/frame are exact, calls are 11/11 aligned,
// and the remaining structural mismatch starts at the land-size adjustment loop.

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

        i = 0;
        if (this->land_info.land_num > 0) {
            long* p = &this->land_info.land[0].land_size;
            do {
                *p -= ((this->map_height + this->map_width) * count) / this->land_info.land_num;
                ++i;
                p += 13;
            } while (i < this->land_info.land_num);
        }

        i = 0;
        index1 = 0;
        if (count > 0) {
            do {
                int land_count = this->land_info.land_num;
                this->land_info.land[i + land_count].terrain_type = 0;
                this->land_info.land[i + this->land_info.land_num].area = 7;
                this->land_info.land[i + this->land_info.land_num].base_size = 3;
                this->land_info.land[i + this->land_info.land_num].zone = (uchar)i + (uchar)this->land_info.land_num;
                this->land_info.land[i + this->land_info.land_num].land_size = (long)((double)(this->map_width + this->map_height) * DAT_00571f40);
                this->land_info.land[i + this->land_info.land_num].clumpiness_factor = 10;
                this->land_info.land[i + this->land_info.land_num].wall_1_avoidance_line = this->land_info.wall_1_avoidance_line;
                this->land_info.land[i + this->land_info.land_num].wall_2_avoidance_line = this->land_info.wall_2_avoidance_line;
                this->land_info.land[i + this->land_info.land_num].wall_3_avoidance_line = this->land_info.wall_3_avoidance_line;
                this->land_info.land[i + this->land_info.land_num].wall_4_avoidance_line = this->land_info.wall_4_avoidance_line;
                this->land_info.land[i + this->land_info.land_num].wall_fade = this->land_info.wall_fade;

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
                            if (!done)
                                goto found_bad_position;
                            if ((x - p[-1]) * (x - p[-1]) + (y - p[0]) * (y - p[0]) < 400)
                                done = 0;
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

                this->land_info.land[i + this->land_info.land_num].x = x;
                this->land_info.land[i + this->land_info.land_num].y = y;

                this->object_info.objects[this->object_info.object_num].terrain = -1;
                this->object_info.objects[this->object_info.object_num].group_flag = 2;
                this->object_info.objects[this->object_info.object_num].scale_flag = 0;
                this->object_info.objects[this->object_info.object_num].object_number_per_group = 8;
                this->object_info.objects[this->object_info.object_num].object_number_varience = 0;
                this->object_info.objects[this->object_info.object_num].number_of_groups = 1;
                this->object_info.objects[this->object_info.object_num].group_area = 4;
                this->object_info.objects[this->object_info.object_num].player_id = 0;
                this->object_info.objects[this->object_info.object_num].land_id = i + this->land_info.land_num;
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
                this->object_info.lands[this->object_info.land_num].id = i + this->land_info.land_num;
                this->object_info.lands[this->object_info.land_num].player_id = 0;
                ++this->object_info.land_num;
                ++i;
            } while (i < count);
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
            } else if (p[-3] == -2) {
                switch (p[-11]) {
                case 0x3B:
                case 0x42:
                    *p = this->map->map_width / 6;
                    break;
                case 0x41:
                    *p = this->map->map_width / 8;
                    break;
                case 0x66:
                    *p = this->map->map_width / 6;
                    break;
                }
            }
            ++i;
            p += 12;
        } while (i < this->object_info.object_num);
    }

    int r = debug_rand((char*)0x585E04, 0x236);
    TDebuggingLog::Log(debug_log, (char*)0x585E7C, r);
}
