extern "C" void __cdecl free(void* block);

class RGE_Game_World;
class RGE_Player;
class RGE_Map;

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;

    ~RGE_Visible_Map();
};

RGE_Visible_Map::~RGE_Visible_Map() {
    if (this->visible_map != 0) {
        free(this->visible_map);
        this->visible_map = 0;
    }
    if (this->map_offsets != 0) {
        free(this->map_offsets);
        this->map_offsets = 0;
    }
    this->player = 0;
    this->map = 0;
}
