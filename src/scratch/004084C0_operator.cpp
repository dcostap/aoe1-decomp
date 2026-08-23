struct BuildItem {
    int pad;
    int priority;
};

int __cdecl operator_less(const BuildItem& a, const BuildItem& b) {
    return a.priority < b.priority;
}
