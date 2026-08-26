// compact attribute-give wrapper first
// tried a raw command-object vtable cast; mismatch was just the call surface
// current lead: direct world->commands forwarding with the player id as the first argument
// STATUS: scratch. Standalone bytes match; the canonical full tplayer wrapper does not.

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Command;
class RGE_Game_World;
class RGE_Static_Object;

class RGE_Player {
public:
    virtual void update();
    char pad_00[0x38];
    RGE_Game_World* world;
    char pad_40[0xA];
    short id;
};

class TRIBE_Player : public RGE_Player {
public:
    char pad_4C[0x1DC];
    virtual unsigned char command_give_attribute(int param_1, int param_2, float param_3, float param_4);
};

float DAT_00576828 = 0.0f;

class RGE_Command {
public:
    virtual void command_build(RGE_Static_Object**, short, short, float, float);
    virtual void command_build_wall(RGE_Static_Object**, short, short, long, long, long, long);
    virtual void command_cancel_build(RGE_Static_Object*);
    virtual void command_trade_attribute(RGE_Static_Object**, short, long);
    virtual void command_attack_ground(RGE_Static_Object**, short, float, float);
    virtual unsigned char command_give_attribute(int player_id, int param_1, int param_2, float param_3, float param_4);
};

class RGE_Game_World {
public:
    char pad_00[0x58];
    RGE_Command* commands;
};
#endif

unsigned char TRIBE_Player::command_give_attribute(int param_1, int param_2, float param_3, float param_4) {
    if (param_2 == -1 || param_3 == DAT_00576828) {
        return 0;
    }
    this->world->commands->command_give_attribute(this->id, param_1, param_2, param_3, param_4);
    return 1;
}
