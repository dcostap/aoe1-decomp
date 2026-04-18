struct ConstructionItem { int pad; int priority; };
int __cdecl operator_greater(const ConstructionItem& a, const ConstructionItem& b) {
    return a.priority > b.priority;
}
