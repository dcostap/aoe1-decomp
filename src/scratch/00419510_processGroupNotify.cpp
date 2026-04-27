// VA: 00419510 processGroupNotify (209B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap4[0x4];
    void* field_08;
    
    void processGroupNotify(int a1, int a2);
};

void UnitAIModule::processGroupNotify(int a1, int a2) {
    int* data = *(int**)((char*)field_08 + 4);
    if (data) {
        int* objInfo = *(int**)((char*)field_08 + 0x0C);
        if (objInfo) {
            *(int*)((char*)data + 0x58) = a1;
        }
    }
}
