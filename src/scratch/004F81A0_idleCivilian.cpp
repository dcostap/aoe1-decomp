// VA: 004F81A0 TribeTacticalAIModule::idleCivilian
// Attempt log:
// try 1: 004DF520 query returned no normal target, so selected next eligible unclaimed normal after assigned/prior targets: 004F81A0 idleCivilian.
// try 2: started from prior 004F7E80 idleCivilian reconstruction and expanded toward 976B packet: two-pass civilian scan, reserve-list checks, object lookup, AI idle tests, and mode-sensitive fallback.
// try 3: modeled ManagedArray<int> at +0xF4 with resize-before-access pattern, world pointer at +0xF0, object-table lookup through world->md+0x3C.
// try 4: modeled first exclusion array at +0xD58/+0xD5C/+0xD64 and second at +0x104/+0x108/+0x110, matching packet scan loops.
// try 5: modeled first pass requiring object exists, unitAI exists, not gatherer, not in exclusion lists, and action/order both -1.
// try 6: modeled second pass with mode-sensitive gatherer filter and fallback result for mode 3.
// try 7: added ActionState/UnitAI currentAction/currentOrder call surface corresponding to 004C7420 -> 00413960/00413920 in packet.
// try 8: compiled with default flags: source builds, but rebuilt .text is 720B vs original 976B, too short for compare.
// try 9: probed /GX; no code/size change (still 720B), removed flag file.
// try 10: reviewed original: both passes inline every capacity check, allocation/copy/free grow block, exclusion scan, object lookup, and AI-state calls; current source factors ensure_index/contains_limited, collapsing roughly 250B and preventing full diff.
// left in scratch: broad behavior is reconstructed, but exact inlined array-grow/exclusion-scan topology is unresolved. No accepted_drift: rebuilt is size-short/no comparable localized diff.

extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

class ActionState { public: int currentAction(); int currentOrder(); };
class UnitAI { public: ActionState* state(); };
class StaticObj { public: char gap0[4]; int id; char gap8[0x38]; int type; UnitAI* unitAI(); };
class ObjTable { public: StaticObj* object(int); };
class World { public: char gap0[0xf0]; void* md; };
class IdArray { public: int* data; int count; int cap; void resize(int); };

class TribeTacticalAIModule {
public:
    char gap0[0xf0];
    World* world;           // +f0
    IdArray civilians;      // +f4
    int* avoid2; int avoid2_count; char gap10c[4]; int avoid2_cap; // +104/+108/+110
    char gap114[0xd58-0x114];
    int* avoid1; int avoid1_count; char gapd60[4]; int avoid1_cap; // +d58/+d5c/+d64

    int isGatherer(int id);
    int idleCivilian(int mode);
};

static void ensure_index(IdArray* a, int i) { if (i > a->cap - 1) a->resize(i + 1); }
static int contains_limited(int* a, int count, int cap, int value) {
    int i=0;
    if (count <= 0) return 0;
    while (i < cap) {
        if (a[i] == value) return 1;
        ++i;
        if (i >= count) break;
    }
    return 0;
}

int TribeTacticalAIModule::idleCivilian(int mode) {
    int i;
    int id;
    int result;
    StaticObj* obj;
    ActionState* st;
    IdArray* ids = &this->civilians;

    result = -1;
    i = 0;
    if (this->civilians.count > 0) {
        do {
            ensure_index(ids, i);
            id = ids->data[i];
            if (!contains_limited(this->avoid1, this->avoid1_count, this->avoid1_cap, id)) {
                obj = ((ObjTable*)*((void**)((char*)this->world->md + 0x3c)))->object(id);
                if (obj && obj->unitAI() && !this->isGatherer(id)) {
                    ensure_index(ids, i);
                    id = ids->data[i];
                    if (!contains_limited(this->avoid2, this->avoid2_count, this->avoid2_cap, id)) {
                        st = obj->unitAI()->state();
                        if (st->currentAction() == -1 && st->currentOrder() == -1) return obj->id;
                    }
                }
            }
            ++i;
        } while (i < this->civilians.count);
    }

    i = 0;
    if (this->civilians.count <= 0) return -1;
    do {
        ensure_index(ids, i);
        id = ids->data[i];
        if (!contains_limited(this->avoid1, this->avoid1_count, this->avoid1_cap, id)) {
            obj = ((ObjTable*)*((void**)((char*)this->world->md + 0x3c)))->object(id);
            if (obj && obj->unitAI()) {
                if (mode == 0 || mode == 3 || !this->isGatherer(id)) {
                    if (mode != 0 && mode != 1) ensure_index(ids, i);
                    ensure_index(ids, i);
                    id = ids->data[i];
                    if (!contains_limited(this->avoid2, this->avoid2_count, this->avoid2_cap, id)) {
                        st = obj->unitAI()->state();
                        if (st->currentAction() == -1 && st->currentOrder() == -1) return obj->id;
                        if (mode == 3 && st->currentAction() == -1) result = obj->id;
                    }
                }
            }
        }
        ++i;
    } while (i < this->civilians.count);
    return result;
}
