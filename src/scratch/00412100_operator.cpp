// operator==(const ResourceItem&, const ResourceItem&)
// VA: 00412100 | airesitm.cpp:120-128

int operator==(const ResourceItem& lhs, const ResourceItem& rhs) {
    if (lhs.numberValue == rhs.numberValue) {
        for (int i = 0; i < lhs.numberValue; ++i) {
            if (lhs.valueValue[i] != rhs.valueValue[i]) {
                goto not_equal;
            }
        }

        return 1;
    }

not_equal:
    return 0;
}
