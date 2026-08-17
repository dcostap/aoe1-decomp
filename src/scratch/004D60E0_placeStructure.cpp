// 004D60E0 TribeConstructionAIModule::placeStructure (1689 bytes, /GX EH frame)
// Attempt log:
//  1 baseline: natural reconstruction from decompiler + canPlace/placeDock/compare exact donors.
//     Local class stubs; /GX for EH temp ConstructionItem. size EXACT 1689 but missing built()/inProgress() calls.
//  2 add built()/inProgress() guards in size chain: calls fixed but +25 bytes (1714).
//  3 head=&tempLots cleanup (direct-delete): tiny, 1714.
//  4-5 try for-loop / p=tempLots.next cleanup: worse (1778-1786).
//  6 ok-flag nested loop -> goto skip_place (matches binary direct-jump from inner loop past placement):
//     fixed the 4-byte frame (0xB0->0xAC) AND size back to 1689; shape 86.75%. KEY structural fix.
//  7 flat TribeConstructionAIModule (remove ConstructionAIModule base, which shifted vptr into layout +4):
//     fields now at donor offsets 0xF0/0xF4/0x2FC; shape 89.32%, first mismatch +56.
//  8 iterate delete loop from tempLots.next field (virtual dispatch call [edx] matches original):
//     shape 90.12%, edit-diff 590, but +70 bytes (1759) due to /GX EH unwind state growth from delete.
//  10 layout+dtor audit (sa-fc09f788-r1): original stores state_310 at +0x310 and md at +0x314
//     (spurious gap_310 removed); EXPLICIT tempLots.~ConstructionItem() calls REMOVED -- the original
//     emits ONE dtor call per exit with the try-level reset BEFORE the call, which is /GX automatic
//     destruction at return, not an explicit call; an explicit call plus the automatic one doubled the
//     dtor (+3 direct constructionitem calls, +70 bytes). item->typeID() compared first; xSize/ySize
//     are EQUALITY tests (test ah,40h = C3, not C0/less-than): `cur->xSize() == item->xSize()`;
//     best-selection and delete loops are WHILE loops with `n != &tempLots && n != 0` (sentinel test
//     first) whose backedge targets the top null test (orig block layout); `n = best->next` is loaded
//     BEFORE the typeID==0x48 check; dock path is `return new ConstructionItem(dock);` (orig jumps
//     directly to the shared return-0 on operator-new null). Result: size EXACT 1689, calls 62/62
//     (100%), CFG 58/58, shape 99.79%, strict diff 73 bytes / 4.32%, edit 63 / 1.87%.
//
// Remaining drift (49 spans, all register-role + one scheduling hunk in the tempLots setup):
//  - The original emits the /GX try-level store `mov [esp+0C4h],esi` (=1, tempLots alive) AFTER the
//    loop-entry cmp (`cur != end`), with cur allocated to EDI. The rebuilt emits it immediately after
//    the tempLots ctor and allocates cur to ESI, forcing the store before the cur load (WAR on esi:
//    `mov esi,[ebx+160h]` would clobber the state-store operand). This one difference cascades the
//    register roles through the whole loop (cur edi/esi, x0 esi/edi, x1 ebp/ebx, y1 ebx/ebp, item
//    type esi/edi) -- every span is a 1-byte ModRM/dir register swap, no behavior difference.
//  - Exhausted: all 5 setup-statement orders (lab + manual), while vs for, one-line grouping, register
//    cur, single-assignment next/prev, end-inline, /Os /O1 /Og- /Ot flag axes. The state-store
//    position is invariant to all of them; it is a /GX constant-caching (esi=1 reuse from the
//    useInfluencePlacement==1 check) + allocator interaction. The probes (eh_probe3-6) show the
//    default /GX placement is late (after the loop-entry test), matching the original -- only a
//    register-conflict-free cur (edi) reproduces it.
//
// Follow-up sa-603da332-r1: split cur declaration/assignment; move setup declarations before the
// temp; use a for-header cur; mirror the donor destructor declaration; add the later itemType temp;
// add register cur; and restore a correctly sized ConstructionAIModule base. Each emitted the same
// 73-byte diff. A focused /GX lab with the full named BaseItem/ConstructionItem field surface also
// collapsed to the same group. Clean-source reconstruction is therefore restored; no source-model
// or canonical-layout lead moved the first hunk.
//
// Next lead: find a source shape that gives cur a register other than esi at the loop entry (e.g.
//   model the item-type comparison temp, or reorder the loop body so the allocator prefers edi for
//   cur), or a TU/class-surface change that alters the /GX constant caching. Then the state store
//   can sink after the cmp and the whole register cascade resolves.
//
// Follow-up sa-4010606e-r1: 22 meaningful checks. Tested cursor scope and register hints, pointer
// and scalar declaration order, loop forms, sentinel inlining, type-operand order, named type
// temporaries, cursor/best reuse, setup assignment order, self-link chaining, typed aliases, and
// /GX ambient declaration samples. The clean source stayed at 73 bytes. Ambient samples reached
// 72 bytes but did not change the register hunk. Final source is restored and validated.
//
// BINARY NOTE: The original loads constructionLots.next into EDI, compares the sentinel, then
// stores EH state 1. The clean rebuild stores EH state 1 before loading the cursor into ESI.
// This changes only the later register roles; calls, frame, size, and CFG are exact.

