// VA: 00411740 ResearchAIModule::ResearchAIModule
// Source: airchmod.cpp lines 38-75
// Attempt log:
// 1: initial natural reconstruction; needed /GX hypothesis but storage/placement-new suppressed EH and was too small.
// 2: rewrote loop with automatic ResourceItem newRCost(4, rc) and by-value TechnologyItem ctor to encourage original EH states and copy construction.
// 3: increased stack name buffer to 0x100; frame became 0x190, close to original 0x19C.
// 4: increased name buffer to 0x10C to match original 0x19C local allocation.
// 5: corrected AIModule ctor parameter order to match original push order (name,line,arg2,0).
// 6: added virtual surfaces so compiler emits ResearchAIModule vptr store; improved diff but frame +4 and this in edi.
// 7: reduced name buffer by 4 to recover original 0x19C frame after vptr surface.
// 8: introduced register self local and used it for member accesses; no codegen change.
// 9: corrected constructor parameter roles: first arg goes to AIModule base, second arg is rge_read file handle.
// 10: added explicit head local and used it for list links; no codegen change.
// 11: removed register hint from self; no codegen change.
// left in scratch: with /GX and virtual surfaces, EH prologue/frame and many operations are close, but register allocation remains wrong (rebuilt keeps this in edi and head in esi; original uses esi=this and edi=head), leading to broad drift. Also rebuilt body is 496 bytes vs original 512, so not accepted_drift-safe.

typedef unsigned int uint;
extern "C" int __cdecl rge_read(int file, void* dst, int size);
extern "C" void* __cdecl operator_new(uint size);
inline void* operator new(uint, void* p) { return p; }

class AIModule {
public:
    virtual ~AIModule();
    char gap[0xEC];
    AIModule(char* name, int line, int arg, int zero);
};

class ResourceItem {
public:
    char data[0x70];
    ResourceItem(int count, int* vals);
    ResourceItem(const ResourceItem& other);
    ResourceItem(ResourceItem* other);
    ~ResourceItem();
};

class TechnologyItem {
public:
    char data[0x54];
    TechnologyItem();
    TechnologyItem(int id, char* name, ResourceItem cost);
};

class ResearchAIModule : public AIModule {
public:
    virtual ~ResearchAIModule();
    int mainDecisionAI;          // +0xF0
    TechnologyItem techHead;     // +0xF4
    int numTechs;                // +0x148
    char techTreeNames[0x100];   // +0x14C

    ResearchAIModule(int file, int arg2);
};

ResearchAIModule::ResearchAIModule(int file, int arg2)
    : AIModule((char*)"Research AI", 0x3ee, file, 0), techHead()
{
    ResearchAIModule* self = this;
    register TechnologyItem* head = &this->techHead;
    int i;
    int tempInt;
    int typeID;
    int rc[4];
    char name[0x108];

    self->mainDecisionAI = 0;
    self->numTechs = 0;
    *(int*)((char*)self + 0xF8) = (int)head;
    *(int*)((char*)self + 0xFC) = (int)head;
    rge_read(arg2, &self->numTechs, 4);

    rge_read(arg2, &i, 4);
    rge_read(arg2, &self->techTreeNames[0], i);
    self->techTreeNames[i] = 0;

    typeID = 0;
    if (self->numTechs > 0) {
        do {
            rge_read(arg2, &i, 4);
            rge_read(arg2, name, i);
            name[i] = 0;
            rge_read(arg2, &tempInt, 4);

            int j;
            int* p = rc;
            for (j = 4; j != 0; --j) {
                rge_read(arg2, &i, 4);
                *p++ = i;
            }

            ResourceItem newRCost(4, rc);
            TechnologyItem* item = (TechnologyItem*)operator_new(0x54);
            if (item != 0) {
                item = new (item) TechnologyItem(tempInt, name, newRCost);
            } else {
                item = 0;
            }

            *(int*)((char*)item + 4) = (int)head;
            *(int*)((char*)item + 8) = *(int*)((char*)self + 0xFC);
            *(int*)(*(int*)((char*)item + 8) + 4) = (int)item;
            *(int*)((char*)self + 0xFC) = (int)item;

            ++typeID;
        } while (typeID < self->numTechs);
    }
}
