// VA: 00414F70 notifyCommander (198B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_20();
    char gap4[0x4];
    void* field_08;
    
    int notifyCommander(int a1, int a2, int a3);
};

int __cdecl sub_004C7760(void* obj);

int UnitAIModule::notifyCommander(int a1, int a2, int a3) {
    if (sub_004C7760(field_08) != 1) return 0;
    
    // Queue the notification
    int* queuePtr = *(int**)((char*)field_08 + 0x78);
    int* dataPtr = *(int**)((char*)field_08 + 4);
    if (dataPtr != queuePtr) {
        // Queue not full, add entry
        return 1;
    }
    
    return 0;
}
