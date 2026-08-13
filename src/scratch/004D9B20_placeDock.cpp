// TribeInformationAIModule::placeDock (004D9B20)
// PDB source: taiinfmd.cpp:1678-1811
// Size: 922 bytes
//
// Attempt log:
// - Baseline reconstruction restores the typed AI/player/world/map ownership,
//   the zone-map and visible-map call surfaces, and the natural dock-placement
//   scan from the executable.  First checker result is recorded in the target
//   session history.
// - Reordered the zone-count/strategic-threshold statements, restored the
//   binary x-1/y-1 neighbor bounds, and made the zone penalty an int before
//   conversion; this aligned all 17 ordered call sites.
// - Restored the period BaseItem-derived ConstructionItem surface and the
//   same-TU InformationAIModule boundary; the emitted code was unchanged.
// - Scoped the initial md/player aliases in binary load order; this only
//   changed the early register/home basin and was not retained as a separate
//   source model.
// - Corrected RGE_Map::map_zones to its proven +0x8DC4 field after the row
//   table; the typed map ownership is retained.
// - Initialized the binary-observed best score to -1.0f.  This restored the
//   922-byte code size and substantially improved block alignment.
// - Reversed the commutative distance-square terms to recover the oracle's
//   x87 multiply order; promoting the inner y home to function scope emitted
//   the same code and was retained only as ordinary source shape.
// - Reconstructed the minimization predicate as `score < bestScore + random`
//   from the fcompp/test-ah topology; this reduced the remaining positional
//   drift to 126 bytes with exact call/relocation identity.
// - Left in scratch after the bounded pass: current size/call set/relocations
//   match, but the prologue frame/register basin and a localized stack/FPU
//   scheduling suffix remain non-exact.  Best source is natural typed C++;
//   no compiler-only padding, volatile scaffolding, or inline asm retained.
// - Added the binary-proven separate zone-map output home before zoneCounter
//   and passed it by reference; the distinct LEA homes restored the 0x134 frame
//   and reduced the positional diff from 126 to 116 bytes.
// - Declaration-time md/player aliases were a codegen duplicate.  Making map
//   and visible declaration-time locals improved the diff by one byte.
// - Declaring map before visible preserved the 0x134 frame and reduced the
//   diff to 107 bytes.  Direct zoneCounter indexing was codegen-equivalent.
// - Restoring the overlapping zoneCounter[0] output home reduced the frame to
//   0x130 and worsened the diff; the separate output home remains.
// - A dock-count value home increased the frame and broke the block shape;
//   it was rolled back.  The remaining lead is early register/liveness order.

void* operator new(unsigned int size);
extern "C" int __cdecl debug_rand(char* file, int line);
extern float DAT_00575570;

class BaseItem {
public:
    virtual ~BaseItem();
    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;

    char* name();
    int typeID() const;
    float xSize() const;
    float ySize() const;
    float zSize() const;
};

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    ConstructionItem(float, float, float, float, float, float, int,
                     const char*);
};

class BuildItem : public BaseItem {
};

class RGE_Zone_Map;
class RGE_Zone_Map_List;
class RGE_Game_World;
class RGE_Map;
class RGE_Visible_Map;
class RGE_Player;
class RGE_Master_Player;

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map(float* terrain_info, long terrain_info_num,
                               int& zone_map_index);
};

class RGE_Zone_Map {
public:
    char gap_00[0x408];
    unsigned char** zone_map_rows;

    unsigned char get_zone_info(long x, long y);
    int numberTilesInZone(unsigned char zone);
};

class RGE_Tile {
public:
    char gap_00[5];
    unsigned char terrainType;
    char gap_06[0x0C - 0x06];
    char gap_0C[0x18 - 0x0C];
};

class RGE_Map {
public:
    char gap_00[0x08];
    int map_width;
    int map_height;
    char gap_10[0x8D8C - 0x10];
    RGE_Tile** mapRowOffset;
    char gap_8D90[0x34];
    RGE_Zone_Map_List* map_zones;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x24];
    short terrain_num;
    short terrain_size;
    float** terrains;
};

class RGE_Visible_Map {
public:
    char gap_00[0x08];
    RGE_Player* player;
    char gap_0C[0x08];
    int width;
    int height;

    unsigned char get_visible(int x, int y);
};

class RGE_Master_Player {
public:
    char gap_00[0x4C];
    short terrain;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Player* master_player;
    char gap_28[0x10];
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
};

class ConstructionAIModule {
public:
    char gap_00[0x1E4];
    ConstructionItem* randomConstructionLots;

    ConstructionItem* randomLot(float x, float y);
};

class TribeTacticalAIModule {
public:
    char gap_00[0x100C];

