class ConstructionItem {
public:
    char gap_00[0x50];
    float x;
    float y;
};

int __cdecl operator==(const ConstructionItem& a, const ConstructionItem& b) {
    if (a.x == b.x && a.y == b.y) {
        return 1;
    }
    return 0;
}
