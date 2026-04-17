class RGE_Static_Object;

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int object_id);
};

class TribeInformationAIModule {
public:
    int addImportantObject(int objectId);
    int addImportantObject(RGE_Static_Object* obj, int flag);
    char gap_00[0x100];
    MainDecisionAIModule* md;
};

int TribeInformationAIModule::addImportantObject(int objectId) {
    RGE_Static_Object* obj = this->md->object(objectId);
    return this->addImportantObject(obj, 0);
}
