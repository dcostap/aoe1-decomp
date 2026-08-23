class TechnologyItem {
public:
    char gap_00[0xC];
    int value;
};

int __cdecl operator!=(TechnologyItem const& lhs, TechnologyItem const& rhs) {
    return lhs.value != rhs.value;
}
