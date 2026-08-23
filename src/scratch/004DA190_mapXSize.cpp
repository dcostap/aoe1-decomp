struct MapObj {
    char gap_0[0x08];
    int xSize;   // 0x08
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
    int cachedMapXSize;     // 0x104
};

int __fastcall mapXSize(TribeInformationAIModule* self, int) {
    if (self->cachedMapXSize == -1) {
        self->cachedMapXSize = self->gameInfo->world->terrain->mapObj->xSize;
    }
    return self->cachedMapXSize;
}
