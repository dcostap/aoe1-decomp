// 004092F0 BuildAIModule::displayBuildList (aibldmod.cpp:288-308, 318B)
// Logs the build list items via logCommonHistory. Walks linked list from
// this->buildList.next (+0x15C) until sentinel at &this->buildList (+0xF0).
// For each item: if built()==1 uses "BLT..." format, else "    Type..." format.
// Both branches push identical getter results, differing only in format string.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void __cdecl logCommonHistory(void* this_ptr, const char* fmt, ...);

struct BaseItem2 {
    char _pad_04[0x6C - 4];       // +0x04 to +0x6B (vtable ptr at +0x00 from virtual dtor)
    int typeID();
    int gameID();
    int uniqueID();
    int skip();
    char* name();
    virtual ~BaseItem2() {}
};

struct BuildItem2 : BaseItem2 {
    void* next;               // +0x6C
    void* prev;               // +0x70
    int priorityValue;        // +0x74
    int numberValue;          // +0x78
    int progressValue;        // +0x7C
    int builtValue;           // +0x80
    int buildAttemptsValue;   // +0x84
    int placeOnElevation;     // +0x88
    int terrainSet;           // +0x8C
    int buildCapValue;        // +0x90
    int buildFromValue;       // +0x94
    int buildCategoryValue;   // +0x98
    int skipCyclesValue;      // +0x9C
    int numberBuildsValue;    // +0xA0
    int numberValue2;         // +0xA4
    int field_A8;             // +0xA8
    char permanentSkipValue;  // +0xAC

    int built();
    int skipCycles();
    unsigned char permanentSkip();
    int buildFrom();
    int buildCap();
    int numberBuilds();
    int buildAttempts();
    int inProgress();
    int buildCategory();
    virtual ~BuildItem2() {}
};

struct AIModule2 {
    char _pad_00[0xF0];
    BuildItem2 buildList;          // +0xF0 (sizeof 0xB0: 0x6C + next+fields = 0x6C+0x40+1+3pad = 0xB0)
    int buildListLength;           // +0x1A0
    char buildListName[0x101];     // +0x1A4
};

struct BuildAIModule2 : AIModule2 {
    void displayBuildList();
};

void BuildAIModule2::displayBuildList()
{
    logCommonHistory(this, "Build list '%s':", &buildListName);

    BuildItem2* item = (BuildItem2*)((BuildItem2*)&buildList)->next;
    BuildItem2* sentinel = (BuildItem2*)&buildList;

    while (item != sentinel && item != 0) {
        if (item->built() == 1) {
            logCommonHistory(this,
                "BLT Type=%-4d %-20s gID=%-4d Cat=%d uID=%d InPrg=%d BlATmpt=%d Skip=%d NumBld=%d BldCap=%d From=%d PrSkp=%d SkpCyc=%d",
                item->typeID(), item->name(), item->gameID(),
                item->buildCategory(), item->uniqueID(), item->inProgress(),
                item->buildAttempts(), item->skip(), item->numberBuilds(),
                item->buildCap(), item->buildFrom(),
                (unsigned int)item->permanentSkip(), item->skipCycles());
        } else {
            logCommonHistory(this,
                "    Type=%-4d %-20s gID=%-4d Cat=%d uID=%d InPrg=%d BlATmpt=%d Skip=%d NumBld=%d BldCap=%d From=%d PrSkp=%d SkpCyc=%d",
                item->typeID(), item->name(), item->gameID(),
                item->buildCategory(), item->uniqueID(), item->inProgress(),
                item->buildAttempts(), item->skip(), item->numberBuilds(),
                item->buildCap(), item->buildFrom(),
                (unsigned int)item->permanentSkip(), item->skipCycles());
        }

        item = (BuildItem2*)item->next;
    }
}
