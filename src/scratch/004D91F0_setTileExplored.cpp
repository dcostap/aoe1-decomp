struct InfluenceMap {
    int vfptr;
    int xSizeValue;
    int ySizeValue;
    int xRefPt;
    int yRefPt;
    int valueValue;
    int** rowValue;
};

struct TribeInformationAIModule {
    char gap_0[0x158];
    InfluenceMap exploredMap;
};

void __fastcall setTileExplored(TribeInformationAIModule* self, int, int x, int y) {
    InfluenceMap* map = &self->exploredMap;
    if (x < 0 || x >= map->xSizeValue)
        return;
    if (y < 0 || y >= map->ySizeValue)
        return;
    map->rowValue[y][x] = 1;
}
