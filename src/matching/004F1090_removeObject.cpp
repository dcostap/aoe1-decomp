// VA: 004F1090 TribeTacticalAIModule::removeObject
// PDB: taitacmd.cpp:3172-3197
//
// Attempt log:
// - Replaced the former one-array/helper scaffold with the binary-backed
//   tactical list ownership and the natural repeated scan/compact source.
// - Baseline rebuilt 827 bytes with two extra removeFromGroup calls; the
//   canonical fields/call family were right but the helper scaffold was not.
// - Deferred index initialization until after removeFromTaskLists and routed
//   the normal paths through one group-removal tail; this reduced the build to
//   792 bytes and one extra call.
// - Reset the scan index before each list and let boat removal continue into
//   the war-boat scan; size and all ten ordered call sites then matched.
// - Mirrored the exact ManagedArray donor's bounded for scans and
//   value[i]=value[i+1] compaction.  The best source-shaped basin is 768 bytes
//   (original 765), with 607 strict diff bytes and 216 edit/resync bytes.
// - Positive count guards plus reversed i/capacity comparison improved the
//   structural alignment; a do/while variant was worse and was rolled back.
// - An ordinary zero local, register-qualified zero, per-loop pointer aliases,
//   and a narrow volatile member-pointer reload were codegen duplicates.  The
//   remaining gap is the original EBX zero/prologue allocation and associated
//   block placement; calls, frame, boundary, and size are otherwise aligned.
// - Removing the outer count guards reduced the CFG count but regressed to 744
//   bytes and 730 diff bytes; rolled back.  Reset do/while scans reached the
//   exact 765-byte size and saved EBX, but used EBX for the count and regressed
//   to 659 diff bytes and 67.74% shape; rolled back.
// - Zero locals derived from objectId or the scan index, and explicit stage-skip
//   gotos, all emitted the clean candidate unchanged; no new structural lead.
// - Tested natural inline ManagedArray contains/remove calls with early
//   returns.  EBX and several structural blocks aligned, but size fell to 632
//   bytes and one removeFromGroup call site disappeared; restored.
// - Tested natural inline contains iteration for the first three list gates.
//   The compiler inlined auxiliary contains calls too, losing four call sites
//   and growing to 804 bytes; restored the clean candidate.
// - Reconstructed the decompiler's shared count/pointer scan topology.  It
//   recovered the saved-EBX prologue but grew to 839 bytes, with a broad CFG
//   shift; restored the clean candidate.
// - Corrected the boat-removal continuation into the war-boat scan.  This
//   restored the ten-call sequence, but the shared scan source remained far
//   outside the clean structural basin; restored.
// - Tried a no-reinitialization scan-index form and a first-scan do-while
//   form.  They improved some block counts, but moved strict diff to 710 and
//   682 bytes; restored the 607-byte clean source.
// - Renewed pass: 21 distinct source, liveness, control-flow, and context
//   probes reproduced the 768-byte source-shaped basin or regressed it.  The
//   best clean result remains 607 strict diff bytes with all ten ordered calls,
//   the frameless boundary, and the correct owning symbol.  The unresolved
//   blocker is the original saved-EBX zero/register basin and block layout.
// - ManagedArray recovery restored the exact contains and remove bodies and
//   replaced the caller-side scans with direct API calls. This recovered the
//   original saved EBX, all ten calls, and every block.
// - VC5 inlines the first three remove calls. The original TU also inlines the
//   fourth war-boat call, but the isolated TU exhausts its inline budget there.
//   The retained war-boat block is the exact remove donor body. A direct call
//   adds one call and removes 92 bytes, so it cannot model the executable.
// - The original control flow checks war, fishing, trade, and transport only
//   after a successful boat removal. If the boat scan fails, it checks only
//   artifacts. This source preserves that shipped list ownership.
// - Exact-finish removal of temporary inline-depth pragmas remained exact.
// - Fresh exact-finish audit: replacing the fourth war-boat inline remove body
//   with a natural remove call produced 673 bytes, 11 calls, and 397 strict
//   diff bytes. Restoring the body rebuilt the 765-byte exact result in the
//   authentic taitacmd.cpp translation unit.

#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TribeMainDecisionAIModule;

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int contains(const T& item) const {
        int i;
        T wanted;
        T current;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                return 0;
            current = this->value[i];
            wanted = item;
            if (current == wanted)
                return 1;
        }
        return 0;
    }

    int remove(T item) {
        int i = 0;
        int maximum = this->maximumSizeValue;
        for (; i < maximum; i++) {
            if (this->value[i] == item)
                break;
        }
        if (i >= maximum)
            return 0;
        maximum--;
        if (i < maximum) {
            do {
                this->value[i] = this->value[i + 1];
                i++;
            } while (i < this->maximumSizeValue - 1);
        }
        this->numberValue--;
        if (this->numberValue < 0)
            this->numberValue = 0;
        return 1;
    }
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;

    void removeFromTaskLists(int objectId);
    int removeFromGroup(int objectId);
    void removeObject(int objectId);
};
#endif

void TribeTacticalAIModule::removeObject(int objectId)
{
    this->removeFromTaskLists(objectId);

    if (this->civilians.contains(objectId)) {
        this->civilians.remove(objectId);
    } else if (this->soldiers.contains(objectId)) {
        this->soldiers.remove(objectId);
    } else {
        if (this->boats.contains(objectId)) {
            this->boats.remove(objectId);

            if (this->warBoats.contains(objectId)) {
                // BINARY NOTE: Exact remove body at the fourth inline site.
                int removeIndex = 0;
                int maximum = this->warBoats.maximumSizeValue;
                for (; removeIndex < maximum; removeIndex++) {
                    if (this->warBoats.value[removeIndex] == objectId)
                        break;
                }
                if (removeIndex < maximum) {
                    maximum--;
                    if (removeIndex < maximum) {
                        do {
                            this->warBoats.value[removeIndex] =
                                this->warBoats.value[removeIndex + 1];
                            removeIndex++;
                        } while (removeIndex <
                                 this->warBoats.maximumSizeValue - 1);
                    }
                    this->warBoats.numberValue--;
                    if (this->warBoats.numberValue < 0)
                        this->warBoats.numberValue = 0;
                }
                this->removeFromGroup(objectId);
                return;
            }
            if (this->fishingBoats.contains(objectId))
                this->fishingBoats.remove(objectId);
            else if (this->tradeBoats.contains(objectId))
                this->tradeBoats.remove(objectId);
            else if (this->transportBoats.contains(objectId))
                this->transportBoats.remove(objectId);
        } else {
            if (this->artifacts.contains(objectId))
                this->artifacts.remove(objectId);
        }
    }

    this->removeFromGroup(objectId);
}
