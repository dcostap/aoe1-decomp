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
    if (this->group_number >= 25) {
        return 0;
    }

    int count;
    int i;
    int newMax;
    int* newArray;

    count = this->group_number;
    i = 0;
    if (count > 0) {
        do {
            if (i >= this->group_maximum) {
                break;
            }
            if (this->group_value[i] == groupIndex) {
                return 1;
            }
            i++;
        } while (i < count);
    }

    if (count > this->group_maximum - 1) {
        newMax = count + 1;
        newArray = (int*)operator_new(newMax * 4);
        if (newArray) {
            i = 0;
            if (this->group_maximum > 0) {
                do {
                    if (i >= newMax) {
                        break;
                    }
                    i++;
                    newArray[i - 1] = this->group_value[i - 1];
                } while (i < this->group_maximum);
            }
            operator_delete(this->group_value);
            this->group_value = newArray;
            this->group_maximum = newMax;
        }
    }

    this->group_value[this->group_number] = groupIndex;
    this->group_number++;
    return 1;
}
