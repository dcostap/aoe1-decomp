// VA: 004E4680, TribeInformationAIModule::acceptablePotentialDropsiteArea, 260 bytes
// Source: taiinfmd.cpp lines 8531-8560
// Attempt log:
// - v17: single expression for strategicNumber product
// FLAGS: /nologo /c /O2 /Oy

typedef unsigned char uchar;

struct TribeTacticalAIModule {
    char gap_0[0x194];
    int strategicNumbers[226];
    int strategicNumber(int index);
};

struct OwnerCheckObject {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual int func18(int arg);
};

struct TribeInformationAIModule {
    char gap_00[0x100];
    void* volatile md;
    char gap_104[0x0C];
    int maxImportantObjectMemory;
    void* importantObjectMemory;

    int acceptablePotentialDropsiteArea(int param1, int param2);
};

int TribeInformationAIModule::acceptablePotentialDropsiteArea(int param1, int param2)
{
    int s = ((TribeTacticalAIModule*)((char*)md + 0x1146C))->strategicNumber(0xCA)
          * ((TribeTacticalAIModule*)((char*)md + 0x1146C))->strategicNumber(0xCA);

    for (int i = 0, offset = 0; i < maxImportantObjectMemory; i++, offset += 0x24) {
        OwnerCheckObject* ownerCheck = *(OwnerCheckObject**)((char*)md + 0xF0);
        uchar owner = *(uchar*)((char*)importantObjectMemory + offset + 0x0B);
        int result = ownerCheck->func18(owner);
        if (result != 0) {
            short type = *(short*)((char*)importantObjectMemory + offset + 4);
            if (type == 0x6D || type == 0x67 || type == 0x44 ||
                type == 0x4F || type == 0xC7 || type == 0x45) {
                int x = (int)(*(uchar*)((char*)importantObjectMemory + offset + 8));
                int y = (int)(*(uchar*)((char*)importantObjectMemory + offset + 9));
                int dx = x - param1;
                int dy = y - param2;
                if (dx * dx + dy * dy <= s)
                    return 0;
            }
        }
    }
    return 1;
}
