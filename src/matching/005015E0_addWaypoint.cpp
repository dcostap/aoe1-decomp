struct WaypointInfo {
    unsigned char a;
    unsigned char b;
    unsigned char flag;
};

class TacticalPlayer {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void addWaypoint(int id, WaypointInfo* info, int one);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    TacticalPlayer* player;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;

    void addWaypoint(int id, unsigned char a, unsigned char b);
};

void TribeTacticalAIModule::addWaypoint(int id, unsigned char a, unsigned char b) {
    WaypointInfo info;

    info.a = a;
    info.b = b;
    info.flag = 1;
    this->md->player->addWaypoint(id, &info, 1);
}
