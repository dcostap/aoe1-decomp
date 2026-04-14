struct TacticalAIGroup {
    char gap_0[0x14];
    int numberUnits;
    int units[40];
};

int __fastcall containsUnit(TacticalAIGroup* self, int, int unitId) {
    for (int i = 0; i < self->numberUnits; i++) {
        if (self->units[i] == unitId)
            return 1;
    }
    return 0;
}
