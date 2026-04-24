#pragma warning(disable:4234)
class RGE_Player {
public:
    char gap_00[0x80];
    unsigned char game_status;
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x3C];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
    char gap_7E[0x2];
};

extern char DAT_0086BCE0[];

class TRIBE_Game {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void message(int text_id, char* text, int max_len);

    char gap_04[0x3F0];
    RGE_Game_World* world;

    char* game_over_msg();
};

char* TRIBE_Game::game_over_msg() {
    RGE_Game_World* world = this->world;
    RGE_Player* player = world->players[world->curr_player];
    if (player->game_status == 1) {
        this->message(0x47E, DAT_0086BCE0, 0x100);
        return DAT_0086BCE0;
    }
    this->message(0x47F, DAT_0086BCE0, 0x100);
    return DAT_0086BCE0;
}
