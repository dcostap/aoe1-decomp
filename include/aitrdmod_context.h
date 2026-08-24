#ifndef AITRDMOD_CONTEXT_H
#define AITRDMOD_CONTEXT_H

// Authentic local declaration surface for C:\\msdev\\work\\age1_x1\\aitrdmod.cpp.
//
// The PDB order is the two TradeAIModule constructors, the virtual destructor,
// setMainDecisionAI, and save.  The generated class inventory proves an AIModule
// base at 0x00, a TradeAIModule object size of 0xF4, and md at +0xF0.
// The AIModule virtual order below follows the generated class inventory so
// that save remains the inherited slot at +0x3C.

class AIModuleMessage;
class MainDecisionAIModule;

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* filename);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* filename);
    virtual int saveState(char* filename);
    virtual int gleanState(int value);
    virtual int processMessage(AIModuleMessage* message);
    virtual int update(int value);
    virtual void setCallbackMessage(AIModuleMessage* message);
    virtual int filterOutMessage(AIModuleMessage* message);
    virtual int save(int value);

    AIModule(char* name, int id, int player, void* ptr);

    unsigned char body[0xEC];
};

typedef char aitrdmod_aimodule_size[
    (sizeof(AIModule) == 0xF0) ? 1 : -1];

typedef char aitrdmod_pointer_size[
    (sizeof(void*) == 4) ? 1 : -1];

class TradeAIModule : public AIModule {
public:
    virtual ~TradeAIModule();
    virtual int save(int value);

    TradeAIModule(void* ptr, int player);
    TradeAIModule(int player, int unused);
    void setMainDecisionAI(MainDecisionAIModule* module);

    MainDecisionAIModule* md;
};

typedef char aitrdmod_tradeaimodule_size[
    (sizeof(TradeAIModule) == 0xF4) ? 1 : -1];

typedef char aitrdmod_tradeaimodule_md_offset[
    ((char*)&((TradeAIModule*)0)->md - (char*)0 == 0xF0) ? 1 : -1];

#endif
