#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void map_generate(RGE_Player* p0, RGE_Game_World* p1,
                              RGE_Player_Info* p2, unsigned char* p3);
};

#endif

void RGE_Map::map_generate(RGE_Player* p0, RGE_Game_World* p1,
                           RGE_Player_Info* p2, unsigned char* p3) {}
