#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0[0x8];
    int field_C;
    int get_map_height();
};

#endif

long RGE_Map::get_map_height() { return this->map_height; }
