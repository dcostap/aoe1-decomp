// VA: 00419BC0 UnitAIModule::processRetryableOrder
// Source: aiuaimod.cpp:5694-5746
// EXACT MATCH: switch generates subtract-chain matching original

class UnitAIModule {
public:
    char gap_04[0x2C];
    int currentActionValue; // +0x30
    char gap_34[0x1C];
    int lastOrderValue; // +0x50
    char gap_54[0x8];
    int lastTargetTypeValue; // +0x5C

    virtual int vf00();
    virtual int vf01();
    virtual int vf02();
    virtual int vf03();
    virtual int vf04();
    virtual int vf05();
    virtual int vf06();
    virtual int vf07();
    virtual int vf08();
    virtual int vf09();
    virtual int call28(int value);
    virtual int vf11();
    virtual int vf12();
    virtual int vf13();
    virtual int vf14();
    virtual int vf15();
    virtual int call40(int a, int b, int c, int d, int e);
    virtual int vf17();
    virtual int vf18();
    virtual int vf19();
    virtual int vf20();
    virtual int vf21();
    virtual int vf22();
    virtual int vf23();
    virtual int vf24();
    virtual int call64(int value, int zero);
    virtual int call68(int value, int zero);

    int processRetryableOrder();
};

int UnitAIModule::processRetryableOrder() {
    int result;

    result = this->call28(this->lastOrderValue);
    if (result == 1) {
        result = this->call40(this->lastTargetTypeValue, -1, -1, -1, 0);
        if (result != -1) {
            switch (this->lastOrderValue) {
            case 0x2C5:
                result = this->call68(result, 0);
                return (result == 1) ? 8 : 7;
            case 0x2C9:
                result = this->call64(result, 0);
                return (result == 1) ? 8 : 7;
            default:
                return 7;
            }
        }
    }
    return 7;
}
