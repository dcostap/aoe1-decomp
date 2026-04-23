class RGE_Master_Object {
public:
    char gap_00[0x10];
    short unitType;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Object* master_obj;
};

class MainDecisionAIModule {
public:
    char gap_000[0xF0];
    class CostOwner* costTableOwner;

    RGE_Static_Object* object(int);
};

class CostOwner {
public:
    virtual void v0();
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual int costToLoseUnit(int);
};

class TribeInformationAIModule {
public:
    char gap_0000[0x100];
    MainDecisionAIModule* md;

    int costToLoseUnit(int param_1);
};

int TribeInformationAIModule::costToLoseUnit(int param_1) {
    RGE_Static_Object* object = md->object(param_1);
    if (object == 0) {
        return -1;
    }
    CostOwner* owner = md->costTableOwner;
    return owner->costToLoseUnit(object->master_obj->unitType);
}
