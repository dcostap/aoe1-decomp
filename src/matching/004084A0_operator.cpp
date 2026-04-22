class BuildItem {
public:
    char gap_00[0x4];
    int value;
};

int __cdecl operator!=(BuildItem const& lhs, BuildItem const& rhs) {
    return lhs.value != rhs.value;
}
