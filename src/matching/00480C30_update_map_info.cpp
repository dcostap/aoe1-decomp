// tried the direct map-pointer member version and a free-function version for the map queries; VC5 kept pulling in an extra EDI save/load basin
// sibling ctor shows the correct basin: member-method calls on RGE_Map keep ECX live and avoid the extra push/pop path

class RGE_Tile;
class RGE_Map {
public:
    virtual ~RGE_Map();
    void* give_up_map_offsets();
    int get_map_width();
    int get_map_height();
};

class RGE_Random_Map_Module {
public:
    int vtable;         // +0x00
    void* parent;       // +0x04
    void* list;         // +0x08
    RGE_Map* map_field; // +0x0C
    void* map_row_offset; // +0x10
    int map_width;      // +0x14
    int map_height;     // +0x18

    void update_child_map_info();
    void update_map_info(RGE_Map* param_1);
};

void RGE_Random_Map_Module::update_map_info(RGE_Map* param_1) {
    this->map_field = param_1;
    if (param_1 != 0) {
        this->map_row_offset = param_1->give_up_map_offsets();
        this->map_width = this->map_field->get_map_width();
        this->map_height = this->map_field->get_map_height();
    } else {
        this->map_row_offset = 0;
        this->map_width = 0;
        this->map_height = 0;
    }
    this->update_child_map_info();
}
