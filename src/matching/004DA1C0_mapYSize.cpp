struct MapObj {
    char gap_0[0x0C];
    int ySize;   // 0x0C
};

struct TerrainObj {
    char gap_0[0x28];
    MapObj* mapObj;  // 0x28
};

struct WorldObj {
    char gap_0[0x3C];
    TerrainObj* terrain;  // 0x3C
};

struct GameInfo {
    char gap_0[0x1256C];
    WorldObj* world;  // 0x1256C
};

struct TribeInformationAIModule {
    char gap_0[0x100];
    GameInfo* gameInfo;     // 0x100
    char gap_104[0x04];
    int cachedMapYSize;     // 0x108
};

int __fastcall mapYSize(TribeInformationAIModule* self, int) {
    if (self->cachedMapYSize == -1) {
        self->cachedMapYSize = self->gameInfo->world->terrain->mapObj->ySize;
    }
    return self->cachedMapYSize;
}
