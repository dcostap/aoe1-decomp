// VA: 004E02A0 TribeInformationAIModule::storeLot
// PDB: taiinfmd.cpp:5774-5841
// Default flags: /nologo /c /O2 /Oy
//
// Baseline reconstruction: BuildingLot is the proven 8-byte record at +0x1F8;
// the routine scans for an existing lot or a typeID == -1 slot, then doubles
// the lot array and initializes the new slots when no free slot exists.
//
// Attempt log (sa-f4a574e2-r1, 10 meaningful hypotheses):
// - Baseline: canonical typed BuildingLot fields (+0, +4, +5, +6), max/count
//   at +0x1F4, array at +0x1F8, field-wise growth copy, and real VC5 new/delete
//   declarations. 448 emitted bytes, 391 positional diff; calls and frame align.
// - Reversed coordinate equality operands improved the emitted diff to 381 and
//   preserved parameter-byte reloads, but VC5 still chose the opposite cmp
//   encoding and kept the existing-lot return immediately after the scan.
// - Late-label/goto, explicit alternate-arm, explicit returns, saved-base
//   pointer, and donor <windows.h> context probes were codegen duplicates.
// - Negative-disjunction spelling regressed to the baseline group. A natural
//   break plus post-loop existing-lot arm reached exact size and 347 diff, but
//   emitted an extra i/max test absent from the oracle; retained only as
//   diagnostic evidence and restored this simpler source.
// - Raw cursor/decompiler-shaped field plumbing was worse (444 bytes, 391
//   diff), so it is not retained. Remaining blocker is structural: the oracle
//   sends the existing-lot branch to a late handler at 004E044E while default
//   VC5 lowering places that handler immediately after the scan.
// - Reversed the typed x/y equality operands, following the neighboring
//   taiinfmd lot helpers; this keeps parameter-byte loads in the first scan
//   hunk and tests the direct source form without changing ownership.
// - Direct indexed BuildingLot scan improved the diagnostic diff to 368 bytes
//   and shape to 94.16%, but moved freeIndex into edi, added one byte, and
//   lost the oracle's pointer-walk prologue; restored the pointer-walk source.
// - Memory-first x/y comparisons fixed the local compare encoding only; the
//   indexed scan stayed at 368 bytes and did not restore the original CFG.
// - A natural matched-lot pointer carried the existing record past the scan;
//   this moved the first prologue hunk and regressed to 451 bytes / 417 diff.
//   Restored the pointer-walk source; the late existing-lot handler remains
//   the structural blocker.
// - This pass tested explicit late labels, explicit returns, negative-arm
//   nesting, and removeLot-style scan labels; VC5 emitted the same 448-byte
//   basin and kept the matched-lot handler beside the scan.
// - A canonical for-loop changed the prologue and grew the body to 454 bytes.
//   A break plus post-loop guard changed the prologue and fell to 444 bytes.
//   Both were restored because they lost the proven source shape.
// - Final validation: 448 bytes versus 450, calls and frame match, 381 strict
//   differing bytes. The unresolved drift is the two-byte loop reversal and
//   the late matched-lot block placement.
// - Accepted drift: scan order, free-slot choice, allocation size, field-wise
//   copy order, new-slot initialization, deletion, pointer publication, record
//   stores, capacity update, and returns match. Both allocation calls have the
//   same arguments and stack context. The late matched-lot handler and loop
//   branch direction are control-flow placement only.
// - Fresh finish pass: restored the reviewed full information-AI/object header
//   surface. The natural body stayed in the 448-byte / 381-diff basin.
// - Fresh probes: memory-left coordinate compares worsened to 391 bytes;
//   while, max-local, pointer-lifetime, split-initializer, negative-disjunction,
//   and explicit positive-backedge forms did not improve the clean basin.
//   Default flags without the target /Gs addition produced the same listing.
// - Exact-finish result: no exact source was found. The remaining binary facts
//   are the late status handler at +01AE and direct scan jl at +0051. Natural
//   VC5 lowering keeps the status handler before allocation and emits jge+jmp.

#include <stddef.h>
#include "../../include/information_dropsites_context.h"

void TribeInformationAIModule::storeLot(int typeID, unsigned char x,
                                        unsigned char y, unsigned char built)
{
    int freeIndex = -1;
    int i = 0;

    if (this->maxBuildingLots > 0) {
        BuildingLot* lot = this->buildingLots;
        do {
            if (lot->typeID == typeID && x == lot->x && y == lot->y) {
                this->buildingLots[i].status = built;
                return;
            }

            if (freeIndex == -1 && lot->typeID == -1) {
                freeIndex = i;
            }

            ++i;
            ++lot;
        } while (i < this->maxBuildingLots);
    }

    if (freeIndex == -1) {
        BuildingLot* newLots = (BuildingLot*)::operator new(
            this->maxBuildingLots << 4);
        if (newLots != 0) {
            i = 0;
            if (this->maxBuildingLots > 0) {
                do {
                    newLots[i].typeID = this->buildingLots[i].typeID;
                    newLots[i].x = this->buildingLots[i].x;
                    newLots[i].y = this->buildingLots[i].y;
                    newLots[i].status = this->buildingLots[i].status;
                    ++i;
                } while (i < this->maxBuildingLots);
            }

            if (i < this->maxBuildingLots * 2) {
                do {
                    newLots[i].typeID = -1;
                    newLots[i].x = 0;
                    newLots[i].y = 0;
                    newLots[i].status = built;
                    ++i;
                } while (i < this->maxBuildingLots * 2);
            }

            ::operator delete(this->buildingLots);
            this->buildingLots = newLots;

            newLots[this->maxBuildingLots].typeID = typeID;
            this->buildingLots[this->maxBuildingLots].x = x;
            this->buildingLots[this->maxBuildingLots].y = y;
            this->buildingLots[this->maxBuildingLots].status = built;
            this->maxBuildingLots <<= 1;
        }
    } else {
        this->buildingLots[freeIndex].typeID = typeID;
        this->buildingLots[freeIndex].x = x;
        this->buildingLots[freeIndex].y = y;
        this->buildingLots[freeIndex].status = built;
    }
}
