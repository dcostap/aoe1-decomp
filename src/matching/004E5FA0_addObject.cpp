#ifndef AOE1_TAIMDMD_CONTEXT_H
class RGE_Static_Object;

class TribeTacticalAIModule {
public:
    char gap_00[0x100C];
    void addObject(RGE_Static_Object* object);
};

class TribeInformationAIModule {
public:
    char gap_00[0x10090];
    void addObject(RGE_Static_Object* object);
};

class MainDecisionAIModule {
public:
    char gap_00[0x104];
    int addObject(RGE_Static_Object* object);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0xCEC - 0x104];
    TribeInformationAIModule informationAI;
    char gap_D7C[0x6F0];
    TribeTacticalAIModule tacticalAI;

    int addObject(RGE_Static_Object* object);
};
#endif

int TribeMainDecisionAIModule::addObject(RGE_Static_Object* object) {
    if (object == 0) {
        return 0;
    }
    tacticalAI.addObject(object);
    informationAI.addObject(object);
    return MainDecisionAIModule::addObject(object);
}
