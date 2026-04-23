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
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
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

void RGE_Command::do_command_add_waypoint(RGE_Command_Add_Waypoint* param_1) {
    if (this->world->object(param_1->recipient) != 0) {
        this->world->players[param_1->player_id]->processAddWaypointCommand(param_1->recipient, param_1->waypoint, param_1->numberWaypoints);
    }
}
