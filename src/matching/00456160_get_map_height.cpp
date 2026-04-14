class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0[0x8];
    int field_C;
    int get_map_height();
};

int RGE_Map::get_map_height() { return this->field_C; }
