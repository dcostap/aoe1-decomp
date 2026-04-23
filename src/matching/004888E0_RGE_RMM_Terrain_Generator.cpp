class RGE_Map;
class RGE_Terrain_Info {
public:
    char data[0x1298];
};
class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();

    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    void* map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    void* search_map;
    void* search_map_rows;
    void* stack_array;
    void* stack_offsets;

    RGE_Random_Map_Module(RGE_Map* map, RGE_Random_Map_Module* parent, unsigned char create_shared);
};

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    char gap_30[0x1298];
    void* map_zone;

    RGE_RMM_Terrain_Generator(RGE_Map* map, RGE_Random_Map_Module* parent, RGE_Terrain_Info* info);
};

RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(RGE_Map* map, RGE_Random_Map_Module* parent, RGE_Terrain_Info* info)
    : RGE_Random_Map_Module(map, parent, 1)
{
    *((RGE_Terrain_Info*)((char*)this + 0x30)) = *info;
    this->schedule = 2.0f;
}
