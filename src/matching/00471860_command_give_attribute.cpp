#ifndef PLAYER_GROUPED_TU
class ICommandModule {
public:
    void give_attribute(int id, int param1, int param2, int p3);
};
class RGE_Player {
public:
    char gap_00[0x3C];
    void* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x04];
    float* attributes;
    unsigned char command_give_attribute(int, int, float);
};
#endif

unsigned char RGE_Player::command_give_attribute(int param1, int param2, float param3) {
    if (param2 == -1) return 0;
    if (param3 == *(float*)0x570EC4) return 0;
    if (param3 <= this->attributes[param2]) {
#ifdef PLAYER_GROUPED_TU
        this->world->command->command_give_attribute(this->id, param1, param2, *(int*)&param3);
#else
        ICommandModule* cmds = *(ICommandModule**)((char*)this->world + 0x58);
        cmds->give_attribute(this->id, param1, param2, *(int*)&param3);
#endif
        return 1;
    }
    return 0;
}
