class RGE_Command_saw {
public:
    void sendAddWaypoint(int player, int a, int b, int c);
};

class RGE_Game_World_saw {
public:
    char gap_00[0x58];
    RGE_Command_saw* command;
};

class RGE_Player_saw {
public:
    void sendAddWaypointCommand(int a, int b, int c);
    char gap_00[0x3C];
    RGE_Game_World_saw* world;
    char gap_40[0x0A];
    short player_id;
};

void RGE_Player_saw::sendAddWaypointCommand(int a, int b, int c) {
    int pid = (int)this->player_id;
    this->world->command->sendAddWaypoint(pid, a, b, c);
}