// FLAGS: config/flags/004D60E0_placeStructure.rsp uses /GX for original EH frame.

extern int useInfluencePlacement;

class BaseItem {
public:
    virtual ~BaseItem();
    int typeID();
    int uniqueID();
    void setUniqueID(int);
    void setTypeID(int);
    float x();
    float y();
    float xSize();
    float ySize();
    char gap_04[0x68];
};

class ConstructionItem : public BaseItem {
public:
    virtual ~ConstructionItem();
    ConstructionItem();
    ConstructionItem(ConstructionItem*);
    int built();
    int inProgress();
    int buildAttempts();
    void setInProgress(int);
    void incrementBuildAttempts();
    ConstructionItem* next;   // +0x6C
    ConstructionItem* prev;   // +0x70
    char gap_74[0x0C];
};

class BuildItem : public BaseItem {
public:
    char gap_6c[0x44];
};

class PlacementState {
public:
    char pad_0[0x4];
};

class RGE_Static_Object;

class MainDecisionAIModule {
public:
    char pad_0[0x4];
    RGE_Static_Object* object(int a1, int a2, int a3, int a4, int a5,
                              int a6, int a7, int a8, int a9, int a10);
    RGE_Static_Object* object(int a1);
};

class RGE_Static_Object {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68();
    virtual int canPlace(float x, float y, int flag);  // vtable slot 0x114
    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
};

class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    ConstructionItem* lot(float x, float y);
};

class TribeConstructionAIModule {
public:
    char gap_000[0x0F0];
    int field_f0;                                  // +0xF0
    ConstructionItem constructionLots;             // +0xF4 (anchor)
    char gap_174[0x2FC - 0x174];
    float x;                                       // +0x2FC
    float y;                                       // +0x300
    char gap_304[4];
    int max_x;                                     // +0x308
    int max_y;                                     // +0x30C
    int state_310;                                 // +0x310
    MainDecisionAIModule* md;                      // +0x314

    ConstructionItem* placeStructure(BuildItem* item, int x, PlacementState& state, unsigned long flags);
    ConstructionItem* placeDock(BuildItem* item);
    ConstructionItem* compare(ConstructionItem* a, ConstructionItem* b);
    ConstructionItem* lot(float x, float y);
};

class TribeInformationAIModule {
public:
    ConstructionItem* influencePlaceStructure(BuildItem* item, int x, int a, int b, int c,
            int d, int e, int f, int g, PlacementState& state, unsigned long flags);
};

