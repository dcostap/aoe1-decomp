// tried direct compare, static s_Any, explicit byte temps, and an explicit match flag
// switching to the branchless compare-return shape from the packet to chase the 82-byte basin
static char s_Any[] = "Any";

class AIPlayBook {
public:
    int convertTargetNameToIntType(char* param_1) const;
};

int AIPlayBook::convertTargetNameToIntType(char* param_1) const {
    unsigned char* pbVar2 = (unsigned char*)s_Any;
    unsigned char bVar1;
    bool bVar3;

    while (1) {
        bVar1 = (unsigned char)*param_1;
        bVar3 = bVar1 < *pbVar2;
        if (bVar1 != *pbVar2) {
            break;
        }
        if (bVar1 == 0) {
            return 5;
        }
        bVar1 = (unsigned char)param_1[1];
        bVar3 = bVar1 < pbVar2[1];
        if (bVar1 != pbVar2[1]) {
            break;
        }
        param_1 = param_1 + 2;
        pbVar2 = pbVar2 + 2;
        if (bVar1 == 0) {
            return 5;
        }
    }

    return (-(unsigned)(1 - bVar3 != (unsigned)(bVar3 != 0)) & 0xFB) + 5;
}
