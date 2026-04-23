class RGE_Static_Object {
public:
    unsigned char currentZone();
};

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int);
};

class TribeInformationAIModule {
public:
    char gap_0000[0x100];
    MainDecisionAIModule* md;
    char gap_0104[0x308 - 0x104];
    unsigned char fullyExploredZoneValue[255];

    void setFullyExploredZone(int param_1, int param_2);
};

void TribeInformationAIModule::setFullyExploredZone(int param_1, int param_2) {
    RGE_Static_Object* object = md->object(param_1);
    if (object != 0) {
        unsigned char zone = object->currentZone();
        fullyExploredZoneValue[zone] = (unsigned char)param_2;
    }
}
