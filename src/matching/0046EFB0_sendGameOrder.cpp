#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object;

class RGE_Command {
public:
    void command_order(RGE_Static_Object** src, int command, RGE_Static_Object* dst, float x, float y);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* command;
};

class RGE_Player {
public:
    virtual void sendGameOrder(RGE_Static_Object* src, RGE_Static_Object* dst, float x, float y);
    char gap_00[0x38];
    RGE_Game_World* world;
};
#endif

void RGE_Player::sendGameOrder(RGE_Static_Object* src, RGE_Static_Object* dst, float x, float y) {
    RGE_Static_Object* order_src;

    order_src = src;
    this->world->command->command_order(&order_src, 1, dst, x, y);
}
