// aiblditm.cpp:36-39, 110 bytes
// attempt 1: 80 bytes, too small
// attempt 2: 82.7%, base call via vptr, vptr=0 not 56E734h
// attempt 3: 82.7%, EH prolog still present
// attempt 4: 72.7%, no base call, just member inits
// attempt 5: 82.7%, BaseItem() in body still triggers EH
// BEST: 72.7% (attempt 4). BLOCKER: VC5 inserts EH prolog
//   (push ecx; lea ecx,[esp+7]; call) for constructors by default.
//   Original has no EH setup. Member init order/offsets all correct.
//   Also missing: vptr store at end (mov [esi], 56E734h).
class BuildItem {
public:
    void* vptr;        // +0x00
    char gap_04[0x6C - 4];
    
    void* next;         // +0x6C (0)
    void* prev;         // +0x70 (0)
    int priorityValue;  // +0x74 (-1)
    int numberValue;    // +0x78 (0)
    int progressValue;  // +0x7C (0)
    int builtValue;     // +0x80 (0)
    int buildAttemptsValue; // +0x84 (0)
    int placeOnElevationValue; // +0x88 (0)
    int terrainSetValue; // +0x8C (-1)
    int buildCapValue;  // +0x90 (-1)
    int buildFromValue; // +0x94 (-1)
    int buildCategoryValue; // +0x98 (-1)
    int skipCyclesValue; // +0x9C (0)
    int numberBuildsValue; // +0xA0 (0)
    int numberValue2;   // +0xA4 (-1)
    int field_A8;       // +0xA8 (0)
    char permanentSkipValue; // +0xAC (0)

    BuildItem();
};

BuildItem::BuildItem() {
    vptr = 0;  // placeholder
    next = 0;
    prev = 0;
    numberValue = 0;
    priorityValue = -1;
    progressValue = 0;
    builtValue = 0;
    buildAttemptsValue = 0;
    placeOnElevationValue = 0;
    terrainSetValue = -1;
    buildCapValue = -1;
    buildFromValue = -1;
    buildCategoryValue = -1;
    skipCyclesValue = 0;
    numberBuildsValue = 0;
    numberValue2 = -1;
    permanentSkipValue = 0;
    field_A8 = 0;
}
