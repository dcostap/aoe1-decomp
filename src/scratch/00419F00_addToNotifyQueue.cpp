// VA: 00419F00 addToNotifyQueue (279B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap4[0x4];
    void* field_08;
    
    void addToNotifyQueue(int a1, int a2, int a3);
};

void UnitAIModule::addToNotifyQueue(int a1, int a2, int a3) {
    int* queue = *(int**)((char*)field_08 + 0x78);
    int* head = *(int**)((char*)field_08 + 4);
    
    if (head != queue) {
        // Add to queue
        *(int*)((char*)head + 0x60) = a1;
        *(int*)((char*)head + 0x64) = a2;
        *(int*)((char*)head + 0x68) = a3;
        
        // Advance head
        *(int**)((char*)field_08 + 4) = head + 1;
    }
}
