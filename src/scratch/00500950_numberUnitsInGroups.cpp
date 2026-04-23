// first pass: walk the circular TacticalAIGroup list, filtering by type unless param_1 == -1
// if this misses, the remaining gap is likely just the exact loop shape or local register ordering around the sentinel
// attempt log:
// fixed the group/sentinel layout to the circular list shape; that moved the first mismatch from the group offset to the loop prologue
// tried combined guard, split guard, and early copied type local forms; the remaining mismatch is now VC5 control-flow / register-basin drift around the loop header
// left in scratch because the logic is right but the emitted branch/register order is still unstable
class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int type() const;
    int numberUnits() const;
};

class TacticalAIModule {
public:
    char gap_00[0x9D4];
    TacticalAIGroup groups;
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    int numberUnitsInGroups(int type);
};

int TribeTacticalAIModule::numberUnitsInGroups(int type) {
    TacticalAIGroup* group = this->groups.next;
    TacticalAIGroup* end = &this->groups;
    int total = 0;
    int wanted = type;

    if (group != end) {
        if (group != 0) {
            do {
                if (wanted == -1) {
                    total += group->numberUnits();
                }
                else if (group->type() == wanted) {
                    total += group->numberUnits();
                }
                group = group->next;
            } while (group != end);
        }
    }
    return total;
}
