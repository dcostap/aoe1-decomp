class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
    char gap_4C[0x38];
    unsigned char* relations;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    RGE_Player* owner;
};

class UnitAIModule {
public:
    char gap_00[4];
    RGE_Static_Object* objectValue;

    int isNeutralOwner(int player_id);
};

int UnitAIModule::isNeutralOwner(int player_id) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == player_id) {
        return 0;
    }
    return owner->relations[player_id] == 1;
}
