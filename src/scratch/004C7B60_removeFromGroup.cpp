// 004C7B60 RGE_Static_Object::removeFromGroup(int param_1)
// Source: stat_obj.cpp lines 4928-4939
// Size: 102 bytes, 42 asm lines

// 9 attempts. Best: 30.39% positional diff (attempt 6).
// Structurally close — prologue, entry guard, search loop body (inc/add/jl),
// shift loop (reload max from memory via groupMembers.maximumSizeValue-1),
// decrement/clamp/return 1 all match.
// Remaining diffs:
// - Search loop: original uses `jl loop_top` (back-edge to compare); our VC5
//   generates `jge exit; cmp [edx],edi; jne loop` (inverted loop exit).
// - Not-found path: original `xor eax,eax; jmp shared_epilogue`; our VC5
//   generates `jge not_found_separate_epilogue` with no xor/jmp.
// - Final check uses eax vs edx (register choice).
// All VC5 codegen scheduling differences, not behavioral.

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

int RGE_Static_Object::removeFromGroup(int param_1) {
    int count = groupMembers.maximumSizeValue;
    int index = 0;

    if (count > 0) {
        int* ptr = groupMembers.value;
        do {
            if (*ptr == param_1) {
                break;
            }
            ++index;
            ++ptr;
        } while (index < count);

        if (index < count) {
            while (index < groupMembers.maximumSizeValue - 1) {
                groupMembers.value[index] = groupMembers.value[index + 1];
                ++index;
            }

            --groupMembers.numberValue;
            if (groupMembers.numberValue < 0) {
                groupMembers.numberValue = 0;
            }
            return 1;
        }
    }

    if (groupMembers.numberValue <= 0) {
        groupCommanderValue = -1;
    }
    return 0;
}
