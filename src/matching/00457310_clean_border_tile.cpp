class RGE_Map {
public:
    virtual ~RGE_Map();
    int clean_border_tile(int p0, int p1, int p2);
};

int RGE_Map::clean_border_tile(int p0, int p1, int p2) { return -1; }
