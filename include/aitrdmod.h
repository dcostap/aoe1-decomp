#ifndef AOE1_AITRDMOD_H
#define AOE1_AITRDMOD_H

// Module-local declarations for the original aitrdmod.cpp source module.
// AIModule comes from its canonical shared header.
#include "aimodule.h"

// setMainDecisionAI, and save.  The generated class inventory proves the
// TradeAIModule object size of 0xF4 and md at +0xF0.
class MainDecisionAIModule;

class TradeAIModule : public AIModule {
  public:
    virtual ~TradeAIModule();
    virtual int save(int outfile);

    TradeAIModule(void* pW, int playerID);
    TradeAIModule(int playerID, int infile);
    void setMainDecisionAI(MainDecisionAIModule* m);

    MainDecisionAIModule* md;
};

typedef char aitrdmod_tradeaimodule_size[(sizeof(TradeAIModule) == 0xF4) ? 1 : -1];

typedef char aitrdmod_tradeaimodule_md_offset[((char*) &((TradeAIModule*) 0)->md - (char*) 0 == 0xF0) ? 1 : -1];

#endif
