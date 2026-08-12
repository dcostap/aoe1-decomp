// VA: 004E4040 TribeInformationAIModule::lookAtMap
// Attempt log:
// baseline: replaced the decompiler-shaped counter-only loop with the typed
// map, tile-list, influence-map, and important-object operations shown by the
// original call sites and field accesses.
// probe 2: restored direct mapRowOffset[y][x] ownership and the 0x28-byte
// InfluenceMap surface; size reached 379 bytes and the quadrant/counter
// offsets became correct.
// probe 3: confirmed the full InfluenceMap layout; diff improved to 341
// bytes. Calls, CFG count, and all three call targets are aligned.
// probes 4, 9: volatile/address-taken map locals were codegen duplicates.
// probes 5, 8: sinking x initialization changed register ownership and was
// rolled back. Probe 6: direct owner-chain map reload reached 381 bytes and
// worsened resynchronization, so the persistent typed map local remains.
// probe 10: direct quadrantLog indexing worsened the localized block and was
// rolled back.
// probe 13: map declaration initialization was a codegen duplicate.
// probe 14: removed the redundant mapYSize local and read the owning field
// directly for the guard, quadrant divisor, and inner-loop limit; this
// restored the original frame and all bytes.
// exact: the typed map/tile-list traversal is natural source and matches the
// original 379-byte function with all three direct calls aligned.

class RGE_Static_Object;

struct RGE_Object_List_Node {
    RGE_Static_Object* object;
    RGE_Object_List_Node* next;
};

class RGE_Object_List {
public:
    void* vtable;
    RGE_Object_List_Node* list;
};

class RGE_Tile {
public:
    char gap_00[5];
    unsigned char terrainType;
    char gap_06[6];
    RGE_Object_List objects;
    char gap_14[4];
};

class RGE_Map {
public:
    char gap_00[0x8D8C];
    RGE_Tile** mapRowOffset;
};

class RGE_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class RGE_Master_Static_Object {
public:
    void* vtable;
    char gap_04[0x10];
    short objectGroup;
};

class RGE_Static_Object {
public:
    void* vtable;
    int id;
    RGE_Master_Static_Object* master_obj;
};

class InfluenceMap {
public:
    void* vtable;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    unsigned char unchangeableLimitValue;
    unsigned char gap_25[3];

    void setValue(int x, int y, int value);
};

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecisionAIModule* md;
    int mapXSizeValue;
    int mapYSizeValue;
    char gap_10C[0x4C];
    InfluenceMap pathMap;
    char gap_180[0x288];
    struct QuadrantLog {
        int numberExploredTiles;
        int numberAttacksOnUs;
        int numberAttacksByUs;
    } quadrantLog[4][4];
    char gap_4C8[0x98];
    int numberFoundForestTilesValue;

    void lookAtMap(void);
    int importantObject(int group);
    int addImportantObject(void* object, int value);
};

void TribeInformationAIModule::lookAtMap(void)
{
    RGE_Map* map = this->md->player->world->map;
    int x = 0;

    if (this->mapXSizeValue > 0) {
        do {
            int y = 0;

            if (this->mapYSizeValue > 0) {
                do {
                    int terrainType = map->mapRowOffset[y][x].terrainType & 0x1F;

                    if (this->mapXSizeValue != -1) {
                        int qx = (x * 4) / this->mapXSizeValue;
                        int qy = (y * 4) / this->mapYSizeValue;
                        this->quadrantLog[qx][qy].numberExploredTiles++;
                    }

                    this->pathMap.setValue(x, y, 0);

                    int forestTileCount = 0;
                    RGE_Object_List_Node* node =
                        map->mapRowOffset[y][x].objects.list;
                    while (node != 0) {
                        RGE_Static_Object* object = node->object;
                        int objectGroup = object->master_obj->objectGroup;

                        if (this->importantObject(objectGroup) == 1)
                            this->addImportantObject(object, 0);

                        if (objectGroup == 0x0F)
                            forestTileCount++;

                        node = node->next;
                    }

                    if (forestTileCount > 0 &&
                        (terrainType == 0x0A || terrainType == 0x13 ||
                         terrainType == 0x0D || terrainType == 0x14))
                        this->numberFoundForestTilesValue++;

                    ++y;
                } while (y < this->mapYSizeValue);
            }

            ++x;
        } while (x < this->mapXSizeValue);
    }
}
