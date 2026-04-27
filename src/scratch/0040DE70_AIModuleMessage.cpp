// VA: 0040DE70 AIModuleMessage default ctor
// aimodule.cpp lines 68-70

// attempt 1: /GX EH-framed ctor with sub-object construction
// 185 bytes

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

AIModuleMessage::AIModuleMessage() : 
    sender((char*)0x57F4B0, 0),
    recipient((char*)0x57F4A4, 0) 
{
    field_04 = 0;
    field_88 = 0;
    field_130 = 0;
    field_134 = 0;
}
