// TribeBuildAIModule::removeBuiltItem — VA: 004D5270
// taibldmd.cpp:1152-1189
// Retry 2026-05-19: replaced stale fake-helper source with natural C++ member surface.
// try 1: stale fake-helper source emitted only 128B and behavior was wrong.
// try 2: natural member calls/fields reached exact 159B but broad 77.36% positional; fixed wonderBuilt offset/updateNeededResources surface.
// try 3: explicit self/register and found declaration-order variants did not move allocator out of EDI=this/EBX=zero/EAX=found basin.
// try 4: break/no-found loop moved this into EBX but lost original found-test topology and worsened control flow.
// try 5: bool found used AL and worsened; rolled back to int family.
// try 6: using found/zero as method args and wonder reset did not change register allocation.
// try 7: /Ob0 no improvement; flag removed.
// try 8: prechecking sentinel with an empty if/else-for got EBX=this and EDI=zero, improving to 71.07% positional / 52.20% edit, but push edi and branch layout still differ; kept as best.
// GIVEUP: behavior/calls/offsets now match the packet, but remaining mismatch is broad control-flow/register topology (original push edi before sentinel lea, EDI=found from entry, EBX=this; rebuilt delays push edi and carries a separate EAX found state). Not accepted drift.
// The local TU context now models the proved tactical virtual header.
// Grouped validation is MATCH at the tactical wonder-field displacement.


#ifndef TAIBLDMD_SHARED_CONTEXT
class BaseItem {
public:
    char gap_00[0x6C];
    BaseItem* next;
    int gameID();
    int typeID();
    void setGameID(int id);
};

class BuildItem : public BaseItem {
public:
    int built();
    void setInProgress(int v);
    void setBuilt(int v);
    void setBuildAttempts(int v);
};

class TribeTacticalAIModule {
public:
    void updateNeededResources();
};

class MasterData {
public:
    char gap_00[0x122B4];
    int wonderBuiltValue;
};

class TribeBuildAIModule {
public:
    char gap_000[0x0F0];
    BuildItem sentinel;
    char gap_160[0x45C];
    MasterData* md;

    int removeBuiltItem(int id);
};
#endif

int TribeBuildAIModule::removeBuiltItem(int id)
{
    BuildItem* item = *(BuildItem**)((char*)this + 0x15C);
    int found = 0;
    BuildItem* sentinel = (BuildItem*)((char*)this + 0x0F0);

    while (item != sentinel && item != 0 && found == 0) {
        if (item->gameID() == id && item->built() == 1) {
            item->setInProgress(found);
            item->setBuilt(found);
            item->setGameID(-1);
            item->setBuildAttempts(found);
            if (item->typeID() == 0x114) {
#ifdef TAIBLDMD_SHARED_CONTEXT
                this->md->tacticalAI.wonderBuiltValue = found;
#else
                this->md->wonderBuiltValue = found;
#endif
            }
            found = 1;
        } else {
            item = (BuildItem*)item->next;
        }
    }

    ((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->updateNeededResources();
    return 1;
}
