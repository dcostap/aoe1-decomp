class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];

    int unit(int index);
};

// tried decompiler-style pointer walk, straight while/do forms, and an index+continue form.
// Best remaining family still differs in early register/save order:
// original wants param in esi, base in ebx, then push edi; rebuilt keeps pushing edi too early
// and tends to compare/count against a derived `index+1` temp in esi instead of using
// `cmp edx, esi` after the occupied-slot increment. The object now reaches the full 70-byte
// size, so the blocker is codegen shape rather than missing behavior.
int TacticalAIGroup::unit(int index) {
    int i = 0;
    int used = -1;
    int* units = this->unitsValue;

    while (used < index + 1) {
        if (*units != -1) {
            used++;
        }
        if (used == index) {
            return this->unitsValue[i];
        }
        i++;
        units++;
        if (i >= 0x28) {
            return -1;
        }
    }
    return -1;
}
