// attempt 1-4: tried various class layouts, 8 params (80 bytes), 10 params (83 bytes but wrong)
// need 8 params with ret 20h, explicit vftable store, and -1,-1 pushes

class BaseItem {
public:
    void* vtable_ptr;
    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;

    BaseItem() {}
    BaseItem(int, int, int, const char*, float, float, float, float, float, float);
};

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    ConstructionItem(float, float, float, float, float, float, int, const char*);
};

ConstructionItem::ConstructionItem(float p1, float p2, float p3, float p4, float p5, float p6, int p7, const char* p8) {
    this->BaseItem::BaseItem(p7, -1, -1, p8, p1, p2, p3, p4, p5, p6);
    vtable_ptr = (void*)0x56E79C;
    next = 0;
    prev = 0;
    inProgressValue = 0;
    builtValue = 0;
    buildAttemptsValue = 0;
}
