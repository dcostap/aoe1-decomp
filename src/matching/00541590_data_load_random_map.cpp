class RGE_Map {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void data_load_random_map(char* a, char* b, char* c, char* d);
};

class RGE_Game_World {
public:
    char gap_00[0x24];
    RGE_Map* map;

    virtual void data_load_random_map(char* a, char* b, char* c, char* d);
};

void RGE_Game_World::data_load_random_map(char* a, char* b, char* c, char* d) {
    this->map->data_load_random_map(a, b, c, d);
}
