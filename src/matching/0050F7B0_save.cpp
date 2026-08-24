#ifndef TMAP_GROUP_CONTEXT
class RGE_Map {
public:
    virtual void save(int p);
};

class TRIBE_Map : public RGE_Map {
public:
    virtual void save(int p);
};
#endif

void TRIBE_Map::save(int p) { RGE_Map::save(p); }
