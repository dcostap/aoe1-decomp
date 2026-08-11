// Attempt log for 004828B0 RGE_RMM_Controller::add_object_module
// try 1: manual object_info stack buffer/stores from packet plus natural new/ctor; too small 672B.
// try 2: /GX flag probe; unchanged too small 672B.
// try 3: /Oy- flag probe; too small 656B.
// try 4: /O1 flag probe; too small 625B.
// try 5: added placement-new surface for natural ctor; compiles but no size improvement.
// try 6: reviewed stack-frame target 0x18D0 and local object_info offset; broad alloca/EH frame likely close.
// try 7: reviewed constants/register reuse; manual stores likely too expression-collapsed vs original scheduled register constants.
// try 8: reviewed land-copy loop; source loop shape matches behavior but not validated.
// try 9: reviewed final operator new/ctor argument order; plausible but size short.
// try 10: left in scratch; current source is a behavior scaffold, not exact-size.
// BLOCKER: rebuilt .text 672B vs original 695B; missing exact large aggregate initialization schedule/register-lifetime and ctor/EH state shape. Not accepted_drift-safe.
// try 11: restored typed RGE_Object_Info/RGE_Map/RGE_Random_Map_Module ownership and a natural new-expression; test the constructor ABI and /GX EH state against the oracle.
// try 12: restored the polymorphic 0x30-byte RGE_Random_Map_Module base and inherited generator size so natural new has the period class surface.
// try 13: coalesced the natural allocation result onto object_info's proven first dword instead of a separate pointer local; this should restore the 0x18dc frame/home topology.
// try 14: preserve the proven object_info.obj_id null guard with typed operator-new plus placement construction; natural new optimized away that observable first-dword home.
// try 15: restore the period RGE_Object_Info_Line field/byte-pair ownership and PDB initialization order instead of a raw offset/constant scaffold.
// try 16: represent the binary-proven group/scale/short flag word as one union dword store while retaining named byte ownership.
// try 17: corrected the count owner to RGE_Land_Info::land_num at +0x141c; the oracle loads the lands parameter before the copy loop, not world->land_num.
// try 18: restored the full RGE_Land_Info record layout and canonical interior y-field cursors; the oracle's +0x0c/+0x34 loop is a typed field anchor, not an arbitrary byte buffer.
// fresh session: baseline rebuilt 658 effective bytes with no EH/new ABI; typed natural new restored the constructor relocation, EH frame, 0x1920 allocation, exact 137-instruction count, and 0x18d0/0x18dc stack sizes.
// fresh probes: full object-record ownership plus the group-flag dword union closed the initialization instruction count; correcting land_num to the second parameter at +0x141c recovered the loop owner and 18.98% exact-block coverage.
// final state: current typed source is 687 effective bytes vs 695 original, 137 instructions, 3 calls, exact frame allocation, and 589 strict differing bytes; the best emitted-code diagnostic was 584 bytes before restoring the full typed land anchors.
// BLOCKER: remaining mismatch begins in the EH handler/stack-home and saved-this/register schedule (rebuilt uses __chkstk/local EH label and spills this before callee-save pushes; oracle uses __alloca_probe/55E63E and delayed [esp+0Ch] home). No productive hypotheses remain in this bounded session; left the canonical typed reconstruction in scratch.

class RGE_Map;
class RGE_Game_World { public: char pad[0x141c]; int land_num; };
class RGE_Land_Info_Line {
public:
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    unsigned char zone;
    unsigned char pad_19[3];
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_31[3];
};
class RGE_Land_Info {
public:
    RGE_Land_Info_Line land[99];
    long land_num;
    unsigned char base_terrain;
    unsigned char pad_1421[3];
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    unsigned char wall_fade;
    unsigned char pad_end[3];
};
class RGE_RMM_Object_Generator;
class RGE_Object_Number_Per_Group {
public:
    unsigned char _0_1_;
    unsigned char _1_1_;
    unsigned char pad[2];
};
class RGE_Object_Initial_Flags {
public:
    struct Bytes {
        unsigned char group_flag;
        unsigned char scale_flag;
        unsigned short _10_2_;
    };
    union {
        Bytes bytes;
        unsigned long group_flags;
    };
};
class RGE_Object_Info_Line {
public:
    long obj_id;
    long terrain;
    RGE_Object_Initial_Flags initial_flags;
    RGE_Object_Number_Per_Group object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
    long object_exclusion_zone;
};
class RGE_Land_Point_Info_Line {
public:
    long x;
    long y;
    long id;
    long player_id;
};
class RGE_Object_Info {
public:
    RGE_Object_Info_Line objects[99];
    long object_num;
    RGE_Land_Point_Info_Line lands[99];
    long land_num;
};
class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
    void* parent;
    void* list;
    RGE_Map* map;
    char pad[0x20];
};
class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    char data[0x1920 - 0x30];
    RGE_RMM_Object_Generator(RGE_Map*, RGE_Random_Map_Module*, RGE_Game_World*, RGE_Object_Info*, unsigned char);
};
class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:
    void add_object_module(RGE_Game_World*, RGE_Land_Info*);
};

