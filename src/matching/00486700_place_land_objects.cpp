// VA: 00486700 RGE_RMM_Object_Generator::place_land_objects
// Attempt log:
// prior worker left a decompiler-shaped candidate with the wrong land/object ownership and no zone-map calls.
// baseline: canonical RMM info/land/player/master/zone-map ownership; natural pop_stack loop and placement gates.
// tried a radius alias and delayed line pointer; duplicate codegen.
// kept deinit_stack inside the non-null master arm; only the null-edge block improved.
// reloaded the player's master object inside the candidate loop; restored the missing second place_object site and reached the correct call set.
// restored the repeated pop_stack/count loop and reused dead coordinate homes; frame/CFG became exact-size.
// removed the radius alias; prologue and late layout regressed, then restored it.
// used a late y1 output local instead of mutating the radius formal; prologue and stack frame aligned, with four bytes of localized drift.
// swapping output-local declaration order was a codegen duplicate.
// swapped pop_stack output references; edit alignment changed but positional bytes did not improve.
// restored the binary-proven tile terrain low-five-bit mask; exact size/frame/instruction/call parity, 17 localized bytes remain in pop-stack homes and register coloring.
// reused the typed outer master pointer for the per-candidate reload; codegen was a duplicate and the first pop-stack hunk did not move.
// aligned the pop_stack coordinate roles with get_zone_info rows[param2][param1]; swapping y1/min_x0 and all placement call arguments reduced the drift to one byte.
// reversed the zone equality operands to select the original memory-byte compare; exact match.

extern "C" void* __cdecl memset(void*, int, unsigned int);

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Tile {
    char gap_00[5];
    unsigned char terrain;
    char gap_06[0x18 - 0x06];
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
    unsigned char group_flag;
    unsigned char scale_flag;
    unsigned char gap_0a[2];
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

class RGE_Map;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Zone_Map;
class RGE_Zone_Map_List;

class RGE_Random_Map_Module {
public:
    void* vtable_ptr;
    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void set_search_area(long, long, long, unsigned char);
    void init_stack(Map_Stack&);
    void deinit_stack(Map_Stack&);
    void make_placement_stack(Map_Stack&, long, long, long, long);
    Map_Stack* pop_stack(Map_Stack&, long&, long&, float&);
    void remove_area_from_lists(long, long, long);
    void place_group(RGE_Object_Info_Line&, long, long, RGE_Player*);
    void place_cluster(RGE_Object_Info_Line&, long, long, RGE_Player*);
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
    char gap_44[0x10];
    float** terrains;
};

class RGE_Map {
public:
    char gap_00[0x8dc4];
    RGE_Zone_Map_List* map_zones;
};

class RGE_Zone_Map {
public:
    char gap_00[0x408];
    unsigned char** zone_map_rows;

    unsigned char get_zone_info(long, long);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    long zone_map_num;
    RGE_Map* map;

    RGE_Zone_Map* get_zone_map(float*, long, int&);
};

class RGE_Master_Static_Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual unsigned char can_place(RGE_Player*, float, float,
        int, int, int, int, int, int, int);

    char gap_04[0x30 - 0x04];
    float radius_x;
    float radius_y;
    char gap_38[0x66 - 0x38];
    short terrain;
};

class RGE_Player {
public:
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36();
    virtual void place_object(long, float, float, int, int);

    char gap_04[0x24 - 0x04];
    RGE_Master_Static_Object** master_objects;
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    RGE_Object_Info info;

    void place_land_objects(RGE_Object_Info_Line&, long, long, long, long, long);
};

void RGE_RMM_Object_Generator::place_land_objects(
    RGE_Object_Info_Line& line, long x, long y, long inner_radius,
    long outer_radius, long land_index)
{
    long radius = inner_radius;
    long min_x = x - radius;
    long min_y = y - radius;
    long max_x = x + radius;
    long max_y = y + radius;
    long min_x0;
    long y1;
    int zone_index;
    unsigned char zone;
    float cost;
    int temp;
    Map_Stack obj_stack;

    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x >= this->map_width) max_x = this->map_width - 1;
    if (max_y >= this->map_height) max_y = this->map_height - 1;

    memset(this->search_map, 1, this->map_width * this->map_height);

    int i = 0;
    if (this->info.land_num > 0) {
        RGE_Land_Point_Info_Line* land = this->info.lands;
        do {
            this->set_search_area(land->x, land->y, radius, 0);
            ++i;
            ++land;
        } while (i < this->info.land_num);
    }

    this->init_stack(obj_stack);
    this->make_placement_stack(obj_stack, x, y, radius, outer_radius);

    RGE_Object_Info_Line* object = &line;
    int player_id = 0;
    if (object->player_id > -1) {
        player_id = object->player_id;
    } else {
        int land_player_id = this->info.lands[land_index].player_id;
        if (land_player_id > 0) player_id = land_player_id;
    }

    RGE_Player* player = this->world->players[player_id];
    RGE_Master_Static_Object* master = player->master_objects[object->obj_id];
    if (master != 0) {
        RGE_Zone_Map* zone_map = this->map->map_zones->get_zone_map(
            this->world->terrains[master->terrain], 0x20, zone_index);
        zone = zone_map->get_zone_info(x, y);

        long count = object->number_of_groups;
        while (this->pop_stack(obj_stack, y1, min_x0, cost) != 0 &&
               count > 0) {
                if ((unsigned char)zone ==
                        zone_map->get_zone_info(y1, min_x0) &&
                    (object->terrain < 0 ||
                     (this->map_row_offset[min_x0][y1].terrain & 0x1f) ==
                         object->terrain) &&
                    (y1 <= min_x || y1 >= max_x ||
                     min_x0 <= min_y || min_x0 >= max_y)) {
                    float fx = (float)y1;
                    RGE_Master_Static_Object* placement_master =
                        player->master_objects[object->obj_id];
                    float fy = (float)min_x0;

                    temp = (short)(int)placement_master->radius_x;
                    if (0.0f < placement_master->radius_x - (float)temp) {
                        fx -= -0.5f;
                    }
                    temp = (short)(int)placement_master->radius_y;
                    if (0.0f < placement_master->radius_y - (float)temp) {
                        fy -= -0.5f;
                    }

                    if (!placement_master->can_place(player, fx, fy,
                        0, 0, 1, 1, 1, 1, 1)) {
                        this->remove_area_from_lists(y1, min_x0,
                            object->object_exclusion_zone);
                        switch (object->group_flag) {
                        case 0:
                            player->place_object(object->obj_id, fx, fy, 0, 1);
                            break;
                        case 1:
                            this->place_group(*object, y1, min_x0,
                                player);
                            break;
                        case 2:
                            this->place_cluster(*object, y1, min_x0,
                                player);
                            break;
                        }
                        --count;
                    } else if (object->group_flag == 0 && obj_stack.next == 0) {
                        player->place_object(object->obj_id, fx, fy, 0, 1);
                    }
                }
        }
        this->deinit_stack(obj_stack);
    }
}
