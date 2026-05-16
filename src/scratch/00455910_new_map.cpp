// VA: 00455910 RGE_Map::new_map
// Attempt log:
// try 1: natural reconstruction from packet: validate dimensions, free old map/row arrays/visibility managers, allocate tile rows and auxiliary rows, initialize tile flags, rebuild zone/visible/resource managers.
// FLAGS: config/flags/00455910_new_map.rsp uses /GX because original has EH registration and constructor cleanup state around manager allocations.
// try 2: modeled old player terrain-subobject destruction before freeing old map data.
// try 3: modeled free calls for tileData/aux arrays/row arrays with CRT free rather than delete.
// try 4: modeled calloc element-size forms matching original push 18/1/4 patterns.
// try 5: modeled row pointer table setup and sentinel final row entries.
// try 6: modeled nested tile flag initialization `(flags & 0x1f) | 0x20`.
// try 7: modeled set_map_bounds(0,0,w-1,h-1) after tile init.
// try 8: modeled zone map destroy/delete then new constructor.
// try 9: modeled unified visible map and visible resource manager destroy/delete/recreate sequence.
// try 10: current /GX source is exact-size 783B, but mismatch starts at EH prologue ordering and remains broad through allocation/constructor/control-flow shape.
// left in scratch: not accepted_drift-safe despite exact size; source/type/context still wrong.

extern void* __cdecl operator new(unsigned int);
extern void __cdecl operator delete(void*);
extern void* __cdecl calloc(unsigned int, unsigned int);
extern void __cdecl free(void*);

class RGE_Player_List { public: char gap[0x3c]; short count; void** players; };
class RGE_Zone_Map_List { public: RGE_Zone_Map_List(void*); void destroy(); };
class RGE_Unified_Visible_Map { public: RGE_Unified_Visible_Map(int,int); void destroy(); };
class Visible_Resource_Manager { public: Visible_Resource_Manager(void*, int, int); void destroy(); };
class TerrainSub { public: void destroy(); };

class RGE_Map {
public:
    char gap_0000[4];
    unsigned char* tileData;
    int width;
    int height;
    int worldWidth;
    int worldHeight;
    char gap_0018[0x8D74];
    void** rows;
    char gap_8D90[6];
    short tileW;
    short tileH;
    char gap_8D9A[0x16];
    unsigned char* aux1;
    unsigned char** auxRows1;
    unsigned char* aux2;
    unsigned char** auxRows2;
    char gap_8DB8[8];
    RGE_Player_List* players;
    RGE_Zone_Map_List* zoneMaps;
    RGE_Unified_Visible_Map* visibleMap;
    Visible_Resource_Manager* resManager;

    void set_map_bounds(int,int,int,int);
    void new_map(int w, int h);
};

void RGE_Map::new_map(int w, int h)
{
    if (w <= 0 || h <= 0) return;
    if (this->tileData != 0) {
        if (this->players != 0) {
            int n = this->players->count;
            for (int i = 0; i < n; i++) {
                void* p = this->players->players ? this->players->players[i] : 0;
                if (p != 0) {
                    ((TerrainSub**)((char*)p + 0x28))[0]->destroy();
                    ((TerrainSub**)((char*)p + 0x2c))[0]->destroy();
                    ((TerrainSub**)((char*)p + 0x30))[0]->destroy();
                }
            }
        }
        free(this->tileData);
    }
    if (this->aux1) free(this->aux1);
    if (this->rows) free(this->rows);
    if (this->aux2) free(this->aux2);

    this->height = h;
    this->width = w;
    this->worldWidth = (int)this->tileW * w;
    this->worldHeight = (int)this->tileH * h;
    this->tileData = (unsigned char*)calloc(w * h, 0x18);
    this->aux1 = (unsigned char*)calloc(w * h, 1);
    this->rows = (void**)calloc(h + 1, 4);
    this->aux2 = (unsigned char*)calloc(h + 1, 4);
    this->auxRows1 = (unsigned char**)calloc(h + 1, 4);
    for (int y = 0; y < h; y++) {
        this->rows[y] = this->tileData + y * w * 0x18;
        this->auxRows1[y] = this->aux1 + y * w;
    }
    this->rows[h] = this->tileData;
    this->auxRows1[h] = this->aux1;
    for (int yy = 0; yy < h; yy++) {
        for (int x = 0; x < w; x++) {
            unsigned char* t = (unsigned char*)this->rows[yy] + x * 0x18;
            t[5] = (t[5] & 0x1f) | 0x20;
        }
    }
    this->set_map_bounds(0,0,w-1,h-1);

    if (this->zoneMaps) { this->zoneMaps->destroy(); operator delete(this->zoneMaps); }
    this->zoneMaps = new RGE_Zone_Map_List(this);
    if (this->visibleMap) { this->visibleMap->destroy(); operator delete(this->visibleMap); }
    this->visibleMap = new RGE_Unified_Visible_Map(w,h);
    if (this->resManager) { this->resManager->destroy(); operator delete(this->resManager); }
    this->resManager = new Visible_Resource_Manager(this, this->players ? this->players->count : 0, 0x40);
}
