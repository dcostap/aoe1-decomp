// 00540A40 RGE_Game_World::~RGE_Game_World
// Attempt log:
// 1: natural destructor implementation from packet with local class surfaces and delete/free calls: too short 560B; compiler looped first 7 object-list deletes and doubled explicit destructor+delete calls.
// 2: switch to explicit operator delete after destructor and unroll the seven object-list fields: same size 674, edit diff 59; remaining drift includes gameInfo vcall slot and first zeroing schedule.
// 3: add dummy virtual before RGE_Game_Info deleting destructor to call [vftable+4] like original: first 607 bytes exact, only fclose call staging differs near two globals.
// 4: declare fclose as void/int and globals as pointer/int: no change; remaining mismatch is only two fclose argument staging blocks.
// 5: best check: same size 674/674, first 607 bytes exact, edit diff 24 (3.56%), positional diff 56 (8.31%).
// 6: accepted_drift candidate: original pushes EAX directly for fclose(logStatusFile/DVlogf); rebuilt copies EAX to EDX/ECX then pushes that register and compensates with shifted add esp/branch distances. Memory effects and calls are equivalent.

extern "C" void __cdecl free(void*);
extern "C" void __cdecl fclose(int);
void __cdecl operator delete(void*);

#define VIS_UNIT_objectsValue (*(int*)0x0087D7FC)
#define logStatusFile (*(int*)0x00886C50)
#define DVlogf (*(int*)0x00886C58)

class RGE_Game_Info { public: virtual void v0(); virtual void dtor(int); };
class RGE_Thing { public: virtual void dtor(int); };
class RGE_Object_List { public: ~RGE_Object_List(); };
class RGE_Sprite { public: ~RGE_Sprite(); };
class RGE_Sound { public: ~RGE_Sound(); };
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char pad04[0x28-4]; RGE_Thing* p28; short cnt2c; char pad2e[2]; RGE_Sound** sounds; short spriteCount; char pad36[2]; RGE_Sprite** sprites; char pad3c[0x44-0x3c]; short playerCount; char pad46[2]; RGE_Thing** players; RGE_Thing* p4c; short ptrCount50; char pad52[2]; void** ptrs54; RGE_Game_Info* gameInfo; char pad5c[4]; short objCount60; char pad62[2]; RGE_Thing** objs64; char pad68[0x88-0x68]; void* visUnitObjects; char pad8c[8]; void* p94; char pad98[8]; RGE_Thing* pA0; char padA4[0xd8-0xa4]; RGE_Object_List* lists[7];
    void del_game_info();
};

RGE_Game_World::~RGE_Game_World()
{
    this->gameInfo = this->gameInfo;
    *(int*)this = 0x00577910;
    if (this->gameInfo) this->gameInfo->dtor(1);
    this->del_game_info();
    RGE_Object_List* l;
    l = this->lists[0]; if (l) { l->~RGE_Object_List(); operator delete(l); }
    l = this->lists[1]; if (l) { l->~RGE_Object_List(); operator delete(l); }
    l = this->lists[2]; if (l) { l->~RGE_Object_List(); operator delete(l); }
    l = this->lists[3]; if (l) { l->~RGE_Object_List(); operator delete(l); }
    l = this->lists[4]; if (l) { l->~RGE_Object_List(); operator delete(l); }
    l = this->lists[5]; if (l) { l->~RGE_Object_List(); operator delete(l); }
    l = this->lists[6]; if (l) { l->~RGE_Object_List(); operator delete(l); }
    if (this->players) {
        for (int i = 0; i < this->playerCount; ++i) {
            RGE_Thing* p = this->players[i];
            if (p) { p->dtor(1); this->players[i] = 0; }
        }
        free(this->players);
        this->players = 0;
    }
    if (this->p4c) { this->p4c->dtor(1); this->p4c = 0; }
    if (this->p28) { this->p28->dtor(1); this->p28 = 0; }
    if (this->sprites) {
        for (int i = 0; i < this->spriteCount; ++i) {
            RGE_Sprite* p = this->sprites[i];
            if (p) { p->~RGE_Sprite(); operator delete(p); }
        }
        free(this->sprites);
        this->sprites = 0;
    }
    if (this->sounds) {
        for (int i = 0; i < this->cnt2c; ++i) {
            RGE_Sound* p = this->sounds[i];
            if (p) { p->~RGE_Sound(); operator delete(p); }
        }
        free(this->sounds);
        this->sounds = 0;
    }
    if (this->ptrs54) {
        for (int i = 0; i < this->ptrCount50; ++i) {
            void* p = this->ptrs54[i];
            if (p) free(p);
        }
        free(this->ptrs54);
        this->ptrs54 = 0;
    }
    if (this->objs64) {
        for (int i = 0; i < this->objCount60; ++i) {
            RGE_Thing* p = this->objs64[i];
            if (p) p->dtor(1);
        }
        free(this->objs64);
        this->objs64 = 0;
    }
    if (this->visUnitObjects) { delete this->visUnitObjects; this->visUnitObjects = 0; VIS_UNIT_objectsValue = 0; }
    if (this->p94) { delete this->p94; this->p94 = 0; }
    if (logStatusFile) { fclose(logStatusFile); logStatusFile = 0; }
    if (this->pA0) { this->pA0->dtor(1); this->pA0 = 0; }
    if (DVlogf) { fclose(DVlogf); DVlogf = 0; }
}
