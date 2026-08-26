#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0[0x4];
    int field_8;
    int get_map_width();
};

#endif

long RGE_Map::get_map_width() { return this->map_width; }
