// VA: 00458820 RGE_Map::create_terrain_object
// Attempt log:
// initial rough reconstruction from packet: get terrain, delete/replace existing objects, then create terrain objects based on terrain table probabilities.
// modeled get_terrain(x,y), terrain table index formula ((terrain*16+terrain)*3)*8 and object-count gate at +0x220.
// modeled existing tile object scan through rows[x][y].objects, owner/type id checks, min/max id filters, destroy/delete vs remove calls, and replacement-terrain compatibility scan.
// modeled terrain object creation loop over per-terrain ids/chances/modes, centered vs random sub-tile placement, chance >=1000 fast path, debug_rand probability, can-place and create virtual calls.
// tried rough low-level vtable call surfaces for delete/remove/can-place/create; source compiles but surfaces are speculative.
// current source is 752 bytes vs original 794, so no positional diff; broad/short and not accepted_drift-safe.

extern "C" int __cdecl debug_rand(char*, int);
struct ObjNode { void* obj; ObjNode* next; };
struct Tile { char gap[0x10]; ObjNode* objects; };
struct ObjType { char gap[0x10]; short id; };
class RGE_Player { public: char gap[0x24]; ObjType** types; };
class RGE_Game_World {};
class RGE_Map { public:
    char gap0[8]; int width; int height; char blob[0x8d8c-0x10]; Tile** rows;
    unsigned char get_terrain(short, short);
    void create_terrain_object(RGE_Player*, RGE_Game_World*, short, short, short, int, int, int);
};

void RGE_Map::create_terrain_object(RGE_Player* player, RGE_Game_World* world, short x, short y, short newTerrain, int destroy, int minId, int maxId)
{
    float fx = 0.0f, fy = 0.0f;
    unsigned char terrain = this->get_terrain(x, y);
    int idx = terrain;
    int base = ((idx << 4) + idx) * 3;
    short count = *(short*)((char*)this + base*8 + 0x220);
    char* terrainBase = (char*)this + base*8;
    if (count <= 0) return;
    Tile* tile = &this->rows[x][y];
    ObjNode* n = tile->objects;
    while (n) {
        void* obj = n->obj;
        n = n->next;
        if (*(int*)((char*)obj+0xc) == (int)player) {
            short id = *(short*)(*(int*)(*(int*)obj+8)+0x10);
            if (id < minId || id > maxId) {
                if (newTerrain < 0) {
                    if (destroy) { if (obj) (*(void(***)(void*,int))obj)[0](obj,1); }
                    else (*(void(***)(void*))obj)[26](obj);
                } else {
                    int nbase = (((int)newTerrain << 4) + (int)newTerrain) * 3;
                    short ncnt = *(short*)((char*)this + nbase*8 + 0x220);
                    if (ncnt >= 0) {
                        int k;
                        for (k=ncnt; k>=0; --k) {
                            int off = (nbase*4 + k) * 2;
                            if (*(short*)((char*)this + off + 0x18a) == id) break;
                        }
                        if (k >= 0) {
                            if (destroy) { if (obj) (*(void(***)(void*,int))obj)[0](obj,1); }
                            else (*(void(***)(void*))obj)[26](obj);
                        }
                    }
                }
            }
        }
    }
    if (count <= 0) return;
    char* p = terrainBase + 0x1c6;
    char* q = terrainBase + 0x202;
    for (int i=0; i<count; ++i, p+=2, q+=1) {
        short objid = *(short*)(p-0x3c);
        if (objid == -1) continue;
        short chance = *(short*)p;
        ObjType* type = player->types[objid];
        unsigned char mode = *q;
        if (!type || chance <= 0) continue;
        fx = 0.0f; fy = 0.0f;
        if (mode == 1) { fx = (float)x - 0.5f; fy = (float)y - 0.5f; }
        else if (mode == 0) { fx = (float)y - (float)debug_rand((char*)0x00584B1C,0x813) * 0.0001f; fy = (float)x - (float)debug_rand((char*)0x00584B1C,0x814) * 0.0001f; }
        int ok = (chance >= 1000) ? 1 : (debug_rand((char*)0x00584B1C,0x820) % 1000 < chance);
        if (ok) {
            if (!(*(unsigned char(***)(ObjType*,RGE_Game_World*,float,float,int,int,int,int,int,int))type)[8](type, world, fx, fy,0,0,1,0,1,1)) {
                (*(void(***)(ObjType*,RGE_Game_World*,float,float,int))type)[6](type, world, fx, fy, 0);
            }
        }
        chance -= 1000;
        count -= 1000;
        if (chance > 0) { --i; p-=2; q-=1; }
    }
}
