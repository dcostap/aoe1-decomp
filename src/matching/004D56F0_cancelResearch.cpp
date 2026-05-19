// 004D56F0 TribeBuildAIModule::cancelResearch(int, int, int, int)
// PDB: taibldmd.cpp lines 1462-1489 (144 B, 51 asm)
// FLAGS: default
// MATCH: 0.0000% (144/144 bytes exact)
//
// Key insights:
// logCommonHistory is a free/static function (__cdecl, takes AIModule* as first arg)
// vfn_40 is at virtual slot 16 (= vtable+0x40), requiring 16 filler virtual slots
// __declspec(novtable) on both base and derived prevents spurious vtable codegen
// uniqueID/setInProgress are direct member functions (not virtual)

class BuildItem {
public:
    int uniqueID();
    void setInProgress(int val);
};

class __declspec(novtable) AIModuleBase {
public:
    virtual ~AIModuleBase();          // slot 0
};

class __declspec(novtable) TribeBuildAIModule : public AIModuleBase {
public:
    virtual void v1();                // slot 1
    virtual void v2();                // slot 2
    virtual void v3();                // slot 3
    virtual void v4();                // slot 4
    virtual void v5();                // slot 5
    virtual void v6();                // slot 6
    virtual void v7();                // slot 7
    virtual void v8();                // slot 8
    virtual void v9();                // slot 9
    virtual void v10();               // slot 10
    virtual void v11();               // slot 11
    virtual void v12();               // slot 12
    virtual void v13();               // slot 13
    virtual void v14();               // slot 14
    virtual void v15();               // slot 15
    virtual void vfn_40();            // slot 16 = vtable+0x40

    char gap_04[0x5B8];              // +0x04
    void* field_5BC;                  // +0x5BC

    void* specificBuildListItem(int id);
    int cancelResearch(int p1, int p2, int p3, int p4);
};

void logCommonHistory(TribeBuildAIModule* module, const char* fmt, ...);

int TribeBuildAIModule::cancelResearch(int p1, int p2, int p3, int p4)
{
    int val = *(int*)(*(int*)(*(int*)((char*)this->field_5BC + 0xF0) + 0x3C) + 4);
    logCommonHistory(this, "Canceling research (WT=%ld) for item of type %d, %d", val, p2, p3);

    BuildItem* item = (BuildItem*)this->specificBuildListItem(p4);

    if (item) {
        logCommonHistory(this, "  Setting build item #%d in progress to FALSE", item->uniqueID());
        item->setInProgress(0);
    } else {
        logCommonHistory(this, "  ERROR!  Invalid build item.");
    }

    this->vfn_40();
    return 1;
}
