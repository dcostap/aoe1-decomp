// 00485CB0 RGE_RMM_Object_Generator::add_quick_obj
// rmm_obj.cpp:46-62, 266 bytes, __thiscall
//
// The info record is the generator's named RGE_Object_Info_Line array.  The
// second argument supplies number_of_groups, while the third supplies
// object_exclusion_zone.
// Attempt log:
// - The prior raw-offset candidate used the second argument for the final
//   store and stalled at 256 bytes; that was not the observed third-argument
//   behavior and was discarded.
// - Adding the proven world pointer at +0x30 placed info/object_num at the
//   observed +0x34/+0x12C4 and produced an exact match.
// - Replacing the proven lands gap with its named array preserved the match.
// - Main-agent audit restored the inherited random-map-module virtual surface;
//   emitted code remains exact.

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

struct RGE_Land_Point_Info_Line {
    long x;
    long y;
    long id;
    long player_id;
};

struct RGE_Object_Info {
    RGE_Object_Info_Line objects[99];
    long object_num;
    RGE_Land_Point_Info_Line lands[99];
    long land_num;
};

class RGE_RMM_Object_Generator {
public:
    virtual unsigned char generate();
    unsigned char gap_04[0x2C];
    void* world;
    RGE_Object_Info info;

    void add_quick_obj(long obj_id, long number_of_groups,
        long object_exclusion_zone);
};

void RGE_RMM_Object_Generator::add_quick_obj(long obj_id,
    long number_of_groups, long object_exclusion_zone)
{
    this->info.objects[this->info.object_num].obj_id = obj_id;
    this->info.objects[this->info.object_num].terrain = -1;
    this->info.objects[this->info.object_num].group_flag = 0;
    this->info.objects[this->info.object_num].scale_flag = 0;
    this->info.objects[this->info.object_num].object_number_per_group = 1;
    this->info.objects[this->info.object_num].object_number_varience = 1;
    this->info.objects[this->info.object_num].number_of_groups = number_of_groups;
    this->info.objects[this->info.object_num].group_area = 2;
    this->info.objects[this->info.object_num].player_id = 0;
    this->info.objects[this->info.object_num].land_id = -1;
    this->info.objects[this->info.object_num].land_inner_radius = 0;
    this->info.objects[this->info.object_num].land_outer_radius = 1;
    this->info.objects[this->info.object_num].object_exclusion_zone = object_exclusion_zone;
    this->info.object_num = this->info.object_num + 1;
}
