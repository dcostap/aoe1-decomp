// VA: 005032E0 TribeTacticalAIModule::checkTradeBoats (406 B)
// PDB source: taitacmd.cpp:13224-13258
// __thiscall, void
//
// Attempt log:
// - Baseline reconstruction: restored the typed Tribe tactical module, embedded
//   tradeBoats ManagedArray, MainDecision object lookup, resourceAI threshold
//   checks, and aiPlayer trade-attribute dispatch from the original call set.
// - Probe 2 control-flow: a do/while with an inner break emitted the opposite
//   signed backedge (js-to-exit plus jmp-to-loop) and grew to 407 bytes; rolled
//   back.
// - Probe 3 control-flow: the ordinary descending for loop plus source-local
//   found/next labels reproduced the original jns backedge, boundary, and all
//   406 bytes exactly.  The labels preserve the observed found and next-boat
//   CFG rather than compiler-steering register aliases.
// - Probe 4 control-flow: replacing the found label with break plus a
//   post-loop resource guard changed liveness/saves and broad block layout;
//   restored the exact for/label reconstruction.

void* operator new(unsigned int size);
void operator delete(void* ptr);

class RGE_Static_Object;
class TribeMainDecisionAIModule;

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_data = (T*)operator new(new_size * 4);
            if (new_data != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size;
                     i++) {
                    new_data[i] = this->value[i];
                }
                operator delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x48];
    short attribute_type_held;
};

class MainDecisionAIModule : public AIModule {
public:
    void* player;
    ManagedArray<int> objects;

    RGE_Static_Object* object(int objectID);
};

class TribeResourceAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;
    int numberResourcesValue;

    int resource(int type);
};

class TRIBE_Player {
public:
    unsigned char command_trade_attribute(int objectID, int attribute);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x10D7C - 0x104];
    TribeResourceAIModule resourceAI;
    char gap_10E74[0x1256C - 0x10E74];
    TRIBE_Player* aiPlayer;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;
    int sn[0xE2];

    void checkTradeBoats();
};

void TribeTacticalAIModule::checkTradeBoats()
{
    int i;
    i = 0;

    if (this->tradeBoats.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->md->object(this->tradeBoats[i]);
            if (object != 0) {
                short attribute = object->attribute_type_held;
                if (this->md->resourceAI.resource((int)attribute) <
                    this->sn[0xD8]) {
                    int resource = 2;
                    for (; resource >= 0; --resource) {
                        if (resource != attribute &&
                            this->md->resourceAI.resource(resource) >=
                                this->sn[0xD8]) {
                            goto trade_attribute;
                        }
                    }

                    goto next_boat;

trade_attribute:
                    this->md->aiPlayer->command_trade_attribute(
                        this->tradeBoats[i], resource);
                }
            }

next_boat:
            ++i;
        } while (i < this->tradeBoats.numberValue);
    }
}
