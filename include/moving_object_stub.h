// VA: 0045C450 RGE_Moving_Object ctor (333B)
// move_obj.cpp lines 96-112

class RGE_Animated_Object {
public:
    virtual ~RGE_Animated_Object();
    char gap0[0x10];
    void* gameObj;      // +0x10
    char gap14[0x24];
    float x;            // +0x38
    float y;            // +0x3C
    char gap40[0x5C];
    float rotOffset;    // +0x9C
    char gapA0[4];
    // Path at +0xA4 (0x34 bytes)
    // Path at +0xD8 (0x34 bytes)
    char gapA4[0x68];   // 0xA4 to 0x10C = 0x68
    int field_10C;      // +0x10C
    int field_110;      // +0x110
    int field_114;      // +0x114
    char gap118[0x14];  // to 0x12C
    int field_12C;      // +0x12C
    char gap130[0x18];  // to 0x148
    int moveMode;       // +0x148
    int field_14C;      // +0x14C
    int field_150;      // +0x150
    char byte_154;      // +0x154
    char byte_155;      // +0x155
    char byte_156;      // +0x156
    char gap157[0x11];  // to 0x168
    char* waypoints;    // +0x168
    int wpCount;        // +0x16C
    int wpCapacity;     // +0x170
    char wpByte;        // +0x174
    char gap175[0x7];   // to 0x17C
    char byte_17C;      // +0x17C
    char byte_17D;      // +0x17D
};