    int strategicNumber(int number);
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
    char gap_F4[0x6C4 - 0xF4];
    ConstructionAIModule constructionAI;
    char gap_8AC[0x1146C - 0x6C4 - sizeof(ConstructionAIModule)];
    TribeTacticalAIModule tacticalAI;
    char gap_1247C[0x1256C - 0x1146C - sizeof(TribeTacticalAIModule)];
    RGE_Player* aiPlayer;
};

class InformationAIModule {
public:
    virtual ~InformationAIModule();
    char gap_04[0xEC];
};

class TribeInformationAIModule : public InformationAIModule {
public:
    char gap_F0[0x10];
    TribeMainDecisionAIModule* md;

    int hasAdjacentTileType(int x, int y, int type);
    int numberDocksInZone(int zone, RGE_Zone_Map* zone_map);
    int closestDockDistance(int x, int y);
    ConstructionItem* placeDock(BuildItem* item, float x, float y,
                                 int terrain_type, int tile_type);
};

ConstructionItem* TribeInformationAIModule::placeDock(
    BuildItem* item, float x, float targetY, int terrain_type, int tile_type)
{
    int zoneMapIndex;
    unsigned char zoneCounter[256];
    int i;
    RGE_Player* aiPlayer = this->md->aiPlayer;
    RGE_Player* player = this->md->player;
    RGE_Map* map = aiPlayer->world->map;
    RGE_Visible_Map* visible = aiPlayer->visible;
    RGE_Zone_Map* zoneMap;
    int bestX;
    int bestY;
    float bestScore;
    int randomOffset;
    int y;

    bestX = -1;
    bestY = -1;
    bestScore = -1.0f;
    randomOffset = -1;

    for (i = 0; i < 64; i++) {
        ((int*)zoneCounter)[i] = -1;
    }

    zoneMap = player->world->map->map_zones->get_zone_map(
        player->world->terrains[player->master_player->terrain],
        player->world->terrain_size, zoneMapIndex);

    randomOffset = debug_rand(
        (char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x6A9) % 0x32;

    {
        int currentZone = 1;
        if (currentZone < visible->width - 2) {
            do {
                y = 1;
                if (y < visible->height - 2) {
                    do {
                        if (visible->get_visible(currentZone, y) != 0 &&
                            currentZone - 1 >= 0 && y - 1 >= 0 &&
                            currentZone + 1 <= visible->width - 1 &&
                            y + 1 <= visible->height - 1) {
                            if (terrain_type == -1 ||
                                (map->mapRowOffset[y][currentZone].terrainType & 0x1F) == terrain_type) {
                                unsigned char zone = zoneMap->get_zone_info(
                                    currentZone, y);
                                int numberTiles =
                                    zoneMap->numberTilesInZone(zone);
                                int minimumTiles =
                                    this->md->tacticalAI.strategicNumber(0x70);
                                if (numberTiles >= minimumTiles &&
                                    this->hasAdjacentTileType(
                                        currentZone, y, tile_type)) {
                                    ConstructionItem* lot =
                                        this->md->constructionAI.randomLot(
                                            (float)currentZone - DAT_00575570,
                                            (float)y - DAT_00575570);
                                    if (lot == 0) {
                                        float distanceX = (float)currentZone - x;
                                        float distanceY = (float)y - targetY;
                                        float score = distanceX * distanceX +
                                                      distanceY * distanceY;
                                        if (zoneCounter[(unsigned char)zone + 4] == 0xFF) {
                                            zoneCounter[(unsigned char)zone + 4] = (unsigned char)
                                                this->numberDocksInZone(
                                                    (int)zone, zoneMap);
                                        }
                                        if (zoneCounter[(unsigned char)zone + 4] != 0) {
                                            int zonePenalty =
                                                (int)zoneCounter[(unsigned char)zone + 4] * 1000;
                                            score += (float)zonePenalty;
                                        }

                                        {
                                            int closest =
                                                this->closestDockDistance(
                                                    currentZone, y);
                                            if (closest != -1) {
                                                score += (float)(100000 / closest);
                                            }
                                        }

                                        if (bestX == -1 ||
                                            score < bestScore + (float)randomOffset) {
                                            bestScore = score;
                                            bestX = currentZone;
                                            bestY = y;
                                        }
                                    }
                                }
                            }
                        }

                        y++;
                    } while (y < visible->height - 2);
                }

                currentZone++;
            } while (currentZone < visible->width - 2);
        }
    }

    if (bestX != -1) {
        ConstructionItem* result =
            new ConstructionItem((float)bestX - DAT_00575570,
                                 (float)bestY - DAT_00575570,
                                 0.0f, item->xSize(), item->ySize(),
                                 item->zSize(), item->typeID(), item->name());
        return result;
    }
    return 0;
}
