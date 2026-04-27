// VA: 004E4FA0 setLogHistory (165B)
// taimdmd.cpp

class TribeMainDecisionAIModule {
public:
    char gap4[0x100];
    void* field_104_vtbl;
    char gap108[0x5BC];
    int field_6C4;
    char gap6C8[0xA84];
    int field_1146C;
    
    void setLogHistory(int a1);
};

void __cdecl sub_0040D0A0(void* this_, int a1);

void TribeMainDecisionAIModule::setLogHistory(int a1) {
    // Call base class
    sub_0040D0A0(this, a1);
    
    // Virtual calls on the member objects
    {
        void** vtable = *(void***)((char*)this + 0x104);
        void (*func1)(void*, int) = (void (*)(void*, int))vtable[2];
        func1((char*)this + 0x104, a1);
        
        void** vtable2 = *(void***)((char*)this + 0x6C4);
        void (*func2)(void*, int) = (void (*)(void*, int))vtable2[2];
        func2((char*)this + 0x6C4, a1);
    }
}
