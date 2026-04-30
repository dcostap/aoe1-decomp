// VA: 00410050 AIPlayStatus::copy (170 bytes)

struct GroupingStruct {
    int id;
    unsigned char field1;
    unsigned char field2;
    unsigned char pad[2];
};

struct PointValue {
    int xValue;
    int yValue;
    int zValue;
};

struct AIPlayStatus {
    GroupingStruct groupings[50];
    int playNumberValue;
    int targetValue;
    PointValue originalPointValue;
    int originalHitPointsValue[5];
    unsigned char currentPhaseValue;
    char pad_1B9[3];
    int savedAttackerValue;
    int lastPhaseChangeTimeValue;
    
    void copy(AIPlayStatus* other);
};

void AIPlayStatus::copy(AIPlayStatus* other) {
    this->playNumberValue = other->playNumberValue;
    this->targetValue = other->targetValue;
    int z = other->originalPointValue.zValue;
    int y = other->originalPointValue.yValue;
    int x = other->originalPointValue.xValue;
    this->originalPointValue.xValue = x;
    this->originalPointValue.yValue = y;
    this->originalPointValue.zValue = z;
    this->currentPhaseValue = other->currentPhaseValue;
    this->savedAttackerValue = other->savedAttackerValue;
    this->lastPhaseChangeTimeValue = other->lastPhaseChangeTimeValue;
    
    unsigned char* dest = (unsigned char*)this + 4;
    unsigned char* src = (unsigned char*)other;
    int diff = src - (unsigned char*)this;
    int count = 50;
    
    do {
        *(int*)(dest - 4) = *(int*)src;
        *dest = *(src + 4);
        *(dest + 1) = *(src + 5);
        dest += 8;
        src += 8;
        count--;
    } while (count != 0);
    
    int* hpDest = &this->originalHitPointsValue[0];
    int hpCount = 5;
    
    do {
        *hpDest = *(int*)((unsigned char*)hpDest + diff);
        hpDest++;
        hpCount--;
    } while (hpCount != 0);
}
