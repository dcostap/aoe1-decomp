// 004E3500 TribeInformationAIModule::benefitToKillUnit
// BINARY NOTE: The PDB owner is TribeInformationAIModule, not a free helper.

#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Master_Static_Object {
public:
    short gap_00[8];
    short id;
};

class RGE_Player {
public:
    virtual int objectCostByType(int type);
};

class RGE_Static_Object {
public:
    char gap_00[4];
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Static_Object* object(int id);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;
    int benefitToKillUnit(int unitId);
};
#endif

int TribeInformationAIModule::benefitToKillUnit(int unitId) {
    RGE_Static_Object* object = this->md->object(unitId);
    if (object == 0)
        return -1;
    return object->owner->objectCostByType(object->master_obj->id);
}
