// 004DEBA0 TribeInformationAIModule::findGatherPosition
// Attempt log:
// 1: natural decompiler reconstruction using local XYPoint layout and raw virtual calls for object collision/line collision.
// 2: __thiscall function-pointer casts failed under VC5 C4234, replaced with cdecl raw vtable calls (asm pushes object explicitly).
// 3: first compiling attempt has correct high-level call set and many matching arithmetic islands, but frame is 0x50 vs original 0x54.
// 4: parameter order/registers mostly align after prologue except min/max comparison polarity (cmp esi,edi/jg vs cmp edi,esi/jl).
// 5: setupInfluenceMap/mapBound/groupInfluenceDimension represented as member calls with relocations masked.
// 6: stack-slot placement for XYPoint locals differs; early mapBound locals land at [esp+30]/[esp+20] instead of original [esp+3C]/[esp+2C].
// 7: exclusion-box predicate compiles behaviorally but compare operand/polarity differs from original memory-vs-register form.
// 8: object virtual collision and line collision calls use observed vtable slots +0x114/+0x1B0 and float push order is plausible.
// 9: no inline asm or custom flags tried.
// 10: left in scratch; needs deliberate stack-local/source-shape work before exact matching, not accepted_drift.

typedef unsigned char uchar;
struct XYPoint { int x; int y; };
class RGE_Static_Object { public: virtual void pad000(); };
class InfluenceMap { public: int lookupValue(int x, int y); };
extern InfluenceMap iMap;

#define VTBL(obj) (*(void***)(obj))
#define OBJ_CHECK(obj, fy, fx, one) ((int (__cdecl*)(void*, float, float, int))VTBL(obj)[0x45])((obj),(fy),(fx),(one))
#define OBJ_LINE(obj, cpos, from, dist, line, one) ((int (__cdecl*)(void*, XYPoint*, XYPoint*, float, XYPoint*, int))VTBL(obj)[0x6C])((obj),(cpos),(from),(dist),(line),(one))

class TribeInformationAIModule {
public:
    int mapBound(XYPoint* p);
    void setupInfluenceMap(int a, int b, XYPoint* p, XYPoint* minp, XYPoint* maxp);
    int groupInfluenceDimension(int v);
    int findGatherPosition(XYPoint& p, int group, int clearDistance, int minDistance, int maxDistance, RGE_Static_Object* obj, XYPoint& out);
};

int TribeInformationAIModule::findGatherPosition(XYPoint& p, int group, int clearDistance, int minDistance, int maxDistance, RGE_Static_Object* obj, XYPoint& out)
{
    int bestPointValue;
    int blocked;
    int i;
    int j;
    int d;
    XYPoint maxClear;
    XYPoint max;
    XYPoint minClear;
    XYPoint min;
    XYPoint minExclude;
    XYPoint maxExclude;
    XYPoint cPosition;
    XYPoint lineCollisionPoint;

    if (minDistance <= maxDistance) return 0;
    min.y = p.x - minDistance - maxDistance;
    minExclude.x = p.y - minDistance - maxDistance;
    mapBound(&min);
    max.y = p.x + maxDistance + minDistance;
    minClear.x = p.y + maxDistance + minDistance;
    mapBound(&max);
    minExclude.y = p.x - minDistance + maxDistance;
    maxExclude.x = p.y + maxDistance - minDistance;
    mapBound(&minExclude);
    maxExclude.y = p.x - maxDistance + minDistance;
    cPosition.x = p.y + minDistance - maxDistance;
    mapBound(&maxExclude);
    setupInfluenceMap(0, -1, &p, &min, &max);
    bestPointValue = -1;
    maxClear.x = groupInfluenceDimension(group);
    for (j = min.y; j <= max.y; j++) {
        for (i = minExclude.x; i <= minClear.x; i++) {
            if (j < minExclude.y || j > maxExclude.y || i < maxExclude.x || i > cPosition.x) {
                d = maxClear.x / 2;
                minClear.y = j - d;
                min.x = i - d;
                if (mapBound(&minClear) != 1) {
                    maxClear.y = j + d;
                    max.x = i + d;
                    if (mapBound(&maxClear) != 1) {
                        blocked = 0;
                        for (int yy = minClear.y; yy < maxClear.y && !blocked; yy++) {
                            for (int xx = min.x; xx < max.x && !blocked; xx++) {
                                if (OBJ_CHECK(obj, (float)yy, (float)xx, 1) == 0) blocked = 1;
                            }
                        }
                        if (blocked != 1) {
                            int val = 0x80;
                            cPosition.y = j;
                            lineCollisionPoint.x = i;
                            if (OBJ_LINE(obj, &cPosition, &p, (float)minDistance, &lineCollisionPoint, 1) == 0) val = 0x40;
                            for (int yy2 = minClear.y; yy2 <= maxClear.y && !blocked; yy2++) {
                                for (int xx2 = min.x; xx2 <= max.x && !blocked; xx2++) {
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
