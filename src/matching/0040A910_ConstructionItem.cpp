// ConstructionItem::ConstructionItem (0040A910, 53 bytes, aiconitm.cpp)
// Attempt 1

class BaseItem {
public:
    BaseItem(BaseItem const* other);
};

class ConstructionItem : public BaseItem {
public:
    void* vtable;
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

    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    ConstructionItem(ConstructionItem const* other);
};

ConstructionItem::ConstructionItem(ConstructionItem const* other) : BaseItem(other) {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = other->inProgressValue;
    this->builtValue = other->builtValue;
    this->buildAttemptsValue = other->buildAttemptsValue;
    this->vtable = (void*)0x56E79C;
}
