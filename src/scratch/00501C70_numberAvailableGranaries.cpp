// VA: 00501C70 numberAvailableGranaries (176B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xEC];
    int field_F0;
    
    int numberAvailableGranaries();
};

int __cdecl sub_00409D40(void* obj, int a2, int a3);

int TribeAICommand::numberAvailableGranaries() {
    int* obj = (int*)field_F0;
    if (obj) {
        sub_00409D40(obj + 0x41, 0x44, 0);
    }
    return 0;
}
