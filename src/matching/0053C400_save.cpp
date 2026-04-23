extern float save_game_version;
extern "C" void __cdecl rge_write(int handle, void* buffer, int count);

class RGE_Game_World;
class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
};
class RGE_Map;

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;

    void save(int handle);
};

void RGE_Visible_Map::save(int handle) {
    rge_write(handle, &this->widthValue, 4);
    rge_write(handle, &this->heightValue, 4);
    if (save_game_version >= 6.7f) {
        rge_write(handle, &this->numberTilesExploredValue, 4);
    }
    rge_write(handle, &this->player->id, 2);
    if ((0 < this->widthValue) && (0 < this->heightValue)) {
        rge_write(handle, this->visible_map, this->widthValue * this->heightValue);
    }
}
