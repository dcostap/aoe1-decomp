#ifndef TMAP_GROUP_CONTEXT
class RGE_Player_Info;
class TRIBE_Map {
public:
    virtual ~TRIBE_Map();
    void map_generate(RGE_Player_Info* p0);
};
#endif

void TRIBE_Map::map_generate(RGE_Player_Info* p0) {}
