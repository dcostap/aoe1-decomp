struct World {
    char data[4];
};

struct SomeModule {
    char gap_0[0xB0];
    World* world;
};

int __stdcall world_lookupObject(World*, int);

int __fastcall lookupObject(SomeModule* self, int, int objectId) {
    World* w = self->world;
    if (!w)
        return 0;
    return world_lookupObject(w, objectId);
}
