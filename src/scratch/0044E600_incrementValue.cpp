// VA: 0044E600 InfluenceMap::incrementValue
// PDB: infmap.cpp lines 240-257 (123 bytes, 45 asm lines)
// Default flags. No inline asm/hacks.
// Retry 2026-05-18/19 (18 honest tries):
// - Revalidated baseline: exact-sized 123 but broad register/order mismatch (71.5447% positional / 60.9756% edit).
// - Tried naming rowData/limit/row/cell/cur locals to force original ESI=rowData and CL=limit; worsened to extra EDI save and 86.1789% positional.
// - Tried precomputing cell vs using row[rx]; original wants both LEA cell in ESI and load from [edx+eax], but VC5 either keeps pointer in EAX or spills cur.
// - Tried `--limit` / `limit-1` saturation spellings; no improvement.
// - Tried preserving coordinate roles by swapping temp names and expression order; VC5 still uses EDX for rx/EAX for ry in baseline, opposite original.
// - Tried /Ob0 briefly; no change, flag removed.
// - 2026-05-19 tried mutating x/y parameter slots; got original initial EAX=x/EDX=xRef but introduced extra EDI save and worse body.
// - 2026-05-19 tried x-mutated/y-local, explicit assignment locals, register locals, and swapped parameter names; either same baseline register swap or extra callee-save pressure.
// - 2026-05-19 tried direct row[rx] stores instead of cell local and nested positive bounds checks; both worsened with extra EDI/EBX saves.
// - 2026-05-19 tried real virtual class surface from type dump; no codegen change from flat vtable field.
// - 2026-05-19 later pass tried parameter mutation (x-=ref/y-=ref) with named rows/row/limit/cell: got original EAX=x start but added EDI save and worsened to 86%+ positional.
// - Tried x-mutated with y local and value+cur order: still added EDI save and worsened to 87.8% positional.
// - Tried value parameter as int and split rx/ry copy-then-sub assignments: no change from baseline register-swap basin.
// GIVEUP: remaining blocker is combined register allocation (original EAX=rx, EDX=ry, ESI=cell, CL=limit) plus exact unsigned-byte widening/order around sum and saturation. No accepted_drift proposal because drift changes stack spills/register topology/control displacements broadly.

struct InfluenceMap {
    int vtable;
    int xSize;
    int ySize;
    int xReferencePoint;
    int yReferencePoint;
    unsigned char* valueValue;
    unsigned char** rowData;
    int coverageCount;
    int connectionCount;
    unsigned char maxLimit;

    int incrementValue(int x, int y, unsigned char value);
};

int InfluenceMap::incrementValue(int x, int y, unsigned char value) {
    int rx = x;
    int ry = y;
    rx -= this->xReferencePoint;
    ry -= this->yReferencePoint;

    if (rx < 0 || ry < 0 || rx >= this->xSize || ry >= this->ySize)
        return 0;

    unsigned char* cell = this->rowData[ry] + rx;
    unsigned char cur = *cell;

    if (cur >= this->maxLimit)
        return 1;

    unsigned int sum = (unsigned int)(unsigned char)cur + (unsigned int)(unsigned char)value;

    if (sum >= (unsigned int)(unsigned char)this->maxLimit) {
        *cell = (unsigned char)((unsigned int)(unsigned char)this->maxLimit - 1);
        return 1;
    }

    *cell = (unsigned char)sum;
    return 1;
}
