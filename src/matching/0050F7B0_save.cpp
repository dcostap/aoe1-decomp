class RGE_Map {
public:
    virtual void save(int p);
};

class TRIBE_Map : public RGE_Map {
public:
    virtual void save(int p);
};

void TRIBE_Map::save(int p) { RGE_Map::save(p); }
