struct ConstructionItem { int pad; int priority; };
int __cdecl operator_less(const ConstructionItem& a, const ConstructionItem& b) {
    return a.priority < b.priority;
}
