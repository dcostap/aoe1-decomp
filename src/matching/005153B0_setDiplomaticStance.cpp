class TRIBE_Command {
public:
    void command_relation(short player_id, short target_id, short stance);
};

class RGE_World {
public:
    char gap_00[0x58];
    TRIBE_Command* commands;
};

class TRIBE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world;
    char gap_40[0x0A];
    short id;

    void setDiplomaticStance(int target_id, int stance);
};

void TRIBE_Player::setDiplomaticStance(int target_id, int stance) {
    this->world->commands->command_relation(this->id, (short)target_id, (short)stance);
}
