#ifndef PLAYER_GROUPED_TU
class RGE_Command {
public:
    void command_add_waypoint(int player, int a, int b, int c);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* command;
};

class RGE_Player {
public:
    virtual void sendAddWaypointCommand(int a, void* b, int c);
    char gap_00[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};
#endif

void RGE_Player::sendAddWaypointCommand(int a, void* b, int c) {
    int pid = (int)this->id;
    this->world->command->command_add_waypoint(pid, a, (int)b, c);
}
