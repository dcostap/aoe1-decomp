#include <string.h>

extern const char default_item_name[];

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

    BaseItem();
};

BaseItem::BaseItem() {
    typeIDValue = -1;
    gameIDValue = -1;
    uniqueIDValue = -1;
    xValue = 0;
    yValue = 0;
    zValue = 0;
    xSizeValue = 0;
    ySizeValue = 0;
    zSizeValue = 0;
    skipValue = 0;
    vtable_ptr = (void*)0x56E730;
    strcpy(nameValue, default_item_name);
}
