// tried a direct map-pointer member version and a free-function version for the map queries; VC5 kept pulling in an extra EDI save/load basin
// kept the null/nonnull behavior and child-info update shape; the remaining mismatch is the prolog register-save order, not the field writes
// leaving in scratch as a paused near-match

class RGE_Tile;
class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0[0x4];
    int field_8;
    int field_C;
};

extern RGE_Tile** give_up_map_offsets(RGE_Map*);
extern int get_map_width(RGE_Map*);
extern int get_map_height(RGE_Map*);

class RGE_Random_Map_Module {
public:
    char gap_00[0x0C];
    RGE_Map* map_field;
    RGE_Tile** map_row_offset;
    int map_width;
    int map_height;

    void update_child_map_info();
    void update_map_info(RGE_Map* param_1);
};

void RGE_Random_Map_Module::update_map_info(RGE_Map* param_1) {
    this->map_field = param_1;
    if (param_1 != 0) {
        this->map_row_offset = give_up_map_offsets(param_1);
        this->map_width = get_map_width(param_1);
        this->map_height = get_map_height(param_1);
    } else {
        this->map_row_offset = 0;
        this->map_width = 0;
        this->map_height = 0;
    }
    this->update_child_map_info();
}
