// operator==(const ResourceItem&, const ResourceItem&)
// VA: 00412100 | airesitm.cpp:120-128
//
// BINARY NOTE: Keep the named left reference and count local.  VC5 then keeps
// the left count in EDX and emits the left value load before the right load.

int operator==(const ResourceItem& lhs, const ResourceItem& rhs) {
    const ResourceItem& left = lhs;
    int count = left.numberValue;
    if (count == rhs.numberValue) {
        for (int i = 0; i < count; ++i) {
            if (left.valueValue[i] != rhs.valueValue[i]) {
                goto not_equal;
            }
        }

        return 1;
    }

not_equal:
    return 0;
}
