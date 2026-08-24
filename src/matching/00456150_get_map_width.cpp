#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0[0x4];
    int field_8;
    int get_map_width();
};

#endif

int RGE_Map::get_map_width() { return this->field_8; }
