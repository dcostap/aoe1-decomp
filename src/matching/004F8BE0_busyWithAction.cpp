#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Game_World;
class UnitAIModule {
public:
    int currentAction();
};
class RGE_Static_Object {
public:
    UnitAIModule* unitAI();
};

class TribeTacAIPlayer {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};
class TribeTacticalModuleData {
public:
    char gap_00[0x1256C];
    TribeTacAIPlayer* aiPlayer;
};
class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeTacticalModuleData* md;

    int busyWithAction(int object_id, int action_id);
};
class RGE_Game_World {
public:
    RGE_Static_Object* object(int object_id);
};
#endif
int TribeTacticalAIModule::busyWithAction(int object_id, int action_id) {
    RGE_Static_Object* obj = this->md->aiPlayer->world->object(object_id);
    if (obj != 0) {
        UnitAIModule* ai = obj->unitAI();
        if (ai != 0) {
            if (obj->unitAI()->currentAction() == action_id) {
                return 1;
            }
        }
    }
    return 0;
}
