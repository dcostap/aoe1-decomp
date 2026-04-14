// STATUS: scratch
// FLAGS: config\flags\004228C0_set_map_visible.rsp

struct World {
    void set_visible(int param);
};

class RGE_Base_Game {
public:
    char gap_0[0x3F4];
    World* world; // offset 0x3F4

    void set_map_visible(int param);
};

void RGE_Base_Game::set_map_visible(int param)
{
    if (this->world)
        this->world->set_visible(param);
}
