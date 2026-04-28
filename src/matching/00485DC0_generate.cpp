// 00485DC0 RGE_RMM_Object_Generator::generate
// Source: rmm_obj.cpp lines 66-86. 136 bytes. __thiscall, returns uchar in AL.
//
// MATCHED. Exact 136-byte match confirmed via local check_function.py.
// Key: do-while zeroing loop forces LEA before MOV ECX/XOR EAX for rep stosd.

class RGE_Game_World {
public:
    char gap_00[0x40];
    void** players; // +0x40
};

class RGE_Map;

class RGE_Object_Info_Line {
public:
    char gap_00[0x30]; // placeholder, size 0x30
};

class RGE_RMM_Object_Generator {
public:
    char gap_00[0x0C];
    RGE_Map* map;                     // +0x0C
    char gap_10[0x04];
    long map_width;                  // +0x14 (long, but read as word via mov dx)
    long map_height;                 // +0x18 (long, but read as word via mov cx)
    char gap_1C[0x14];
    RGE_Game_World* world;            // +0x30
    RGE_Object_Info_Line info_objects[99]; // +0x34, 99*0x30 = 0x1290
    long object_num;                  // +0x12C4
    char gap_12C8[0x634];
    unsigned char terrain_table[32];  // +0x18FC
    unsigned char add_terrain;        // +0x191C

    void clear_stack();
    void generate_objects(RGE_Object_Info_Line* line);
    unsigned char generate();
};

void RGE_RMM_Object_Generator::clear_stack();
void RGE_RMM_Object_Generator::generate_objects(RGE_Object_Info_Line* line);

class RGE_Zone_Map_List {
public:
    void delete_zone_maps();
};

class RGE_Map {
public:
    char gap_00[0x8DC4];
    RGE_Zone_Map_List* zone_map_list; // +0x8DC4

    void set_terrain(void* player, RGE_Game_World* world,
        int a, int b, short w, short h,
        int c, int d, int e);
};

unsigned char RGE_RMM_Object_Generator::generate() {
    if (this->add_terrain != 0) {
        RGE_Game_World* wld = this->world;
        short w = this->map_width;
        short h = this->map_height;
        h--;
        w--;
        this->map->set_terrain(
            *wld->players,
            wld,
            0, 0,
            w, h,
            1, 0, 0
        );
    }

    this->clear_stack();

    long* zero_ptr = (long*)this->terrain_table;
    int zero_cnt = 8;
    do {
        *zero_ptr++ = 0;
        zero_cnt--;
    } while (zero_cnt != 0);

    for (int i = 0; i < this->object_num; i++) {
        this->generate_objects(&this->info_objects[i]);
    }

    this->map->zone_map_list->delete_zone_maps();

    return 1;
}
