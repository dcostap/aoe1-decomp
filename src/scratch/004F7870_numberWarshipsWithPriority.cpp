// VA: 004F7870 TribeTacticalAIModule::numberWarshipsWithPriority
// PDB source: taitacmd.cpp
// Attempt log:
// - broad reconstruction from packet: scan two warship id arrays, filter duplicates, compare unitAI priority against parameter, count and append unique matches.
// - default /O2 compiles but .text is 752 bytes vs target 1300, much too short for extraction; helper factoring/duplicate checks/array append topology are far from original.
// - tried /Od diagnostically: 1009 bytes, still too short and wrong frame family for the optimized original.
// - restored default flags. Give-up: requires faithful source-level reconstruction of two long near-duplicate scan blocks and exact ManagedArray/helper surfaces; no accepted_drift proposed.

struct Obj;
struct Arr { int* data; int count; int unk8; int cap; void resize(int); int contains(int*); };
struct World { void* vt; char gap4[0x3c-4]; void* obj_mgr; Obj* object(int); };
struct Player { char gap0[0x1256c]; struct { char gap0[0x3c]; World* world; } *game; };
struct ObjType { char gap0[0x14]; short id; };
struct UnitAI { int valid(); int priority(); };
struct Obj { void* vt; char gap4[4]; ObjType* type; UnitAI* unitAI(); };

class TribeTacticalAIModule_4F7870 {
public:
    char gap0[0xF0]; Player* player; char gapF4[0x114-0xF4]; Arr warships2; char gap124[0x144-0x124]; Arr warships1; Arr result; Arr seen; char gapD68[1];
    int numberWarshipsWithPriority(int priority, int compare);
};

static int get_pri(Obj* o) { UnitAI* ai=o->unitAI(); if (ai->valid()==-1) return -999999; return ai->priority(); }
static void append_unique(Arr* a, int v) { if (a->contains(&v) != 1) { if (a->count > a->cap-1) a->resize(a->count+1); a->data[a->count++] = v; } }

int TribeTacticalAIModule_4F7870::numberWarshipsWithPriority(int priority, int compare)
{
    int n = 0;
    result.count = 0;
    int i;
    for (i=0; i<warships1.count; i++) {
        if (i > warships1.cap-1) warships1.resize(i+1);
        int id = warships1.data[i];
        Obj* obj = player->game->world->object(id);
        if (!obj || !obj->unitAI()) continue;
        int dup = 0;
        for (int j=0; j<seen.count && j<seen.cap; j++) if (seen.data[j] == id) { dup=1; break; }
        if (dup) continue;
        int p = get_pri(obj);
        if ((compare < 0 && (p == -999999 || p < priority)) ||
            (compare > 0 && (p != -999999 && p > priority)) ||
            (compare == 0 && (p != -999999 && p == priority))) {
            append_unique(&result, id); n++;
        }
    }
    for (i=0; i<warships2.count; i++) {
        if (i > warships2.cap-1) warships2.resize(i+1);
        int id = warships2.data[i];
        Obj* obj = player->game->world->object(id);
        if (!obj || !obj->unitAI()) continue;
        if (obj->type->id != 0x12 && obj->type->id != 0x0d) continue;
        int p = get_pri(obj);
        if ((compare < 0 && (p == -999999 || p < priority)) ||
            (compare > 0 && (p != -999999 && p > priority)) ||
            (compare == 0 && (p != -999999 && p == priority))) {
            int already=0;
            for (int k=0; k<result.count && k<result.cap; k++) if (result.data[k] == id) { already=1; break; }
            if (!already) { if (result.count > result.cap-1) result.resize(result.count+1); result.data[result.count++] = id; }
            n++;
        }
    }
    return n;
}
