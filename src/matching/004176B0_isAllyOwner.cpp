// compact ally-owner check first
// expected basin: resolve the unit owner, compare ids, then test the symmetric relation bytes

class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;

class UnitAIModule {
public:
    void* vtable_ptr;
    RGE_Static_Object* objectValue;

    int isAllyOwner(int player_id);
};

class RGE_Player {
public:
    char pad_00[0x3C];
    RGE_Game_World* world;
    char pad_40[0xA];
    short id;
    short attribute_num;
    char pad_4E[0x36];
    unsigned char* relations;
};

class RGE_Game_World {
public:
    char pad_00[0x40];
    RGE_Player** players;
};

class RGE_Static_Object {
public:
    char pad_00[0xC];
    RGE_Player* owner;
};

int UnitAIModule::isAllyOwner(int player_id) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == player_id) {
        return 1;
    }
    if (owner->relations[player_id] == 0 && owner->world->players[player_id]->relations[owner->id] == 0) {
        return 1;
    }
    return 0;
}
