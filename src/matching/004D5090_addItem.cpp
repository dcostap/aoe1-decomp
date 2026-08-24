// TribeBuildAIModule::addItem — VA: 004D5090
// Baseline reconstruction: mark the matching construction, then scan the
// embedded build-list sentinel for the first unbuilt item of the object's type.
// Attempt log:
// 1: replaced the stale fake-helper stub with typed member calls and the
//    binary-proven BuildAIModule/BuildItem/MD ownership; reached a one-byte
//    mismatch at the object game-id load.
// 2: corrected RGE_Static_Object field order (id +4, master_obj +8); exact.

#ifndef TAIBLDMD_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x04];
    int id;
    RGE_Master_Static_Object* master_obj;
};

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];

    int typeID();
    void setGameID(int);
};

class BuildItem : public BaseItem {
public:
    BuildItem* next;
    char gap_70[0x40];

    int built();
    void setInProgress(int);
    void setBuilt(int);
    void incrementNumberBuilds();
};

class TribeInformationAIModule {
public:
    char bytes[0x10090];
    int isBuilding(RGE_Static_Object*);
};

class TribeConstructionAIModule {
public:
    char bytes[0x318];
    void setBuilt(RGE_Static_Object*, int);
};

class TribeTacticalAIModule {
public:
    char gap_00[0xE48];
    int wonderBuiltValue;
    char gap_end[0x100C - 0xE4C];
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0x100];
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_to_construction[0x6C4 - 0x104];
    TribeConstructionAIModule constructionAI;
    char gap_to_information[0xCEC - 0x6C4 - 0x318];
    TribeInformationAIModule informationAI;
    char gap_to_tactical[0x1146C - 0xCEC - 0x10090];
    TribeTacticalAIModule tacticalAI;
};

class BuildAIModule : public AIModule {
public:
    BuildItem buildList;
    char gap_to_end[0x5BC - 0xF0 - 0xB0];
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;

    int addItem(RGE_Static_Object*, int);
};
#endif

int TribeBuildAIModule::addItem(RGE_Static_Object* object, int flag)
{
    if (this->md->informationAI.isBuilding(object)) {
        this->md->constructionAI.setBuilt(object, 1);
    }

    if (flag == 0) {
        BuildItem* item = this->buildList.next;
        BuildItem* sentinel = &this->buildList;

        if (item != sentinel) {
            while (item != sentinel) {
                if (item == 0) {
                    break;
                }

                if (item->typeID() == object->master_obj->id) {
                    if (item->built() == 0) {
                        item->setGameID(object->id);
                        item->setInProgress(0);
                        item->setBuilt(1);
                        item->incrementNumberBuilds();
                        if (item->typeID() == 0x114) {
                            this->md->tacticalAI.wonderBuiltValue = 1;
                        }
                        return 1;
                    }
                }

                item = item->next;
            }
        }
    }

    return 0;
}
