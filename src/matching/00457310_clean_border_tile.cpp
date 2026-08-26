#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    long clean_border_tile(long p0, long p1, long (* const p2)[32]);
};

#endif

long RGE_Map::clean_border_tile(long p0, long p1, long (* const p2)[32]) { return -1; }
