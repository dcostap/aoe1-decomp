#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual unsigned char do_cliff_brush(long p0, long p1, unsigned char p2,
                                        unsigned char p3);
};

#endif

unsigned char RGE_Map::do_cliff_brush(long p0, long p1, unsigned char p2,
                                      unsigned char p3) { return 0; }
