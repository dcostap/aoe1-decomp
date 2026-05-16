// 0040B980 ConstructionAIModule::setReferencePoint
// PDB: aiconmod.cpp:393-443, 495 bytes
// Attempt log:
// - v1: natural reconstruction from packet/Ghidra with typed item list, BaseItem accessors, boundary checks, delete/unlink.
// - v2: fixed ConstructionAIModule local layout: ConstructionItem size 0x74, reference fields are floats at +2fc/+300/+304.
// - v3: introduced register self local to probe original EBX this allocation and reduced direct this uses.
// - v4: replaced `delete item` with explicit virtual deleting-dtor-shaped call to reduce compiler delete context.
// - v5: tried /Ob0 flag; no change, removed. Removed register keyword from self as another allocation probe.
// BLOCKER: behavior, sizes, field offsets, call set, and compiled length match (495/495), with first 15 bytes equal. Remaining mismatch is a stable VC5 saved-register/prologue basin: original keeps `this` in EBX and delays pushing EBP/ESI/EDI while interleaving parameter stores with the first FPU compare; rebuilt keeps `this` in EDI and pushes EBP/ESI/EDI immediately after the first fcomp. Later body is mostly same but shifted and uses EDI where original uses EBX. Explicit virtual deleting-dtor call improved edit diff vs natural delete, but not the early register basin.

typedef unsigned int uint;

class ConstructionItem {
public:
    virtual void destroy(unsigned int flags);
    char gap_04[0x68];
    ConstructionItem* next;
    ConstructionItem* prev;

    float x();
    float y();
    float z();
    float xSize();
    float ySize();
    void setX(float v);
    void setY(float v);
    void setZ(float v);
};

class ConstructionAIModule {
public:
    char gap_000[0x0f0];
    int numberConstructionLotsValue;
    ConstructionItem constructionLots;
    int numberRandomConstructionLotsValue;
    ConstructionItem randomConstructionLots;
    char gap_1e0[0x2fc - 0x1e0];
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
    ConstructionAIModule* self = this;
    self->mapXSizeValue = mapX;
    self->yReferencePointValue = yRef;
    self->mapYSizeValue = mapY;
    self->xReferencePointValue = xRef;
    self->zReferencePointValue = zRef;

    if (xRef <= 0.0 || yRef <= 0.0 || (float)mapX <= xRef || (float)mapY <= yRef) {
        self->removeOldLots();
        return;
    }

    ConstructionItem* item = self->constructionLots.next;
    ConstructionItem* end = &self->constructionLots;
    if (item == end || item == 0) {
        return;
    }

    do {
        item->setX(item->x() + xRef);
        item->setY(item->y() + yRef);
        item->setZ(item->z() + zRef);

        if (item->x() - item->xSize() * 0.5f < 0.0f ||
            item->y() - item->ySize() * 0.5f < 0.0f ||
            item->x() - item->xSize() * -0.5f > (float)(this->mapXSizeValue - 1) ||
            item->y() - item->ySize() * -0.5f > (float)(this->mapYSizeValue - 1)) {
            self->numberConstructionLotsValue--;
            ConstructionItem* next = item->next;
            item->prev->next = next;
            item->next->prev = item->prev;
            item->destroy(1);
            item = next;
        } else {
            item = item->next;
        }
    } while (item != end);
}
