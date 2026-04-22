class BaseItem {
public:
    char gap_00[0x8];
    int value;
};

int __cdecl operator<(BaseItem const& lhs, BaseItem const& rhs) {
    return lhs.value < rhs.value;
}
