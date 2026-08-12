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
// 12: moved zeroing into the member initializer list; diff improved by 9 bytes.
// 13: declared TechnologyItem's destructor; restored the constructor EH state and reduced the diff to 159 bytes.
// 14: used ordinary `new TechnologyItem(...)`; compiler-owned allocation EH restored the pointer home and reduced the diff to 100 bytes.
// 15: reduced name to 0x104; recovered the original frame and reduced the diff to 93 bytes.
// 16: moved typeID increment into the for-loop increment expression; exact match.
// 17: replaced raw list links with named TechnologyItem fields; register pressure lost exactness.
// 18: restored raw links; exact output returned. The typed layout remains documented below.
// 19: removed an unused manual operator_new declaration; emitted code stayed exact.
// 20: replaced the opaque ResourceItem blob with its proven 0x70 layout; emitted code stayed exact.
// 21: donor-guided named list insertion keeps an explicit oldTail local, matching loadTechnologyTree's
//     period source shape; this replaces the prior raw-link diagnostic for one codegen check.
// 22: changed oldTail to a named reference to techHead.prev; diff improved to 322 bytes, but vptr and
//     sentinel initialization moved earlier, so the reference form was not kept as the natural source.
// Final natural candidate restores the same-TU donor's explicit oldTail form. The raw +4/+8 and +F8/+FC
// stores remain exact-only diagnostic evidence; named fields are required in the living reconstruction.
// The previous exact diagnostic source used the proven 0xF0 AIModule base, 0x54 TechnologyItem,
// 0x70 ResourceItem, 0x19C EH frame, ordinary nullable VC5 allocation path, and for-loop lifetime
// that destroys newRCost before the counter increment. Its raw link stores are not kept here.
// The final natural candidate keeps those lifetime and ABI facts but uses named list fields; VC5
// emits a 402-byte mismatch because typed links change vptr scheduling and register coloring.

extern "C" int __cdecl rge_read(int file, void* dst, int size);

class AIModule {
public:
    virtual ~AIModule();
    char gap[0xEC];
    AIModule(char* name, int line, int arg, int zero);
};

class ResourceItem {
public:
    void* vtable_ptr;             // +0x00
    ResourceItem* next;           // +0x04
    ResourceItem* prev;           // +0x08
    int valueValue[8];            // +0x0C
    int sortedValue[8];           // +0x2C
    int sortedIndexValue[8];      // +0x4C
    int numberValue;              // +0x6C
    ResourceItem(int count, int* vals);
    ResourceItem(const ResourceItem& other);
    ~ResourceItem();
};

class TechnologyItem {
public:
    void* vtable_ptr;             // +0x00
    TechnologyItem* next;         // +0x04
    TechnologyItem* prev;         // +0x08
    int idValue;                  // +0x0C
    char nameValue[0x40];         // +0x10
    ResourceItem* resourceCostValue; // +0x50
    TechnologyItem();
    TechnologyItem(int id, char* name, ResourceItem cost);
    ~TechnologyItem();
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
    : AIModule((char*)"Research AI", 0x3ee, file, 0),
      mainDecisionAI(0),
      techHead(),
      numTechs(0)
{
    ResearchAIModule* self = this;
    register TechnologyItem* head = &this->techHead;
    int i;
    int tempInt;
    int typeID;
    int rc[4];
    char name[0x104];

    head->next = head;
    head->prev = head;
    rge_read(arg2, &self->numTechs, 4);

    rge_read(arg2, &i, 4);
    rge_read(arg2, &self->techTreeNames[0], i);
    self->techTreeNames[i] = 0;

    for (typeID = 0; typeID < self->numTechs; ++typeID) {
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
            TechnologyItem* item = new TechnologyItem(tempInt, name, newRCost);

            item->next = head;
            TechnologyItem* oldTail = self->techHead.prev;
            item->prev = oldTail;
            oldTail->next = item;
            self->techHead.prev = item;

    }
}
