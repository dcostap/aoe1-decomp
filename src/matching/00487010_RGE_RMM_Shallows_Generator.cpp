class RGE_Map;
class RGE_Random_Map_Module;

class RGE_Shallows_Info_Line {
public:
    long x;
    long y;
};

class RGE_Shallows_Info {
public:
    RGE_Shallows_Info_Line shallows[99];
    long shallows_num;
};

class RGE_Random_Map_Module {
public:
    void* vtable_ptr;
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

    RGE_Random_Map_Module(RGE_Map* map, RGE_Random_Map_Module* parent, int flag);
};

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
public:
    RGE_Shallows_Info info;

    RGE_RMM_Shallows_Generator(RGE_Map* map, RGE_Random_Map_Module* parent, RGE_Shallows_Info* info);
};

RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(RGE_Map* map, RGE_Random_Map_Module* parent, RGE_Shallows_Info* info)
    : RGE_Random_Map_Module(map, parent, 1) {
    this->vtable_ptr = (void*)0x571EE4;
    this->schedule = 1.1f;
    this->info = *info;
}
