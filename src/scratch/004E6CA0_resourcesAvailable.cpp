// 004E6CA0 TribeResourceAIModule::resourcesAvailable
// Source: tairesmd.cpp lines 82-110
// Size: 147 bytes, no EH
//
// Attempt log:
// Probe 1: standalone class + for-loop with count local -> 144 bytes, wrong offset, ebp for this
// Probe 2: direct-pointer chain + for-loop -> extra number() at loop entry (85% diff)
// Probe 3: infinite loop with bottom break + inline chain -> completely different (122% diff)
// Probe 4: do-while + limits temp -> 60% diff, ebp for this, test ah,1 vs test ah,41h
// Probe 5: for(;;) with top i>=number() break -> wrong structure
// Retry 2026-05-19/20 assigned pass:
// - Restored full local model after comment-only scratch and validated natural do/while implementation: 147/147, MISMATCH, 33.3333% positional / 28.5714% edit, first mismatch +9.
// - Source now gets the original `test ah,41h` FPU compare but still chooses EBP=this and EBX=available; original wants EBX=this and EBP=available.
// - Tried explicit `n` local and bottom `n=item->number()` spelling: no codegen change.
// - Tried `self=this` local to encourage EBX for module: no codegen change.
// - Tried reversed FPU predicate `(float)needed > available[i]`: no codegen change.
// - /G5 and /Ob0 flag probes: no change; flags removed.
// GIVEUP: behavior/calls/offsets/FPU predicate are understood, but remaining mismatch is broad register allocation and loop layout (including duplicated rebuilt loop body vs original single loop body). No accepted_drift: not localized.

class ResourceItem {
public:
    int number();
    int value(int i);
};

class TribeResourceAIModule {
public:
    char gap_00[0xF0];
    void* md;                 // +0xF0, md+0xF0 -> ?, +0x50 -> float resources
    int numberResourcesValue; // +0xF4

    int resourcesAvailable(ResourceItem* item);
};

int TribeResourceAIModule::resourcesAvailable(ResourceItem* item)
{
    TribeResourceAIModule* self = this;
    if (item == 0)
        return 0;

    if (self->numberResourcesValue != item->number())
        return 0;

    int i = 0;
    int n = item->number();
    if (n <= 0)
        return 1;

    do {
        float* available = *(float**)((char*)*(void**)((char*)self->md + 0xF0) + 0x50);
        int needed = item->value(i);
        if ((float)needed > available[i])
            return 0;
        i++;
        n = item->number();
    } while (i < n);

    return 1;
}
