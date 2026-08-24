#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    void clean_borders(int p0, int p1, int p2, int p3);
};

#endif

void RGE_Map::clean_borders(int p0, int p1, int p2, int p3) {}
