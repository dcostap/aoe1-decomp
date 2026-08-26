// compact attribute-give wrapper first
// tried a raw command-object vtable cast; mismatch was just the call surface
// current lead: direct world->commands forwarding with the player id as the first argument

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Command;
class RGE_Game_World;

class RGE_Player {
public:
    char pad_00[0x3C];
    RGE_Game_World* world;
    char pad_40[0xA];
    short id;
};

class TRIBE_Player : public RGE_Player {
public:
    char pad_4C[0x1DC];
    unsigned char command_give_attribute(int param_1, int param_2, float param_3, float param_4);
};

float DAT_00576828 = 0.0f;

class RGE_Command {
public:
    void* vtable_ptr;
    RGE_Game_World* world;

    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
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
