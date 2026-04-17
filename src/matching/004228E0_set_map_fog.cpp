struct World {
    void set_fog(int param);
};

class RGE_Base_Game {
public:
    char gap_0[0x3F4];
    World* world; // offset 0x3F4

    void set_map_fog(int param);
};

void RGE_Base_Game::set_map_fog(int param)
{
    if (this->world)
        this->world->set_fog(param);
}
