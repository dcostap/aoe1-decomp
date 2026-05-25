// VA: 004C7920 RGE_Static_Object::addToGroup
// stat_obj.cpp lines 4868-4880
// Fresh 2026-05-19: replace incorrect 32-byte stub with packet-derived groupMembers logic.
// try 1: decompiler-shaped logic with locals at top: exact-size 162B, 149/162 positional, first mismatch +0;
//        compiler saves EBX/EBP/ESI/EDI at entry instead of original early ESI-only cap check.
// try 2: move local declarations after cap check: no codegen change.
// try 3: invert outer cap into positive guarded body: worsened to near jge and same early saves; rolled back.
// Remaining drift is broad register/prologue/control-flow basin. Original delays EDI/EBP/EBX saves until after
// cap success and uses ECX=count through duplicate scan/realloc; rebuilt saves all callee-saves at entry and
// uses EDX/count plus pointer-walk duplicate scan. Not accepted-drift safe.
// Retry 2026-05-20: 16 more probes. Tried block-scoped locals after cap, positive/goto cap guard,
// shared found return, scan locals to mimic original, for-loop scan, combined/case-body copy loops,
// volatile/raw count guard, late groupIndex alias, parameter stack cast, count-before-cap, and raw
// offset-only member accesses. All close variants still first-mismatch at offset 0 with eager
// EBX/EBP/ESI/EDI save family; best metric remained broad ~91.36% positional / 53.70% edit.
// GIVEUP: exact blocker is VC5 choosing eager callee-saved prologue and pointer-walk scan/copy
// instead of original delayed-save basin. Not accepted_drift: broad prologue/control-flow/register
// allocation mismatch, not localized benign drift.
// Retry 2026-05-21 Boss pass: revalidated baseline (162B, ~91.98% positional, first mismatch 0). Tried direct indexed scan/copy, positive outer cap body, for-loop scan, no count local, goto cap, flags /Ob0 /O2-no-/Oy /Oa /O1 /G5, ManagedArray-style surface, delayed-scope/goto found shape, early count condition, and register this alias. No variant reached the original delayed-save prologue; best edit-only variants still kept broad eager EBX/EBP/ESI/EDI save or otherwise failed to compile cleanly. Left scratch unchanged; not accepted_drift.
// Retry 2026-05-24 assigned pass: MATCH. The key was combining the close while/for combined-copy source with a volatile raw read only for the initial capacity guard. That blocks VC5 from reusing the count load for the later `count` local, restoring the original direct `cmp [esi+68h],19h` early-return and delayed callee-save prologue.

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* p);

class RGE_Static_Object {
public:
    char gap_00[0x64];
    int* group_value;        // +0x64
    int group_number;        // +0x68
    char gap_6C[4];
    int group_maximum;       // +0x70

    int addToGroup(int groupIndex, float unused);
};

int RGE_Static_Object::addToGroup(int groupIndex, float unused)
{
    if (*(volatile int*)((char*)this + 0x68) >= 25) {
        return 0;
    }

    {
        int count = this->group_number;
        int i = 0;
        while (i < count) {
            if (i >= this->group_maximum) {
                break;
            }
            if (this->group_value[i] == groupIndex) {
                goto done;
            }
            i++;
        }

        if (count > this->group_maximum - 1) {
            int newMax = count + 1;
            int* newArray = (int*)operator_new(newMax * 4);
            if (newArray != 0) {
                for (i = 0; i < this->group_maximum && i < newMax; i++) {
                    newArray[i] = this->group_value[i];
                }
                operator_delete(this->group_value);
                this->group_value = newArray;
                this->group_maximum = newMax;
            }
        }

        this->group_value[this->group_number] = groupIndex;
        this->group_number++;
    }

done:
    return 1;
}
