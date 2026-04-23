class MasterObject {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    MasterObject* master_obj;
};

class TribeInformationAIModule {
public:
    int isTower(RGE_Static_Object* object);
};

int TribeInformationAIModule::isTower(RGE_Static_Object* object) {
    short id = object->master_obj->id;

    if ((id == 0x4F) || (id == 0xC7) || (id == 0x45) || (id == 0x17F) || (id == 0x17C)) {
        return 1;
    }
    return 0;
}
