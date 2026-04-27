// VA: 00419C70 addToOrderQueue (607B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap4[0xC];
    int field_10;
    int field_14;
    int field_18;
    
    int addToOrderQueue(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
};

void* __cdecl operator_new(unsigned size);

int UnitAIModule::addToOrderQueue(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    if (field_14 == field_10) {
        // Reallocate
        void* newBuf = operator_new(0x24 * field_10 * 8);
        if (!newBuf) return 0;
        
        // Copy old data
        for (int idx = 0; idx < field_10; idx++) {
            ((int*)newBuf)[idx * 9 + 2] = ((int*)field_18)[idx * 9 + 2];
            ((int*)newBuf)[idx * 9 + 3] = ((int*)field_18)[idx * 9 + 3];
            ((int*)newBuf)[idx * 9 + 4] = ((int*)field_18)[idx * 9 + 4];
        }
    }
    
    return 1;
}
