// 004E1D10 TribeInformationAIModule::findStagingPoint
// Attempt log:
// try 1: direct reconstruction from packet/decompiler; focus on call set, stack locals, nested scan topology.
// try 2: initial direct __ftol placeholder compiled too small (.text 1072 vs 1219), because distance expression optimized away/under-modeled.
// try 3: changed distance to natural `(int)sqrt((double)d2)`, producing closer size (.text 1200 vs 1219) but still too short to compare.
// try 4: tested a volatile pad sink to inflate frame/size; worsened to .text 1168, rolled back.
// try 5: tested /GX: no effect on 1200-byte no-EH body; rolled back.
// try 6: tested /O1: much smaller (.text 922), rolled back.
// shardB5: added the proven virtual gap before canPlace and removed one later
// padding slot, restoring canPlace +0x114 and findDrop +0x1B0.
// shardB5: modeled md->aiPlayer->visible and md->player->world->map; this
// improved the typed map ownership basin from 1189 to 1198 bytes.
// shardB5: direct tile guards improved block topology and retained the clean
// source; a promoted p3 local produced duplicate code and was rolled back.
// shardB5: inlined distance computation changed the frame to 0x68 and was
// rolled back. Best current source is 1196 bytes, frame 0x6C, 902-byte diff.
// shardB6: restored ObjectMemory z at +0x0A and owner at +0x0B from the
// taiinfmd first-hunk byte loads; natural typed ownership improved 902 to 900.
// orch-4E1D10-a: explicit outer good gating with a bound-first inner scan
// improved the current reconstruction to 1204 bytes, 867-byte diff, and
// 72.54% shape. This is the retained structural best.
// orch-4E1D10-a: combining distance, random, and findDrop in one expression
// kept findDrop before random and introduced two call replacements; rolled back.
// orch-4E1D10-a: explicit main do/while scans followed the Ghidra back-edges
// and improved shape to 75.53%, but shrank the body to 1178 bytes; rolled back.
// orch-4E1D10-a: parameter-home reuse, explicit sqrt intrinsic context, and
// removing the unused third point were codegen duplicates.
// pass-2026-08-17: ran 25 meaningful source/codegen probes.  Separate LOS and
// attack penalty locals recovered the original 1219-byte size, all 20 calls,
// 0x6C frame, and 85.11% shape; the positional diff is 765 bytes.
// The original distance conversion occurs before debug_rand and findDrop only
// when the direct squared-distance form is used, but that form drops the frame
// to 0x68 and loses the main body shape.  Incoming p.x cursor reuse and the
// donor canPlace float ordering improved local islands but did not combine
// with the exact-size penalty form.  Keep the exact-size penalty form here.
// Remaining evidence: the first mismatch is the target spill home; late
// scoring still uses ESI as the accumulator while the original uses EAX.
// left in scratch: behavior skeleton has the right call set and nested scan,
// but is not exact or accepted drift.  Recover target-home coalescing and the
// late score accumulator without fake volatility or compiler steering.
// pass-2026-08-22: the natural map-before-visible alias order reduced the
// positional diff from 765 to 758 bytes without changing size, frame, calls,
// or CFG counts.  Reversing the canPlace float source arguments kept 758 bytes
// and improved shape from 85.11% to 85.64%; retain both forms for the next pass.

typedef unsigned char uchar;
struct XYPoint { int x; int y; };
struct ObjectMemory {
    int id;
    short mid;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
};

class RGE_Visible_Map { public: unsigned char get_visible(int x, int y); };
class RGE_Static_Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68();
    virtual int canPlace(float y, float x, int flag); // +114
    virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
    virtual int findDrop(XYPoint* a, XYPoint* b, float c, XYPoint* d, int e); // +1B0
    int findClosestPointInTerrainType(XYPoint p, XYPoint* out, int type, int terrain, int radius);
    unsigned char lookupZone(int x, int y);
};
class RGE_PlayerLike {
public:
    char gap0[0x38];
    RGE_Visible_Map* visible;
};
struct RGE_MapLike { char gap[0x8D8C]; int** rows; };
struct RGE_WorldLike { char gap[0x28]; RGE_MapLike* map; };
struct TribePlayerLike { char gap[0x3C]; RGE_WorldLike* world; };
class MainDecisionAIModule {
public:
    char gap0[0xF0];
    RGE_PlayerLike* aiPlayer;
    char gapf4[0x12478];
    TribePlayerLike* player;
    RGE_Static_Object* object(int id);
};
class InfluenceMap { public: int lookupValue(int x, int y); };
extern InfluenceMap losMap;
extern InfluenceMap attackMap;
extern int debug_rand(char*, int);
extern "C" double sqrt(double);

