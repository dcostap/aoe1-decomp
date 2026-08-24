// operator!=(const ResourceItem&, const ResourceItem&)
// VA: 00412140 | airesitm.cpp:133-141

int operator!=(const ResourceItem& lhs, const ResourceItem& rhs) {
    if (lhs.numberValue == rhs.numberValue) {
        for (int i = 0; i < lhs.numberValue; ++i) {
            if (lhs.valueValue[i] != rhs.valueValue[i]) {
                goto not_equal;
            }
        }

        return 0;
    }

not_equal:
    return 1;
}
