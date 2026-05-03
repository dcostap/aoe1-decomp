// VA: 005008A0 TribeTacticalAIModule::groupUnitIsIn (71B)
// PDB source: taitacmd.cpp lines 11465-11473
// tried the direct sentinel-walk shape with a single group temp and inline `&this->groups` compares
// best result keeps `mov edi,[esp+10]` before `test esi,esi` and matches most of the body/call sequence, but VC5 still lowers the post-`group = group->next` tail as `cmp esi,ebx ; je ret0 ; jmp loop` instead of the original single `cmp esi,ebx ; jne loop` fallthrough-to-ret0 basin

class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;

    int containsUnit(int unit);
};

class TacticalAIModule {
public:
    char gap_00[0x9D4];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TacticalAIGroup groups;

    TacticalAIGroup* groupUnitIsIn(int unit);
};

TacticalAIGroup* TribeTacticalAIModule::groupUnitIsIn(int unit) {
    TacticalAIGroup* group;
    TacticalAIGroup* end;

    group = this->groups.next;
    end = &this->groups;
    if (group == end) {
        goto not_found_outer;
    }
    while (1) {
        if (group == 0) {
            goto not_found_outer;
        }
        if (group->containsUnit(unit) == 1) {
            return group;
        }
        group = group->next;
        if (group == end) {
            return 0;
        }
    }

not_found_outer:
    return 0;
}
