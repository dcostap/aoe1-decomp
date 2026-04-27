// VA: 0040DF50 AIModuleMessage(int, int, int) — parameterized ctor
// aimodule.cpp lines 85-87

// attempt 1: /GX EH-framed ctor with args
// 213 bytes

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

AIModuleMessage::AIModuleMessage(int a, int b, int c) : 
    sender((char*)b, a),
    recipient((char*)0x592A40, 0) 
{
    field_04 = a;
    field_88 = c;
    field_130 = 0;
    field_134 = 0;
}
