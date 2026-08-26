#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    void clean_borders(long p0, long p1, long p2, long p3);
};

#endif

void RGE_Map::clean_borders(long p0, long p1, long p2, long p3) {}
