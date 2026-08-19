// 0040B980 ConstructionAIModule::setReferencePoint
// PDB: aiconmod.cpp:393-443, 495 bytes
// Attempt log:
// - v1: natural reconstruction from packet/Ghidra with typed item list, BaseItem accessors, boundary checks, delete/unlink.
// - v2: fixed ConstructionAIModule local layout: ConstructionItem size 0x74, reference fields are floats at +2fc/+300/+304.
// - v3: introduced register self local to probe original EBX this allocation and reduced direct this uses.
// - v4: replaced `delete item` with explicit virtual deleting-dtor-shaped call to reduce compiler delete context.
// - v5: tried /Ob0 flag; no change, removed. Removed register keyword from self as another allocation probe.
// - v7/session probe 3: tested the full donor ABI and natural delete; it added an EH/cleanup block and
//   moved farther, so restored the clean source.
// - v8/session probe 4: keep the compact slot-0 virtual destroy surface but restore BaseItem ownership of
//   accessors and the proven 0x80-byte ConstructionItem size, isolating ABI/layout from delete lowering.
// - v9/session probe 7: add the donor-proven polymorphic AIModule base while preserving all target offsets;
//   test whether the inherited vptr/class context selects the original EBX/EDI coloring.
// - v10/session probe 9: replaced the diagnostic slot-0 destroy shim with the donor-proven real BaseItem /
//   ConstructionItem virtual-destructor surface and natural delete; it added a 4-byte cleanup block and
//   moved farther, so restored the slot-0 ABI experiment.
// - v11/session probe 10: reused the incoming mapY home for the two computed upper bounds; this changed
//   the condition's expression tree and broad block alignment, so restored the direct member expressions.
// - v12/session variant family: end/item declaration order, branch-local versus top-level next, and /GX
//   all collapsed to the same 495-byte emitted group; no further source/context lead remained.
// - v13/session probe 7: the natural `while (item != end && item != 0)` guard changes the saved self
//   register to EBX and reduces the mismatch from 94 to 30 bytes; the first 334 bytes then align.
// - v14/session probes 8-11: initial field assignment order `mapX, mapY, xRef, yRef, zRef` preserves
//   that alignment. Explicit bound/current temporaries, ordered gotos, and parameter-home mutation
//   did not improve the localized upper-bound FPU stack-home mismatch; the last was diagnostic only.
// BLOCKER: behavior, sizes, field offsets, direct-call ABI, and compiled length match (495/495), with
// first 334 bytes equal. Remaining 30 bytes are localized to x/y upper-bound FPU temporaries: original
// stores each decremented bound at entry-home +8 before fsubr, while rebuilt reuses entry-home +4 after
// fsubr. The observed slot-0 cleanup declaration is kept; natural virtual-destructor/delete lowering
// added a 4-byte null/cleanup block and moved farther.
// Fresh final pass: named integer limits changed the register basin, and
// reversed upper-bound comparisons widened both blocks. Neither was closer.
// ACCEPTED DRIFT: Each changed upper-bound block executes the same x()/xSize()
// or y()/ySize() calls, multiply, reverse subtract, integer-to-float load, and
// comparison in that order. VC5 only moves the non-faulting valid-object bound
// load across the multiply and reuses a private stack home. All compared values,
// floating-point operations, flags, branches, list edits, calls, and cleanup
// match. No private temporary escapes.

typedef unsigned int uint;

class BaseItem {
public:
    virtual void destroy(unsigned int flags);
    char gap_04[0x68];

    float x() const;
    float y() const;
    float z() const;
    float xSize() const;
    float ySize() const;
    void setX(float v);
    void setY(float v);
    void setZ(float v);
};

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;
    ConstructionItem* prev;
    char gap_74[0x0c];
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class ConstructionAIModule : public AIModule {
public:
    int numberConstructionLotsValue;
    ConstructionItem constructionLots;
    int numberRandomConstructionLotsValue;
    ConstructionItem randomConstructionLots;
    char gap_1f8[0x2fc - 0x1f8];
    float xReferencePointValue;
    float yReferencePointValue;
    float zReferencePointValue;
    int mapXSizeValue;
    int mapYSizeValue;

    void removeOldLots();
    void setReferencePoint(int mapX, int mapY, float xRef, float yRef, float zRef);
};

void ConstructionAIModule::setReferencePoint(int mapX, int mapY, float xRef, float yRef, float zRef)
{
    this->mapXSizeValue = mapX;
    this->mapYSizeValue = mapY;
    this->xReferencePointValue = xRef;
    this->yReferencePointValue = yRef;
    this->zReferencePointValue = zRef;

    if (xRef <= 0.0 || yRef <= 0.0 || (float)mapX <= xRef || (float)mapY <= yRef) {
        this->removeOldLots();
        return;
    }

    ConstructionItem* item = this->constructionLots.next;
    ConstructionItem* end = &this->constructionLots;
    while (item != end && item != 0) {
        item->setX(item->x() + xRef);
        item->setY(item->y() + yRef);
        item->setZ(item->z() + zRef);

        if (item->x() - item->xSize() * 0.5f < 0.0f ||
            item->y() - item->ySize() * 0.5f < 0.0f ||
            item->x() - item->xSize() * -0.5f > (float)(this->mapXSizeValue - 1) ||
            item->y() - item->ySize() * -0.5f > (float)(this->mapYSizeValue - 1)) {
            this->numberConstructionLotsValue--;
            ConstructionItem* next = item->next;
            item->prev->next = next;
            item->next->prev = item->prev;
            item->destroy(1);
            item = next;
        } else {
            item = item->next;
        }
    }
}
