// Compiler-facing declarations for the original taipbook.cpp module.
#ifndef AOE1_TAIPBOOK_H
#define AOE1_TAIPBOOK_H

#include <string.h>
#include "stat_obj.h"

class AIPlay;

class AIPlayBook {
public:
    virtual ~AIPlayBook();
    virtual int convertTargetNameToIntType(char* name) const;
    virtual int convertTargetCharacteristicNameToIntType(char* name) const;
    virtual int convertUnitNameToIntType(char* name) const;
    virtual int convertUnitToIntType(RGE_Static_Object* object) const;

    AIPlayBook();
    int loadPlays(char* filename);
    AIPlay* play(int index);
    AIPlay* play(char* name);
    int playNumber(char* name);

    int numberPlaysValue;              // +0x04
    char nameValue[65];                // +0x08
    unsigned char pad_49[3];           // +0x49
    AIPlay* plays;                     // +0x4c
};

typedef char taipbook_aiplaybook_size[(sizeof(AIPlayBook) == 0x50) ? 1 : -1];

class TribeAIPlayBook : public AIPlayBook {
public:
    virtual ~TribeAIPlayBook();
    virtual int convertTargetNameToIntType(char* name) const;
    virtual int convertTargetCharacteristicNameToIntType(char* name) const;
    virtual int convertUnitNameToIntType(char* name) const;
    virtual int convertUnitToIntType(RGE_Static_Object* object) const;

    TribeAIPlayBook();
};

typedef char taipbook_tribe_size[(sizeof(TribeAIPlayBook) == 0x50) ? 1 : -1];

#endif
