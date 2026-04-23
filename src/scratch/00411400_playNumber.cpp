// quick probe: decompiler-shaped play-name scan over the play list
// if this misses, the remaining gap is likely the exact compare/branch basin, not the overall loop structure
class AIPlay {
public:
    char nameValue[65];
    char pad_41[0x608 - 65];
};

class AIPlayBook {
public:
    void* vtable_ptr;
    int numberPlaysValue;
    char nameValue[65];
    char pad_49[3];
    AIPlay* plays;

    int playNumber(char* name) const;
};

int AIPlayBook::playNumber(char* name) const {
    AIPlay* pAVar2 = this->plays;
    AIPlay* pAVar6 = pAVar2;
    int iVar4 = 0;
    unsigned char* pbVar6 = (unsigned char*)name;
    int iVar3;
    bool bVar7;

    if (pAVar2 == 0 || this->numberPlaysValue <= 0) {
        return -1;
    }

    do {
        unsigned char bVar1 = (unsigned char)pAVar2->nameValue[0];
        bVar7 = bVar1 < *pbVar6;
        if (bVar1 == *pbVar6) {
            if (bVar1 != 0) {
                bVar1 = (unsigned char)pAVar2->nameValue[1];
                bVar7 = bVar1 < pbVar6[1];
                if (bVar1 != pbVar6[1]) {
                    goto LAB_00411440;
                }
                pAVar2 = (AIPlay*)((char*)pAVar2 + 2);
                pbVar6 = pbVar6 + 2;
                if (bVar1 != 0) {
                    continue;
                }
            }
            iVar3 = 0;
        } else {
LAB_00411440:
            iVar3 = (1 - (unsigned)bVar7) - (unsigned)(bVar7 != 0);
        }
        if (iVar3 == 0) {
            return iVar4;
        }
        iVar4 = iVar4 + 1;
        pAVar2 = pAVar6 + 1;
        pbVar6 = (unsigned char*)name;
        pAVar6 = pAVar2;
        if (this->numberPlaysValue <= iVar4) {
            return -1;
        }
    } while (1);
}
