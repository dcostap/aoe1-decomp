// BaseItem::BaseItem(BaseItem* other) (00407E70, 118 bytes, aibitm.cpp lines 65-67)
// Copy constructor taking pointer (BaseItem*), distinguished from const-ref at 00407EF0
//
// Attempt 1: handwritten strcpy decl -> external call, mismatch (96 bytes, no inline string copy)
// Attempt 2: #include <string.h> for intrinsic strcpy, return this

#include <string.h>

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

    BaseItem(BaseItem* other);
};

BaseItem::BaseItem(BaseItem* other) {
    this->typeIDValue = other->typeIDValue;
    this->gameIDValue = other->gameIDValue;
    this->uniqueIDValue = other->uniqueIDValue;
    this->xValue = other->xValue;
    this->yValue = other->yValue;
    this->zValue = other->zValue;
    this->xSizeValue = other->xSizeValue;
    this->ySizeValue = other->ySizeValue;
    this->zSizeValue = other->zSizeValue;
    this->skipValue = other->skipValue;
    this->vtable_ptr = (void*)0x56E730;
    strcpy(this->nameValue, other->nameValue);
}
