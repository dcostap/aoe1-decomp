// UnitAIModule::isEnemyOwner
// Gets self->object->player, checks player->id == param, if so return 0
// Then checks player->diplomacy[param] == 3 (enemy), returns result
// ret 4 = 1 param

struct RGE_Player {
    char gap_0[0x4A];
    short id;
    char gap_4C[0x38];
    unsigned char* diplomacy;
};

struct RGE_Static_Object {
    char gap_0[0x0C];
    RGE_Player* player;
};

struct UnitAIModule {
    int vtable;
    RGE_Static_Object* object;
};

int __fastcall isEnemyOwner(UnitAIModule* self, int, int owner) {
    RGE_Player* player = self->object->player;
    if (player->id == owner)
        return 0;
    unsigned char bl = player->diplomacy[owner];
    return bl == 3;
}
