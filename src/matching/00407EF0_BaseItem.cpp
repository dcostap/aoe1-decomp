// VA: 00407EF0 BaseItem::BaseItem (copy constructor)
// aibitm.cpp lines 82-84

// attempt 1: natural copy constructor

#include <string.h>

class BaseItem {
public:
    int vtable;             // +0x00
    int field_04;           // +0x04
    int field_08;           // +0x08
    int field_0C;           // +0x0C
    char name[64];          // +0x10 (approximate size)
    int field_50;           // +0x50
    int field_54;           // +0x54
    int field_58;           // +0x58
    int field_5C;           // +0x5C
    int field_60;           // +0x60
    int field_64;           // +0x64
    int field_68;           // +0x68

    BaseItem(BaseItem* src);
};

BaseItem::BaseItem(BaseItem* src) {
    this->field_04 = src->field_04;
    this->field_08 = src->field_08;
    this->field_0C = src->field_0C;
    this->field_50 = src->field_50;
    this->field_54 = src->field_54;
    this->field_58 = src->field_58;
    this->field_5C = src->field_5C;
    this->field_60 = src->field_60;
    this->field_64 = src->field_64;
    this->field_68 = src->field_68;
    this->vtable = 0x56E730;
    strcpy(this->name, src->name);
}
