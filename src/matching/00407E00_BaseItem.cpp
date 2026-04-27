// BaseItem::BaseItem (00407E00, 104 bytes, aibitm.cpp)
// Attempt 1

char* strncpy(char* dest, const char* src, unsigned int count);

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

    BaseItem(int typeID, int gameID, int uniqueID, const char* name,
             float x, float y, float z, float xSize, float ySize, float zSize);
};

BaseItem::BaseItem(int typeID, int gameID, int uniqueID, const char* name,
                   float x, float y, float z, float xSize, float ySize, float zSize) {
    this->typeIDValue = typeID;
    this->gameIDValue = gameID;
    this->uniqueIDValue = uniqueID;
    this->xValue = x;
    this->yValue = y;
    this->zValue = z;
    this->xSizeValue = xSize;
    this->ySizeValue = ySize;
    this->zSizeValue = zSize;
    this->skipValue = 0;
    this->vtable_ptr = (void*)0x56E730;
    strncpy(this->nameValue, name, 0x3F);
}
