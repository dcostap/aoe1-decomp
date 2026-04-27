// first pass: count-gated scan across the 0x10-stride placement entries at +0x12C8/+0x12CC
// tried the head-count test in signed-zero and signed-one forms, plus while/do/goto loop shapes; mismatch is now localized to the count-test / loop-back VC5 basin
// pausing in scratch for now because the behavior is right and the remaining difference is codegen shape, not control flow or data access
class RGE_Object_Info_Line;

class RGE_RMM_Object_Generator {
public:
    char pad_000[0x12C8];
    long entry_x;
    long entry_y;
    char pad_12D0[0x628];
    long count;

    unsigned char to_close(RGE_Object_Info_Line* info_line, long x, long y);
};

class RGE_Object_Info_Line {
public:
    char pad_00[0x24];
    long land_inner_radius;
};

unsigned char RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line* info_line, long x, long y) {
    int iVar1;
    int iVar2;
    int iVar3;
    long* plVar4;
    int iVar5;

    iVar1 = this->count;
    iVar5 = 0;
    if (iVar1 < 1) {
        return 0;
    }

    plVar4 = (long*)((char*)this + 0x12CC);
    while (true) {
        iVar3 = x - *(plVar4 - 1);
        if (iVar3 < 0) {
            iVar3 = -iVar3;
        }
        iVar2 = y - *plVar4;
        if (iVar2 < 0) {
            iVar2 = -iVar2;
        }
        if ((iVar3 < info_line->land_inner_radius) && (iVar2 < info_line->land_inner_radius)) {
            break;
        }
        iVar5 = iVar5 + 1;
        plVar4 = plVar4 + 4;
        if (iVar1 <= iVar5) {
            return 0;
        }
    }

    return 1;
}
