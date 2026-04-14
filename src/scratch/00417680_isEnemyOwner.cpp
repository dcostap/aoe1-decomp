struct UnitAIModule {
    char gap_0[4];
    int object;
};

int __stdcall owner_of(int objectId);
int __stdcall is_enemy(int owner1, int owner2);

int __fastcall isEnemyOwner(UnitAIModule* self, int, int objectId) {
    int otherOwner = owner_of(objectId);
    int myOwner = owner_of(self->object);
    return is_enemy(myOwner, otherOwner);
}
