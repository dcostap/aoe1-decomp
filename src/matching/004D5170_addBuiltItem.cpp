// TribeBuildAIModule::addBuiltItem — VA: 004D5170
// Baseline reconstruction: complete the matching build-list item, copy its
// display name/ID, and refresh tactical resource requirements.
// Attempt log:
// 1: replaced the stale helper/offset scaffold with the natural BuildItem
//    member surface and the sentinel-list form used by exact taibldmd.cpp
//    siblings; baseline check follows.
// 2: placed the remembered built-item ID at its binary-proven +0x5A8 field,
//    before md at +0x5BC; the natural source then differs only in that field
//    layout from the baseline.
// Main-agent audit restored canonical polymorphic object/item/AI ownership;
// emitted code remains exact.
// The local TU context now models the proved tactical virtual header.
// Grouped validation is MATCH at the tactical wonder-field displacement.

#ifndef TAIBLDMD_SHARED_CONTEXT
extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int count);

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
};

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];
    BaseItem* next;

    int typeID();
    int uniqueID();
    void setGameID(int id);
    char* name();
};

class BuildItem : public BaseItem {
public:
    int built();
    void setInProgress(int value);
    void setBuilt(int value);
    void incrementNumberBuilds();
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xE44];
    int wonderBuiltValue;
    char gap_end[0x100C - 0xE4C];

    void updateNeededResources();
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char gap_to_tactical[0x11468];
    TribeTacticalAIModule tacticalAI;
};

class TribeBuildAIModule {
public:
    virtual ~TribeBuildAIModule();
    char gap_04[0xEC];
    BuildItem buildList;
    char gap_to_name[0x145];
    char builtName[0x3F];
    char gap_to_builtID[0x5A8 - 0x2E4];
    int builtID;
    char gap_to_md[0x5BC - 0x5AC];
    TribeMainDecisionAIModule* md;

    int addBuiltItem(RGE_Static_Object* object, int id);
};
#endif

int TribeBuildAIModule::addBuiltItem(RGE_Static_Object* object, int id)
{
    int found = 0;
    BuildItem* item = (BuildItem*)this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0 && found == 0) {
        if (item->typeID() == object->master_obj->id &&
            item->built() == 0 &&
            id != -1 &&
            item->uniqueID() == id) {
            item->setInProgress(found);
            found = 1;
            item->setBuilt(found);
            item->setGameID(object->id);
            item->incrementNumberBuilds();
            if (item->typeID() == 0x114) {
                this->md->tacticalAI.wonderBuiltValue = found;
            }
            strncpy(this->builtName, item->name(), 0x3F);
            this->builtID = item->uniqueID();
        } else {
            item = (BuildItem*)item->next;
        }
    }

    this->md->tacticalAI.updateNeededResources();
    return 1;
}
