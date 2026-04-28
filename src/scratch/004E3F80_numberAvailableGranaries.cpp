// VA: 004E3F80 TribeInformationAIModule::numberAvailableGranaries
// taiinfmd.cpp:8134-8175
//
// Attempt log:
// v0: Direct this->closestDropsiteValue check -> 176 bytes, uses esi for this instead of ebx
// v1: self=this local, first access closestDropsiteValue -> same
// v2: int val = this->closestDropsiteValue[0] temp var -> same (VC5 optimized to direct cmp)
// v3: (int)*this->closestDropsiteValue cast -> same
// v4: self=this, int val, aimd=this->md locals -> same
// v5: swapped access order (val first, then aimd) -> same
// v6: vc5-small flag preset on variant_lab -> all 12 flag variants produce identical code
//
// Remaining gap (pure VC5 register allocation):
// Original: push ebx; mov ebx,ecx (saves this in ebx immediately), then push ebp,esi, push edi
// Mine: push ebx,ebp,esi; mov esi,ecx (saves this in esi), push edi
// Original loads [ebx+0x540] into eax before cmp -1; mine uses cmp dword [esi+0x540],-1
// All 12 vc5-small flag variants produce identical code, showing this is pure source-shape
// register allocation. Behavior, call set, stack cleanup, and memory effects all match.

class RGE_Static_Object {
public:
    unsigned char currentZone();
    unsigned char lookupZone(int a, int b);
    float field_38;
    float field_3C;
};

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int a);
    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10);
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int n);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;               // +0x100
    char gap_104[0x43C];  // 0x104..0x53F
    int closestDropsiteValue;               // +0x540
    char gap_544[0x0C];   // 0x544..0x54F
    int closestDropsiteResourceID;          // +0x550

    int numberAvailableGranaries();
};

int TribeInformationAIModule::numberAvailableGranaries() {
    int val = this->closestDropsiteValue;

    if (val == -1) {
        return 0;
    }

    RGE_Static_Object* obj = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1
    );

    if (obj != 0) {
        RGE_Static_Object* filterObj = this->md->object(
            this->closestDropsiteResourceID
        );

        if (filterObj != 0) {
            unsigned char zone = obj->currentZone();
            int val3C = (int)filterObj->field_3C;
            int val38 = (int)filterObj->field_38;
            unsigned char lookup = obj->lookupZone(val38, val3C);
            if (zone != lookup) {
                return 0;
            }
        }
    }

    int strategicN = ((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0xA3);
    return (strategicN < this->closestDropsiteValue) ? 1 : 0;
}
