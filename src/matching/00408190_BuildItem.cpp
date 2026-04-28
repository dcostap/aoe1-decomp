// VA: 00408190 BuildItem::BuildItem
// Source: aiblditm.cpp lines 36-39
// MATCH: initializer list for bulk fields + body for last 2 -1 fields
// This forces vtable store between init-list and body code, matching original
class BaseItem {
public:
    char gap_00[0x6C - 4];
    BaseItem();
    virtual ~BaseItem();
};

class BuildItem : public BaseItem {
public:
    void* next;
    void* prev;
    int priorityValue;
    int numberValue;
    int progressValue;
    int builtValue;
    int buildAttemptsValue;
    int placeOnElevationValue;
    int terrainSetValue;
    int buildCapValue;
    int buildFromValue;
    int buildCategoryValue;
    int skipCyclesValue;
    int numberBuildsValue;
    int numberValue2;
    int field_A8;
    char permanentSkipValue;

    BuildItem();
    virtual ~BuildItem();
};

BuildItem::BuildItem()
    : next(0), prev(0), numberValue(0), progressValue(0), builtValue(0),
      buildAttemptsValue(0), placeOnElevationValue(0), skipCyclesValue(0),
      numberBuildsValue(0), field_A8(0), permanentSkipValue(0),
      priorityValue(-1), terrainSetValue(-1), buildCapValue(-1),
      numberValue2(-1)
{
    buildFromValue = -1;
    buildCategoryValue = -1;
}
