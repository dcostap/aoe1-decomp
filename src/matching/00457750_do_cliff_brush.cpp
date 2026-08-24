#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    unsigned char do_cliff_brush(int p0, int p1, int p2, int p3);
};

#endif

unsigned char RGE_Map::do_cliff_brush(int p0, int p1, int p2, int p3) { return 0; }
