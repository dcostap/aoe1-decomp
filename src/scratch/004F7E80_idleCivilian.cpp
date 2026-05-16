// VA: 004F7E80 TribeTacticalAIModule::idleCivilian
// Attempt log:
// initial reconstruction from packet: two-pass scan of idle civilian candidate ids, skipping reserved lists/gatherers and checking unit AI idle state.
// removed accidental operator new/delete declarations after VC5 conflict; no allocation is needed in this function.
// tried shared contains() helper for exclusion arrays; emitted too-short 608B text, expanded checks inline to better mirror original scan loops.
// tried /GX probe; no code/size change (still 688B), removed flag.
// modeled ManagedArray<int> at +0xf4 with resize-before-access pattern repeated before each id use.
// modeled world->md->world object lookup, StaticObj::unitAI, UnitAI::currentAction/currentOrder, and isGatherer checks.
// modeled two exclusion arrays at +0xd58/+0xd5c/+0xd64 and +0x104/+0x108/+0x110, but second-array offsets are speculative due local stub layout.
// current source is still 688 bytes vs original 794; no positional diff and broad logic/call-surface gaps remain, not accepted_drift-safe.

class UnitAI { public: int currentOrder(); int currentAction(); };
class StaticObj { public: char gap[4]; int id; UnitAI* unitAI(); };
class World { public: char gap[0xf0]; void* md; };
class ObjTable { public: StaticObj* object(int); };
class IdArray { public: int* data; int count; int cap; void resize(int); };
class TribeTacticalAIModule { public:
    char gap0[0xf0]; World* world; IdArray civilians; char gap114[0xd58-0x114]; int* busy1; int busy1_count; int busy1_cap;
    char gapd68[0x104-0]; int* busy2; int busy2_count; int busy2_cap;
    int isGatherer(int); int idleCivilian(int mode);
};

int TribeTacticalAIModule::idleCivilian(int mode)
{
    int i, j, id;
    IdArray* ids = &this->civilians;
    for (i=0; i<this->civilians.count; ++i) {
        if (i > ids->cap - 1) ids->resize(i+1);
        id = ids->data[i];
        for (j=0; j<this->busy1_count && j<this->busy1_cap; ++j) if (this->busy1[j] == id) goto next1;
        {
            ObjTable* table = *(ObjTable**)((char*)this->world->md + 0x3c);
            StaticObj* obj = table->object(id);
            if (!obj) goto next1;
            if (!obj->unitAI()) goto next1;
            if (this->isGatherer(id)) goto next1;
            if (i > ids->cap - 1) ids->resize(i+1);
            id = ids->data[i];
            for (j=0; j<this->busy2_count && j<this->busy2_cap; ++j) if (this->busy2[j] == id) goto next1;
            UnitAI* ai = obj->unitAI();
            if (ai->currentAction() == -1 && ai->currentOrder() == -1) return obj->id;
        }
next1: ;
    }
    for (i=0; i<this->civilians.count; ++i) {
        if (i > ids->cap - 1) ids->resize(i+1);
        id = ids->data[i];
        for (j=0; j<this->busy1_count && j<this->busy1_cap; ++j) if (this->busy1[j] == id) goto next2;
        {
            ObjTable* table = *(ObjTable**)((char*)this->world->md + 0x3c);
            StaticObj* obj = table->object(id);
            if (!obj) goto next2;
            if (!obj->unitAI()) goto next2;
            if (mode != 0 && mode != 3) {
                if (this->isGatherer(id)) goto next2;
            }
            if (mode != 0 && mode != 1) {
                if (i > ids->cap - 1) ids->resize(i+1);
            }
            if (i > ids->cap - 1) ids->resize(i+1);
            id = ids->data[i];
            for (j=0; j<this->busy2_count && j<this->busy2_cap; ++j) if (this->busy2[j] == id) goto next2;
            UnitAI* ai = obj->unitAI();
            if (ai->currentAction() == -1 && ai->currentOrder() == -1) return obj->id;
        }
next2: ;
    }
    return -1;
}
