struct TacticalAIGroup {
    char gap_0[0x2CC];
    int numberObjectsToDestroy;
    int objectsToDestroy[20];
};

int __fastcall addObjectToDestroy(TacticalAIGroup* self, int, int objectId) {
    if (self->numberObjectsToDestroy >= 20)
        return 0;
    self->objectsToDestroy[self->numberObjectsToDestroy] = objectId;
    self->numberObjectsToDestroy++;
    return 1;
}
