// 004DEBA0 TribeInformationAIModule::findGatherPosition
// Attempt log:
// 1: natural decompiler reconstruction using local XYPoint layout and raw virtual calls for object collision/line collision.
// 2: __thiscall function-pointer casts failed under VC5 C4234, replaced with cdecl raw vtable calls (asm pushes object explicitly).
// 3: first compiling attempt had the correct high-level call set and many matching arithmetic islands, but frame 0x50 vs original 0x54.
// 4: parameter order/registers mostly aligned after prologue except the min/max comparison polarity.
// 5: setupInfluenceMap/mapBound/groupInfluenceDimension were initially represented as member calls with pointer stubs.
// 6: stack-slot placement for XYPoint locals differed; early mapBound locals landed at [esp+30]/[esp+20] instead of original [esp+3C]/[esp+2C].
// 7: exclusion-box predicate compiled behaviorally but used register-left comparisons instead of the original memory-left form.
// 8: object virtual collision and line collision calls use observed vtable slots +0x114/+0x1B0 and float push order.
// 9: no inline asm or custom flags tried.
// 10: retained in scratch; the remaining mismatch is source/layout/codegen, not accepted drift.
// Session sa24955f58r1:
// - typed the two object vtable calls as __thiscall virtual methods; this removed caller cleanup and matched the observed indirect-call ABI.
// - changed mapBound/setupInfluenceMap to XYPoint-reference declarations, restoring the original decorated direct-call identities.
// - `maxDistance >= minDistance` reproduces the initial cmp edi,esi/jl guard; memory-left exclusion predicates reproduce two oracle blocks.
// - XYPoint y,x layout, scalar/point declaration reorderings, and same-TU nonvirtual object declarations did not resolve the frame/local basin.
// - bool blocked was tested and rolled back: it removed the one-byte size overflow but worsened the codegen basin.
// Best retained reconstruction: typed virtual/reference ABI and natural nested scans with named XYPoint ownership; frame remains 0x50 vs 0x54.

typedef unsigned char uchar;
struct XYPoint { int x; int y; };
class InfluenceMap { public: int lookupValue(int x, int y); };
extern InfluenceMap iMap;

class RGE_Static_Object {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B();
    virtual void v1C(); virtual void v1D(); virtual void v1E(); virtual void v1F();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v2A(); virtual void v2B();
    virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44();
    virtual int canPlace(float y, float x, int one); // vtable slot +0x114
    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D();
    virtual void v5E(); virtual void v5F(); virtual void v60(); virtual void v61();
    virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v6A(); virtual void v6B();
    virtual int lineCollision(XYPoint* cPosition, XYPoint* from, float distance,
                              XYPoint* linePoint, int one); // vtable slot +0x1B0
};

class TribeInformationAIModule {
public:
    int mapBound(XYPoint& p);
    void setupInfluenceMap(int a, int b, XYPoint& p, XYPoint& minp, XYPoint& maxp);
    int groupInfluenceDimension(int v);
    int findGatherPosition(XYPoint& p, int group, int clearDistance, int minDistance, int maxDistance, RGE_Static_Object* obj, XYPoint& out);
};

int TribeInformationAIModule::findGatherPosition(XYPoint& p, int group, int clearDistance, int minDistance, int maxDistance, RGE_Static_Object* obj, XYPoint& out)
{
    XYPoint maxClear;
    XYPoint max;
    XYPoint minClear;
    XYPoint min;
    XYPoint minExclude;
    XYPoint maxExclude;
    XYPoint cPosition;
    XYPoint lineCollisionPoint;
    int bestPointValue;
    int j;
    int i;
    int halfDistance;
    int blocked;
    int yy;
    int xx;
    int yy2;
    int xx2;

    if (maxDistance >= minDistance) return 0;
    min.y = p.x - minDistance - maxDistance;
    minExclude.x = p.y - minDistance - maxDistance;
    mapBound(min);
    max.y = p.x + maxDistance + minDistance;
    minClear.x = p.y + maxDistance + minDistance;
    mapBound(max);
    minExclude.y = p.x - minDistance + maxDistance;
    maxExclude.x = p.y + maxDistance - minDistance;
    mapBound(minExclude);
    maxExclude.y = p.x - maxDistance + minDistance;
    cPosition.x = p.y + minDistance - maxDistance;
    mapBound(maxExclude);
    setupInfluenceMap(0, -1, p, min, max);
    bestPointValue = -1;
    maxClear.x = groupInfluenceDimension(group);
    for (j = min.y; j <= max.y; j++) {
        for (i = minExclude.x; i <= minClear.x; i++) {
            if (minExclude.y > j || j > maxExclude.y || maxExclude.x > i || i > cPosition.x) {
                halfDistance = maxClear.x / 2;
                minClear.y = j - halfDistance;
                min.x = i - halfDistance;
                if (mapBound(minClear) != 1) {
                    maxClear.y = j + halfDistance;
                    max.x = i + halfDistance;
                    if (mapBound(maxClear) != 1) {
                        blocked = 0;
                        for (yy = minClear.y; yy < maxClear.y && !blocked; yy++) {
                            for (xx = min.x; xx < max.x && !blocked; xx++) {
                                if (obj->canPlace((float)yy, (float)xx, 1) == 0) blocked = 1;
                            }
                        }
                        if (blocked != 1) {
                            int val = 0x80;
                            cPosition.y = j;
                            lineCollisionPoint.x = i;
                            if (obj->lineCollision(&cPosition, &p, (float)minDistance,
                                                   &lineCollisionPoint, 1) == 0) val = 0x40;
                            for (yy2 = minClear.y; yy2 <= maxClear.y && !blocked; yy2++) {
                                for (xx2 = min.x; xx2 <= max.x && !blocked; xx2++) {
                                    int v = iMap.lookupValue(yy2, xx2);
                                    if (v == 0xff) blocked = 1; else val += v;
                                }
                            }
                            if (blocked != 1 && (bestPointValue == -1 || bestPointValue < val)) {
                                bestPointValue = val;
                                out.x = j;
                                out.y = i;
                            }
                        }
                    }
                }
            }
        }
    }
    return bestPointValue != -1;
}
