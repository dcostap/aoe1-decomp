#ifndef COMMAND_TU_CONTEXT
class XYZBYTEPoint {
public:
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Static_Object;
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, unsigned int, unsigned int, unsigned int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int recipient, XYZBYTEPoint* waypoint, int numberWaypoints);
};

class RGE_Game_World {
public:
    char gap_0[0x40];
    RGE_Player** players;
    RGE_Static_Object* object(int id);
};

class RGE_Command_Add_Waypoint {
public:
    unsigned char command;
    unsigned char player_id;
    unsigned char _pad_0[2];
    int recipient;
    unsigned char numberWaypoints;
    XYZBYTEPoint waypoint[5];
};

class RGE_Command {
public:
    char gap_0[4];
    RGE_Game_World* world;
    void do_command_add_waypoint(RGE_Command_Add_Waypoint* param_1);
};
#endif

void RGE_Command::do_command_add_waypoint(RGE_Command_Add_Waypoint* param_1) {
    if (this->world->object(param_1->recipient) != 0) {
        this->world->players[param_1->player_id]->processAddWaypointCommand(param_1->recipient, param_1->waypoint, param_1->numberWaypoints);
    }
}
