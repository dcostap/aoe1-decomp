struct ObjectManager {
    int lookup(int id);
};

struct World {
    char gap_0[0x3C];
    ObjectManager* objectManager;  // 0x3C
};

struct ObjectRef {
    char gap_0[0x0C];
    World* world;         // 0x0C
};

struct UnitAIModule {
    char gap_0[0x04];
    ObjectRef* objectRef; // 0x04
};

int __fastcall lookupObject(UnitAIModule* self, int, int objectId) {
    if (self->objectRef && self->objectRef->world && self->objectRef->world->objectManager) {
        return self->objectRef->world->objectManager->lookup(objectId);
    }
    return 0;
}
