#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    int clean_border_tile(int p0, int p1, int p2);
};

#endif

int RGE_Map::clean_border_tile(int p0, int p1, int p2) { return -1; }
