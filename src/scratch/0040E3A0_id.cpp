class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[0x40];
};

class AIModule {
public:
    char gap_00[0x08];
    int idValue_id;
    char idValue_name[0x40];

    AIModuleID id(void) const;
};

AIModuleID AIModule::id(void) const {
    AIModuleID result;

    result.id = this->idValue_id;
    for (int i = 0; i < 0x10; i++) {
        ((int*)result.name)[i] = ((const int*)this->idValue_name)[i];
    }
    return result;
}
