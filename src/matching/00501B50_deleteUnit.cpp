#ifndef TAITACMD_SHARED_CONTEXT
#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Static_Object;
class TRIBE_Player;

class MainDecisionAIModule {
public:
    char gap_000[0xF0];
    RGE_Static_Object* object(int param_1);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_000[0x1256C - 0xF0];
    TRIBE_Player* aiPlayer;
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;

    int deleteUnit(int param_1);
};

class TRIBE_Player {
public:
    unsigned char command_delete_object(RGE_Static_Object* object);
};

#endif
int TribeTacticalAIModule::deleteUnit(int param_1) {
    RGE_Static_Object* object;

    object = this->md->object(param_1);
    if (object != 0) {
        if (this->md->aiPlayer->command_delete_object(object) == 1) {
            return 1;
        }
    }

    return 0;
}
#else
int TribeTacticalAIModule::deleteUnit(int) { return 0; }
#endif
