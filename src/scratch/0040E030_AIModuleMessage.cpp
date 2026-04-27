// VA: 0040E030 AIModuleMessage copy ctor
// aimodule.cpp lines 103-105

// attempt 1: /GX EH-framed copy ctor
// 233 bytes

class AIModuleID {
public:
    AIModuleID(char* str, int param);
    char gap_00[0x48];
};

class AIModuleMessage {
public:
    char vtable[4];
    int field_04;
    char gap_08[0x80];
    int field_88;
    AIModuleID sender;       // +0x8C
    AIModuleID recipient;    // +0xD4
    int field_130;           // +0x11C
    int field_134;           // +0x120
    int field_138;           // +0x124
    int field_13C;           // +0x128

    AIModuleMessage();
    AIModuleMessage(int a, int b, int c);
    AIModuleMessage(AIModuleMessage* other);
};

AIModuleMessage::AIModuleMessage(AIModuleMessage* other) : 
    sender((char*)0x592A40, 0),
    recipient((char*)0x592A40, 0) 
{
    field_04 = other->field_04;
    field_88 = other->field_88;
    field_130 = other->field_130;
    field_134 = other->field_134;
    field_138 = other->field_138;
    field_13C = other->field_13C;
}
