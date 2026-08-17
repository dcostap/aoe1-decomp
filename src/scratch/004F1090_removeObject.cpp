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

    int contains(const T& valueToFind);
    int remove(T valueToRemove);
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

void TribeTacticalAIModule::removeObject(int objectId)
{
    this->removeFromTaskLists(objectId);

    int i = 0;

    if (this->civilians.numberValue > 0) {
        for (i = 0; i < this->civilians.numberValue; i++) {
            if (i >= this->civilians.maximumSizeValue)
                break;
            if (this->civilians.value[i] == objectId)
                goto remove_civilian;
        }
    }

    if (this->soldiers.numberValue > 0) {
        for (i = 0; i < this->soldiers.numberValue; i++) {
            if (i >= this->soldiers.maximumSizeValue)
                break;
            if (this->soldiers.value[i] == objectId)
                goto remove_soldier;
        }
    }

    if (this->boats.numberValue > 0) {
        for (i = 0; i < this->boats.numberValue; i++) {
            if (i >= this->boats.maximumSizeValue)
                break;
            if (this->boats.value[i] == objectId)
                goto remove_boat;
        }
    }

scan_war_boats:
    if (this->warBoats.numberValue > 0) {
        for (i = 0; i < this->warBoats.numberValue; i++) {
            if (i >= this->warBoats.maximumSizeValue)
                break;
            if (this->warBoats.value[i] == objectId)
                goto remove_war_boat;
        }
    }

    if (this->fishingBoats.contains(objectId) != 0) {
        this->fishingBoats.remove(objectId);
    } else if (this->tradeBoats.contains(objectId) != 0) {
        this->tradeBoats.remove(objectId);
    } else if (this->transportBoats.contains(objectId) != 0) {
        this->transportBoats.remove(objectId);
    } else if (this->artifacts.contains(objectId) != 0) {
        this->artifacts.remove(objectId);
    }

    goto done;

done:
    this->removeFromGroup(objectId);
    return;

remove_civilian:
    i = 0;
    if (this->civilians.maximumSizeValue > 0) {
        do {
            if (this->civilians.value[i] == objectId)
                break;
            i++;
        } while (i < this->civilians.maximumSizeValue);
    }
    if (i < this->civilians.maximumSizeValue) {
        int max = this->civilians.maximumSizeValue - 1;
        if (i < max) {
            do {
                this->civilians.value[i] = this->civilians.value[i + 1];
                i++;
            } while (i < this->civilians.maximumSizeValue - 1);
        }
        this->civilians.numberValue--;
        if (this->civilians.numberValue < 0) {
            this->civilians.numberValue = 0;
            this->removeFromGroup(objectId);
            return;
        }
    }
    goto done;

remove_soldier:
    i = 0;
    if (this->soldiers.maximumSizeValue > 0) {
        do {
            if (this->soldiers.value[i] == objectId)
                break;
            i++;
        } while (i < this->soldiers.maximumSizeValue);
    }
    if (i < this->soldiers.maximumSizeValue) {
        int max = this->soldiers.maximumSizeValue - 1;
        if (i < max) {
            do {
                this->soldiers.value[i] = this->soldiers.value[i + 1];
                i++;
            } while (i < this->soldiers.maximumSizeValue - 1);
        }
        this->soldiers.numberValue--;
        if (this->soldiers.numberValue < 0) {
            this->soldiers.numberValue = 0;
            this->removeFromGroup(objectId);
            return;
        }
    }
    goto done;

remove_boat:
    i = 0;
    if (this->boats.maximumSizeValue > 0) {
        do {
            if (this->boats.value[i] == objectId)
                break;
            i++;
        } while (i < this->boats.maximumSizeValue);
    }
    if (i < this->boats.maximumSizeValue) {
        int max = this->boats.maximumSizeValue - 1;
        if (i < max) {
            do {
                this->boats.value[i] = this->boats.value[i + 1];
                i++;
            } while (i < this->boats.maximumSizeValue - 1);
        }
        this->boats.numberValue--;
    }
    goto scan_war_boats;

remove_war_boat:
    i = 0;
    if (this->warBoats.maximumSizeValue > 0) {
        do {
            if (this->warBoats.value[i] == objectId)
                break;
            i++;
        } while (i < this->warBoats.maximumSizeValue);
    }
    if (i < this->warBoats.maximumSizeValue) {
        int max = this->warBoats.maximumSizeValue - 1;
        if (i < max) {
            do {
                this->warBoats.value[i] = this->warBoats.value[i + 1];
                i++;
            } while (i < this->warBoats.maximumSizeValue - 1);
        }
        this->warBoats.numberValue--;
        if (this->warBoats.numberValue < 0) {
            this->warBoats.numberValue = 0;
            this->removeFromGroup(objectId);
            return;
        }
    }
    goto done;
}
