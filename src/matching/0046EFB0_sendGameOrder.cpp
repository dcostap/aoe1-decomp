class RGE_Static_Object;

class RGE_Command_sgo {
public:
    void command_order(RGE_Static_Object** src, int command, RGE_Static_Object* dst, float x, float y);
};

class RGE_Game_World_sgo {
public:
    char gap_00[0x58];
    RGE_Command_sgo* command;
};

class RGE_Player_sgo {
public:
    void sendGameOrder(RGE_Static_Object* src, RGE_Static_Object* dst, float x, float y);
    char gap_00[0x3C];
    RGE_Game_World_sgo* world;
};

void RGE_Player_sgo::sendGameOrder(RGE_Static_Object* src, RGE_Static_Object* dst, float x, float y) {
    RGE_Static_Object* order_src;

    order_src = src;
    this->world->command->command_order(&order_src, 1, dst, x, y);
}
