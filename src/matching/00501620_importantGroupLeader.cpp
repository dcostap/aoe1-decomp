class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Static_Object* master_obj;
};

class InnerInnerType {
public:
    RGE_Static_Object* object(int param);
};

class InnerType {
public:
    char gap_0[0x3C];
    InnerInnerType* inner_3C;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    InnerType* member_F0;

    RGE_Static_Object* object(int param);
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;

    int importantGroupLeader(int param);
};

int TribeTacticalAIModule::importantGroupLeader(int param) {
    RGE_Static_Object* object = this->md->object(param);
    if (object == 0) {
        return 0;
    }
    short group = object->master_obj->object_group;
    if ((group != 0x12) && (group != 0x0D)) {
        return 0;
    }
    return 1;
}
