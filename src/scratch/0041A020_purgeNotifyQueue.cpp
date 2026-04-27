// VA: 0041A020 purgeNotifyQueue (166B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap4[0x18];
    int field_1C;
    char gap20[0x4];
    int* field_24;
    char gap28[0x8];
    int field_30;
    
    void purgeNotifyQueue();
};

void UnitAIModule::purgeNotifyQueue() {
    for (int i = 0; i < field_1C; i++) {
        if (field_24[i * 3 + 2] == 0x1FA) {
            if (field_24[i * 3 + 3] == 0x262) {
                if (field_30 == field_24[i * 3 + 3]) {
                    // Match found, purge
                    break;
                }
            }
        }
    }
}