void RGE_RMM_Controller::add_object_module(RGE_Game_World* world, RGE_Land_Info* lands)
{
    RGE_Object_Info object_info;
    object_info.lands[0].x = 6;
    object_info.objects[1].object_exclusion_zone = 4;
    object_info.objects[2].object_number_varience = 6;
    object_info.objects[3].object_number_varience = 6;
    object_info.objects[3].player_id = 4;
    object_info.objects[4].object_number_varience = 6;

    object_info.objects[0].terrain = 0x6d;
    object_info.objects[0].initial_flags.group_flags = 0;
    object_info.objects[0].object_number_per_group._0_1_ = 0;
    object_info.objects[0].object_number_per_group._1_1_ = 0;
    object_info.objects[0].object_number_varience = 1;
    object_info.objects[0].number_of_groups = 0;
    object_info.objects[0].group_area = 1;
    object_info.objects[0].land_id = -1;
    object_info.objects[0].land_inner_radius = 0;
    object_info.objects[0].land_outer_radius = 0;
    object_info.objects[0].object_exclusion_zone = 0;

    object_info.objects[1].terrain = 0x53;
    object_info.objects[1].initial_flags.group_flags = 0;
    object_info.objects[1].object_number_per_group._0_1_ = 0;
    object_info.objects[1].object_number_per_group._1_1_ = 0;
    object_info.objects[1].object_number_varience = 1;
    object_info.objects[1].number_of_groups = 0;
    object_info.objects[1].group_area = 3;
    object_info.objects[1].land_id = -1;
    object_info.objects[1].land_inner_radius = 0;
    object_info.objects[1].land_outer_radius = 2;

    object_info.objects[2].terrain = 0x41;
    object_info.objects[2].initial_flags.group_flags = 0;
    object_info.objects[2].object_number_per_group._0_1_ = 1;
    object_info.objects[2].object_number_per_group._1_1_ = 1;
    object_info.objects[2].object_number_varience = 3;
    object_info.objects[2].number_of_groups = 3;
    object_info.objects[2].group_area = 10;
    object_info.objects[2].player_id = 3;
    object_info.objects[2].land_id = 0;
    object_info.objects[2].land_inner_radius = -1;
    object_info.objects[2].land_outer_radius = -1;
    object_info.objects[2].object_exclusion_zone = -1;

    object_info.objects[3].terrain = 0x66;
    object_info.objects[3].initial_flags.group_flags = 0xffffffff;
    object_info.objects[3].object_number_per_group._0_1_ = 2;
    object_info.objects[3].object_number_per_group._1_1_ = 0;
    object_info.objects[3].number_of_groups = 2;
    object_info.objects[3].group_area = 1;
    object_info.objects[3].land_id = 0;
    object_info.objects[3].land_inner_radius = 0;
    object_info.objects[3].land_outer_radius = 9;
    object_info.objects[3].object_exclusion_zone = 15;

    object_info.objects[4].terrain = 0x42;
    object_info.objects[4].initial_flags.group_flags = 0xffffffff;
    object_info.objects[4].object_number_per_group._0_1_ = 2;
    object_info.objects[4].object_number_per_group._1_1_ = 0;
    object_info.objects[4].number_of_groups = 2;
    object_info.objects[4].group_area = 1;
    object_info.objects[4].player_id = 4;
    object_info.objects[4].land_id = 0;
    object_info.objects[4].land_inner_radius = 0;
    object_info.objects[4].land_outer_radius = 9;
    object_info.objects[4].object_exclusion_zone = 15;

    object_info.objects[5].terrain = 0x3b;
    object_info.objects[5].initial_flags.group_flags = 0xffffffff;
    object_info.objects[5].object_number_per_group._0_1_ = 1;
    object_info.objects[5].object_number_per_group._1_1_ = 0;
    object_info.objects[5].object_number_varience = 5;
    object_info.objects[5].number_of_groups = 2;
    object_info.objects[5].group_area = 1;
    object_info.objects[5].player_id = 3;
    object_info.objects[5].land_id = 0;
    object_info.objects[5].land_inner_radius = 0;
    object_info.objects[5].land_outer_radius = 9;
    object_info.objects[5].object_exclusion_zone = 15;
    int count = lands->land_num;
    if (count > 0) {
        long* dst = &object_info.lands[0].y;
        long* src = &lands->land[0].y;
        int i = 0;
        do {
            ++i;
            dst[-1] = src[-1];
            dst[0] = src[0];
            dst[1] = 0;
            dst[2] = i;
            src += 13;
            dst += 4;
        } while (i < count);
    }
    object_info.objects[0].obj_id = (long)new RGE_RMM_Object_Generator(
        this->map, this, world,
        (RGE_Object_Info*)((char*)&object_info + 4), 1);
}
