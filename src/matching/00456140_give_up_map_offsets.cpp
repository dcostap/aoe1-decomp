#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0[0x8D88];
    int field_8D8C;
    int give_up_map_offsets();
};

#endif

int RGE_Map::give_up_map_offsets() { return this->field_8D8C; }
