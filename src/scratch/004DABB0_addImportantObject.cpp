// 004DABB0 TribeInformationAIModule::addImportantObject
// taiinfmd.cpp
// Attempt log:
// try 1: broad reconstruction from packet: validation, allied recursion, add to important/object subtype lists, final notification.
// try 2: modeled object validation exactly from packet: null object, negative id, object type via obj->type+0x14, validType(type) helper.
// try 3: modeled owner/game/player chain at this+0x100, game+0xF0, player+0x3C/+0x4A/+0x40 observed in alliance recursion path.
// try 4: modeled no-recurse allied propagation path: player isAlly(vtable+0x18), player count > 3, strategy.check(0xC2)==1, loop players 1..count-1.
// try 5: modeled recursive call into other AI module at other->ai+0xCEC with recurse=1 when visibility/active checks pass.
// try 6: modeled markObject(obj) at 004DE600 and stored marked result for final notify condition.
// try 7: modeled first important-id list at +0x118/+0x11C/+0x124: duplicate scan, grow with malloc/free, append id.
// try 8: modeled classifyA/B/C dispatch helpers at 004DAFF0/004DB070/004DB0B0 and secondary lists at +0x128/+0x12C/+0x134 and +0x138/+0x13C/+0x144.
// try 9: factored duplicate list append into local helper for initial behavior; compiled but rebuilt .text only 768B vs original 962B, showing helper factoring is wrong for exactness.
// try 10: reviewed original: three append-list blocks are fully inlined, nearly duplicated, with subtly different register choices/copy loops; current helper collapses ~200B and prevents full diff.
// try 11: also current owner/player/local type surfaces are broad approximations, so even after inlining the append blocks exact register/layout is likely nontrivial.
// left in scratch: behavior is broadly reconstructed but exact inlined append-block/source topology is unresolved; rebuilt is size-short. No accepted_drift: no full-size localized diff.

extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

struct ObjType { char gap00[0x14]; short typeId; char gap16[0x34]; short playerId; };
struct RGE_Static_Object { void* vt; int id; ObjType* type; void* player; };
class RGE_Player { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual int isAlly(int); virtual int isActive(int); char gap04[0x38]; short playerId; ObjType* objects; };
class RGE_Static_Object2 { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual int isVisibleTo(int); char gap04[0x234]; void* ai; };
class AIStrategy { public: int check(int); };
class Game { public: char gap00[0xF0]; RGE_Player* player; char gapF4[0x11378]; AIStrategy strategy; };
class TribeInfoOwner { public: char gap00[0x100]; Game* game; };

class TribeInformationAIModule {
public:
    char gap000[0x100];
    TribeInfoOwner* owner;
    char gap104[0x118-0x104];
    int* listA; int countA; char gap120[4]; int capA;
    int* listB; int countB; char gap130[4]; int capB;
    int* listC; int countC; char gap140[4]; int capC;

    int addImportantObject(RGE_Static_Object* obj, int recurse);
    int classifyA(int type);
    int classifyB(int type);
    int classifyC(int type);
    int validType(int type);
    int markObject(RGE_Static_Object* obj);
    void notifyObject(RGE_Static_Object* obj);
};

static void append_unique(int value, int*& arr, int& count, int& cap) {
    int i = 0;
    if (count > 0) {
        while (i < cap) {
            if (arr[i] == value) return;
            ++i;
            if (i >= count) break;
        }
    }
    if (count > cap - 1) {
        int newcap = count + 1;
        int* n = (int*)malloc(newcap * 4);
        if (n) {
            int j = 0;
            if (cap > 0) {
                while (j < newcap && j < cap) { n[j] = arr[j]; ++j; }
            }
            free(arr);
            arr = n;
            cap = newcap;
        }
    }
    arr[count] = value;
    ++count;
}

int TribeInformationAIModule::addImportantObject(RGE_Static_Object* obj, int recurse) {
    int oType;
    int marked;
    int id;
    int player;

    if (obj == 0) return 0;
    if (obj->id < 0) return 0;
    oType = obj->type->typeId;
    if (!validType(oType)) return 0;

    player = obj->player ? ((ObjType*)obj->player)->playerId : 0;
    if (!recurse && player > 0) {
        RGE_Player* p = owner->game->player;
        if (p->isAlly(player) && p->objects->typeId > 3 && owner->game->strategy.check(0xC2) == 1) {
            for (int i = 1; i < p->objects->typeId; ++i) {
                if (i != owner->game->player->playerId) {
                    RGE_Static_Object2* other = *(RGE_Static_Object2**)((char*)p->objects + 0x40 + i * 4);
                    if (other && other->isVisibleTo(i) && owner->game->player->isActive(i) && other->isVisibleTo(owner->game->player->playerId)) {
                        ((TribeInformationAIModule*)((char*)other->ai + 0xCEC))->addImportantObject(obj, 1);
                    }
                }
            }
        }
    }

    marked = markObject(obj);
    id = obj->id;
    append_unique(id, listA, countA, capA);

    if (classifyA(oType) == 1) {
        append_unique(id, listB, countB, capB);
    } else if (classifyB(oType) == 1) {
        notifyObject(obj);
    } else if (classifyC(oType) == 1) {
        append_unique(id, listC, countC, capC);
    }

    if (classifyA(oType) == 1 || marked == 1) {
        notifyObject(obj);
    }
    return 1;
}
