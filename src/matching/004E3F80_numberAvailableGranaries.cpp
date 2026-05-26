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
// v7: fixed RGE_Static_Object local layout to put field_38/field_3C at +0x38/+0x3C and kept currentZone/lookupZone as unsigned char returns; assigning to int with &0xff lets VC5 emit the original and eax,0xff / mov ebp,eax pattern. MATCH.

class RGE_Static_Object {
public:
    unsigned char currentZone();
    unsigned char lookupZone(int a, int b);
    char gap_00[0x38];
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
            int zone = obj->currentZone() & 0xff;
            int val3C = (int)filterObj->field_3C;
            int val38 = (int)filterObj->field_38;
            int lookup = obj->lookupZone(val38, val3C) & 0xff;
            if (zone != lookup) {
                return 0;
            }
        }
    }

    int strategicN = ((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0xA3);
    return (strategicN < this->closestDropsiteValue) ? 1 : 0;
}