ConstructionItem* TribeConstructionAIModule::placeStructure(BuildItem* item, int x, PlacementState& state, unsigned long flags)
{
    if (this->x <= 0.0 || this->y <= 0.0 || (float)this->max_x <= this->x ||
        (float)this->max_y <= this->y) {
        return ((TribeInformationAIModule*)((char*)this->md + 0xCEC))->influencePlaceStructure(
            item, x, -1, 0, 0, -1, -1, -1, -1, state, flags);
    }

    if (item->typeID() == 0x2D) {
        ConstructionItem* dock = this->placeDock(item);
        if (dock != 0)
            return new ConstructionItem(dock);
        return 0;
    }

    if (item->typeID() == 0x67 || item->typeID() == 0x44 || item->typeID() == 0x4F ||
        item->typeID() == 0xC7 || item->typeID() == 0x45 || item->typeID() == 0x48 ||
        item->typeID() == 0x75 || item->typeID() == 0x9B ||
        useInfluencePlacement == 1 || this->field_f0 == 0) {
        return ((TribeInformationAIModule*)((char*)this->md + 0xCEC))->influencePlaceStructure(
            item, x, -1, 0, 0, -1, -1, -1, -1, state, flags);
    }

    RGE_Static_Object* builderObj = this->md->object(-1, -1, 4, -1, -1, -1, -1, -1, -1, -1);
    if (builderObj == 0)
        return 0;

    RGE_Static_Object* zoneObj = this->md->object(x);
    unsigned char builderZone = 0;
    if (zoneObj != 0)
        builderZone = zoneObj->currentZone();

    ConstructionItem tempLots;
    ConstructionItem* cur = this->constructionLots.next;
    tempLots.next = &tempLots;
    tempLots.prev = &tempLots;
    int count = 0;
    int bestBuildAttempts = -1;
    ConstructionItem* end = &this->constructionLots;

    while (cur != end && cur != 0) {
        if (item->typeID() == cur->typeID() || cur->typeID() == -1) {
            if (cur->xSize() == item->xSize()) {
                if (cur->ySize() == item->ySize()) {
                    if (cur->built() != 1 && cur->inProgress() != 1) {
                        int x0 = (int)(cur->x() - cur->xSize());
                        int y0 = (int)(cur->y() - cur->ySize());
                        int x1 = x0 + (int)cur->xSize();
                        int y1 = y0 + (int)cur->ySize();

                        if (x0 >= 0 && y0 >= 0 && x1 < this->max_x && y1 < this->max_y) {
                            for (int xv = x0; xv < x1; ++xv) {
                                for (int yv = y0; yv < y1; ++yv) {
                                    if ((zoneObj != 0 && zoneObj->lookupZone(xv, yv) != builderZone) ||
                                        builderObj->canPlace((float)xv - -0.5f, (float)yv - -0.5f, 1) == 0) {
                                        goto skip_place;
                                    }
                                }
                            }
                            ConstructionItem* ci = new ConstructionItem(cur);
                            ci->next = &tempLots;
                            ci->prev = tempLots.prev;
                            tempLots.prev->next = ci;
                            tempLots.prev = ci;
                            count++;
                            if (bestBuildAttempts == -1 ||
                                bestBuildAttempts > cur->buildAttempts()) {
                                bestBuildAttempts = cur->buildAttempts();
                            }
                        }
skip_place: ;
                    }
                }
            }
        }
        cur = cur->next;
    }

    if (bestBuildAttempts >= 2 || bestBuildAttempts == -1) {
        ConstructionItem* r = ((TribeInformationAIModule*)((char*)this->md + 0xCEC))->influencePlaceStructure(
            item, x, -1, 0, 0, -1, -1, -1, -1, state, flags);
        if (r != 0)
            return r;
    }

    if (count == 0) {
        this->state_310 = 5;
        return 0;
    }

    ConstructionItem* best = tempLots.next;
    ConstructionItem* n = best->next;
    if (item->typeID() == 0x48) {
        while (n != &tempLots && n != 0) {
            if (best->buildAttempts() > n->buildAttempts() + 5)
                best = n;
            n = n->next;
        }
    } else {
        while (n != &tempLots && n != 0) {
            best = this->compare(best, n);
            n = n->next;
        }
    }

    ConstructionItem* lot = this->lot(best->x(), best->y());
    lot->setInProgress(1);
    lot->incrementBuildAttempts();
    lot->setUniqueID(item->uniqueID());

    this->state_310 = 0;
    ConstructionItem* finalLot = new ConstructionItem(lot);
    finalLot->setTypeID(item->typeID());

    ConstructionItem* p = tempLots.next;
    while (p != &tempLots && p != 0) {
        ConstructionItem* px = p->next;
        delete p;
        p = px;
    }

    return finalLot;
}
