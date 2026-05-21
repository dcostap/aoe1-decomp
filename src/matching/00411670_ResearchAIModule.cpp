// 00411670 ResearchAIModule::ResearchAIModule(void*, int)
// MATCH notes: exact match requires /GX, initializer-list zeroing for mainDecisionAI/numTechs
// around the TechnologyItem member ctor, and strcpy(dest, "") so VC5 emits the inline rep scan/copy.

extern "C" char* __cdecl strcpy(char*, const char*);

class AIModule {
public:
    virtual ~AIModule();
    char gap[0xEC];
    AIModule(char* name, int line, int arg, void* ptr);
};

class TechnologyItem {
public:
    char data[0x54];
    TechnologyItem();
};

class ResearchAIModule : public AIModule {
public:
    virtual ~ResearchAIModule();
    int mainDecisionAI;          // +0xF0
    TechnologyItem techHead;     // +0xF4
    int numTechs;                // +0x148
    char techTreeNames[0x100];   // +0x14C

    ResearchAIModule(void* ptr, int arg);
};

ResearchAIModule::ResearchAIModule(void* ptr, int arg)
    : AIModule((char*)"Research AI", 0x3ee, arg, ptr),
      mainDecisionAI(0),
      techHead(),
      numTechs(0)
{
    TechnologyItem* head = &this->techHead;
    *(int*)((char*)this + 0xF8) = (int)head;
    *(int*)((char*)this + 0xFC) = (int)head;
    strcpy(this->techTreeNames, "");
}
