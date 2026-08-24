void __cdecl operator_delete(void*);

#ifndef INFMAP_SHARED_CONTEXT
struct InfluenceMap {
    int vfptr;      // 0x00
    char gap_4[0x10];
    unsigned char* valueValue; // 0x14
    unsigned char** rowValue;  // 0x18
    ~InfluenceMap();
};
#endif

InfluenceMap::~InfluenceMap() {
    if (this->valueValue) {
        operator_delete((void*)this->valueValue);
    }
    if (this->rowValue) {
        operator_delete((void*)this->rowValue);
    }
}
