#ifndef AOE1_TAICONMD_CONTEXT_H
#define AOE1_TAICONMD_CONTEXT_H

// Canonical declarations recovered from taiconmd.cpp source order and the
// observed member offsets.  The owner bodies remain the compiler-facing source.

extern int useInfluencePlacement;

class ConstructionItem;
class BuildItem;
class RGE_Static_Object;
class TribeMainDecisionAIModule;
class TribeInformationAIModule;

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];

    int typeID();
    int uniqueID();
    void setUniqueID(int);
    void setTypeID(int);
    float x();
    float y();
    float xSize();
    float ySize();
};

class ConstructionItem : public BaseItem {
public:
    virtual ~ConstructionItem();
    ConstructionItem();
    ConstructionItem(ConstructionItem*);
    int built();
    int inProgress();
    int buildAttempts();
    void setInProgress(int);
    void incrementBuildAttempts();
    void setBuilt(int);
    ConstructionItem* next;
    ConstructionItem* prev;
    char gap_74[0x0C];
};

class BuildItem : public BaseItem {
public:
    char gap_6C[0x44];
};

struct PlacementState {
    char pad_00[4];
};

class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    ConstructionAIModule(void*, int);
    ConstructionAIModule(int, int);
    ConstructionItem* lot(float, float);

    char gap_04[0xEC];
    int field_f0;
    ConstructionItem constructionLots;
    int dock_count;
    ConstructionItem* dock_list;
    char gap_17C[0x6C];
    ConstructionItem* dock_tail;
    char gap_1EC[0x110];
    union {
        float x;
        float dock_y;
    };
    union {
        float y;
        float dock_x;
    };
    char gap_304[4];
    int max_x;
    int max_y;
    union {
        int state_310;
        int dock_state;
    };
};

class TribeInformationAIModule {
public:
    int influenceCanPlaceStructure(BuildItem*);
    ConstructionItem* influencePlaceStructure(
        BuildItem*, int, int, int, int, int, int, int, int, PlacementState&,
        unsigned long);
    ConstructionItem* placeDock(BuildItem*, float, float, int, int);
    void storeLot(int, unsigned char, unsigned char, unsigned char);
};

class MainDecisionAIModule {
public:
    char gap_000[0xCEC];
    TribeInformationAIModule informationAI;

    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int, int);
    RGE_Static_Object* object(int);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

class MasterObject {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual int canPlace(float, float, int);
    unsigned char currentZone();
    unsigned char lookupZone(int, int);

    char gap_04[4];
    MasterObject* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
};

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    union {
        MainDecisionAIModule* md;
        MainDecisionAIModule* mainAI;
        void* ai_module_ptr;
        int mainDecisionAI;
    };

    TribeConstructionAIModule(void*, int);
    TribeConstructionAIModule(int, int);
    virtual ~TribeConstructionAIModule();
    void setMainDecisionAI(TribeMainDecisionAIModule*);
    int canPlace(BuildItem*);
    ConstructionItem* placeStructure(BuildItem*, int, PlacementState&, unsigned long);
    ConstructionItem* placeDock(BuildItem*);
    void setBuilt(RGE_Static_Object*, int);

protected:
    ConstructionItem* compare(ConstructionItem*, ConstructionItem*);
};

#endif
