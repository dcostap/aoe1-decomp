class RGE_Static_Object;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int index);
};

class RGE_Player {
public:
    char gap_0[0x3C];
    RGE_Game_World* world;
};

class MainDecisionAIModule {
public:
    char gap_0[0xF0];
    RGE_Player* player;

    RGE_Static_Object* object(int param);
};

RGE_Static_Object* MainDecisionAIModule::object(int param) {
    return this->player->world->object(param);
}
