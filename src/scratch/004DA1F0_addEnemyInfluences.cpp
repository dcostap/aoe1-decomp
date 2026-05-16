// VA: 004DA1F0 TribeInformationAIModule::addEnemyInfluences
// Attempt log:
// try 1: natural reconstruction with helper add_rect compiled helper/out-of-line; text too small (512 vs 547).
// try 2: inline both rectangle influence loops to match original duplicated loop bodies.
// try 3: exact-size achieved only after adding a volatile dummy local, but prologue/frame diverges immediately (sub esp 30 vs original sub esp 28).
// try 4: self local to encourage EBP=this compiled 544 bytes and did not match original prologue.
// try 5: /Oy- shrank to 512 bytes and introduced EBP frame, wrong for original.
// try 6: /GX neutral/544 and unjustified; removed.
// try 7: /O1 shrank to 463 bytes, wrong.
// try 8: direct typed ObjectMemory stride/owner/id/range fields modeled from type dump; behavior plausible.
// try 9: direct InfluenceMap calls at 0x62F348 modeled; call sequence/registers still different under rebuilt.
// try 10: duplicated LOS and range rectangle loops modeled; rebuilt loop family differs and FPU/temp scheduling differs broadly.
// left in scratch: not accepted-drift-safe; best comparable build is exact size but broad prologue/register/FPU/loop mismatch.

struct XYPoint { int x; int y; };

class RGE_Static_Object {
public:
    char gap_00[8];
    void* master;
    char gap_0C[0x38-0x0C];
    float world_x;
    float world_y;
    float world_z;
};

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    char gap_0E[2];
    int attackAttempts;
    unsigned char kills;
    char gap_15[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

class RGE_Player_Object_List { public: RGE_Static_Object* find(int id); };
class InfluenceMap { public: unsigned char getMapValue(int x, int y); void setMapValue(int x, int y, int v); };

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    RGE_Player_Object_List* objectList;
    char gap_104[0x110-0x104];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    void mapBound(XYPoint* p);
    void addEnemyInfluences(int player, int excludeId);
};

void TribeInformationAIModule::addEnemyInfluences(int player, int excludeId)
{
    int i = 0;
    int index = 0;
    volatile int dummy = 0;
    if (this->maxImportantObjectMemory <= 0) return;
    do {
        ObjectMemory* mem = (ObjectMemory*)((char*)this->importantObjectMemory + i);
        if (mem->owner == player) {
            int id = mem->id;
            if (id != excludeId) {
                RGE_Static_Object* obj = this->objectList->find(id);
                if (obj != 0) {
                    XYPoint minLOS;
                    XYPoint maxLOS;
                    XYPoint minRange;
                    XYPoint maxRange;
                    minLOS.x = (int)(obj->world_x - *(float*)((char*)obj->master + 0x28));
                    minLOS.y = (int)(obj->world_y - *(float*)((char*)obj->master + 0x28));
                    this->mapBound(&minLOS);
                    maxLOS.x = (int)(*(float*)((char*)obj->master + 0x28) + obj->world_x);
                    maxLOS.y = (int)(*(float*)((char*)obj->master + 0x28) + obj->world_y);
                    this->mapBound(&maxLOS);
                    int x = minLOS.x;
                    if (x <= maxLOS.x) {
                        do {
                            int y = minLOS.y;
                            if (y <= maxLOS.y) {
                                do {
                                    int v = (int)((InfluenceMap*)0x62F348)->getMapValue(x, y) + 10;
                                    if (v > 255) v = 255;
                                    ((InfluenceMap*)0x62F348)->setMapValue(x, y, v);
                                    y++;
                                } while (y <= maxLOS.y);
                            }
                            x++;
                        } while (x <= maxLOS.x);
                    }

                    float r = mem->range;
                    if (r >= 0.0f) {
                        minRange.x = (int)(obj->world_x - r);
                        minRange.y = (int)(obj->world_y - r);
                        this->mapBound(&minRange);
                        maxRange.x = (int)(r + obj->world_x);
                        maxRange.y = (int)(r + obj->world_y);
                        this->mapBound(&maxRange);
                        int x2 = minRange.x;
                        if (x2 <= maxRange.x) {
                            do {
                                int y2 = minRange.y;
                                if (y2 <= maxRange.y) {
                                    do {
                                        int v2 = (int)((InfluenceMap*)0x62F348)->getMapValue(x2, y2) + 10;
                                        if (v2 > 255) v2 = 255;
                                        ((InfluenceMap*)0x62F348)->setMapValue(x2, y2, v2);
                                        y2++;
                                    } while (y2 <= maxRange.y);
                                }
                                x2++;
                            } while (x2 <= maxRange.x);
                        }
                    }
                }
            }
        }
        index++;
        i += 0x24;
    } while (index < this->maxImportantObjectMemory);
}
