#ifndef AOE1_AIPLAYBOOK_H
#define AOE1_AIPLAYBOOK_H

class AIPlay;
class RGE_Static_Object;

class AIPlayBook {
  public:
    virtual ~AIPlayBook();
    virtual int convertTargetNameToIntType(char* t) const;
    virtual int convertTargetCharacteristicNameToIntType(char* t) const;
    virtual int convertUnitNameToIntType(char* t) const;
    virtual int convertUnitToIntType(RGE_Static_Object* obj) const;

    int numberPlaysValue; // +0x04
    char nameValue[65];   // +0x08
    AIPlay* plays;        // +0x4C

    AIPlayBook();
    int loadPlays(char* filename);
    AIPlay* play(int n);
    AIPlay* play(char* name);
    int playNumber(char* name);
};

typedef char aiplaybook_size_check[(sizeof(AIPlayBook) == 0x50) ? 1 : -1];

#endif