class TribeInformationAIModule {
public:
    char gap[0x100]; MainDecisionAIModule* md;
    ObjectMemory* objectMemory(int id);
    int isBoat(RGE_Static_Object* obj);
    int setupLOSMap(int owner, int x, int y);
    int setupAttackMap(int owner, int x, int y);
    int mapBound(XYPoint* p);
    int findStagingPoint(XYPoint p, XYPoint& out, int p3, int p4, int targetID, int radius, int objID);
};

int TribeInformationAIModule::findStagingPoint(XYPoint p, XYPoint& out, int p3, int p4, int targetID, int radius, int objID)
{
    RGE_Static_Object* unit;
    ObjectMemory* target;
    target = this->objectMemory(targetID);
    if (!target) return 0;
    unit = this->md->object(objID);
    if (!unit) return 0;

    int terrainType, terrain;
    if (this->isBoat(unit) == 1 && p3 == 0) { terrainType = 1; terrain = 0x16; }
    else { terrainType = 2; terrain = 0; }

    XYPoint zoneRefPoint;
    zoneRefPoint.x = p.x; zoneRefPoint.y = p.y;
    unit->findClosestPointInTerrainType(p, &zoneRefPoint, terrainType, terrain, 4);
    unsigned char zone = unit->lookupZone(zoneRefPoint.x, zoneRefPoint.y);

    int maxLOSValue = this->setupLOSMap(target->owner, target->x, target->y);
    int maxAttackValue = this->setupAttackMap(target->owner, target->x, target->y);
    XYPoint min, max, targetPoint;
    min.x = (int)target->x - radius; min.y = (int)target->y - radius; this->mapBound(&min);
    max.x = (int)target->x + radius; max.y = (int)target->y + radius; this->mapBound(&max);
    targetPoint.x = target->x; targetPoint.y = target->y; this->mapBound(&targetPoint);

    RGE_PlayerLike* aiPlayer = this->md->aiPlayer;
    TribePlayerLike* player = this->md->player;
    int bestValue;
    RGE_MapLike* map = player->world->map;
    RGE_Visible_Map* vis = aiPlayer->visible;
    bestValue = -1;

    for (int y = min.x; y <= max.x; ++y) {
        int rowoff = y * 0x18;
        for (int x = min.y; x <= max.y; ++x) {
            unsigned char tile = (unsigned char)(*((unsigned char*)map->rows[x] + rowoff + 5) & 0x1f);
            vis->get_visible(y, x);
            if (p3 == 1) {
                if (tile != 2) continue;
            } else if (p4 == 1) {
                if (tile == 1 || tile == 0x16) continue;
            } else if (p4 == 0 && tile != 1 && tile != 0x16) {
                continue;
            }
            if (unit->lookupZone(y, x) != zone) continue;
            if (p3 == 1) {
                XYPoint passMin, passMax;
                passMin.x = y - 2; passMin.y = x - 2; this->mapBound(&passMin);
                passMax.x = y + 2; passMax.y = x + 2; this->mapBound(&passMax);
                int good = 1;
                for (int yy = passMin.x; yy <= passMax.x; ++yy) {
                    if (good) {
                        int off = yy * 0x18;
                        for (int xx = passMin.y; xx <= passMax.y && good; ++xx) {
                        unsigned char t = (unsigned char)(*((unsigned char*)map->rows[xx] + off + 5) & 0x1f);
                            if (t != 1 && t != 0x16 && unit->canPlace((float)yy, (float)xx, 1) == 0) good = 0;
                        }
                    }
                }
                if (!good) continue;
            }
            int dx = target->x - y;
            int dy = target->y - x;
            int d2 = dx * dx + dy * dy;
            int dist = (int)sqrt((double)d2);
            int rnd = debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x1b3f) % (radius * 3);
            XYPoint a, b;
            a.x = y; a.y = x;
            int found = unit->findDrop(&a, &targetPoint, 1.0f, &b, 1);
            int losPenalty;
            int attackPenalty;
            losPenalty = 0;
            if (maxLOSValue > 0)
                losPenalty = -(losMap.lookupValue(y, x) * radius / maxLOSValue);
            attackPenalty = 0;
            if (maxAttackValue > 0)
                attackPenalty = -(attackMap.lookupValue(y, x) * radius / maxAttackValue);
            int v = attackPenalty + losPenalty;
            v += found != 1 ? radius : 0;
            v += dist;
            v += rnd;
            if (bestValue == -1 || bestValue < v) { bestValue = v; out.x = y; out.y = x; }
        }
    }
    return bestValue != -1;
}
