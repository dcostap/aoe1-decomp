// 004C7B60 RGE_Static_Object::removeFromGroup(int param_1)
// Source: stat_obj.cpp lines 4928-4939
// Size: 102 bytes, 42 asm lines

// exact: search phase needs an outer positive count guard plus a `while (1)`
// loop that breaks both on found and on exhausted, followed by a separate
// `if (index >= count) { result = 0; goto final; }`. This preserves the original
// simple `cmp [edx],edi; je found; inc/add; cmp index,count; jl loop` search loop
// and the not-found `xor eax,eax; jmp shared_epilogue` shape.

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Static_Object {
public:
    char pad_00[0x64];
    ManagedArray_int groupMembers;
    char pad_74[0x4];
    int groupCommanderValue;

    int removeFromGroup(int param_1);
};
#endif

int RGE_Static_Object::removeFromGroup(int param_1) {
    int count = groupMembers.maximumSizeValue;
    int index = 0;
    int result;

    if (count > 0) {
        int* ptr = groupMembers.value;
        while (1) {
            if (*ptr == param_1) break;
            ++index;
            ++ptr;
            if (index < count) continue;
            break;
        }
    }
    if (index >= count) {
        result = 0;
        goto final;
    }

    if (index < groupMembers.maximumSizeValue - 1) {
        while (index < groupMembers.maximumSizeValue - 1) {
            groupMembers.value[index] = groupMembers.value[index + 1];
            ++index;
        }
    }

    --groupMembers.numberValue;
    if (groupMembers.numberValue < 0) {
        groupMembers.numberValue = 0;
    }
    result = 1;

final:
    if (groupMembers.numberValue <= 0) {
        groupCommanderValue = -1;
    }
    return result;
}
