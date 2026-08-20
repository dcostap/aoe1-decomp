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
// - explicit outer do/while scans were tested from the repeated PDB loop bands; VC5 emitted the same bytes as the clean for-loop source, so no new lead was found.
// - PDB declaration-order and first-bound assignment-order probes were codegen-neutral or worse; both were rolled back.
// - field-address mapBound/setup/lineCollision casts improved edit resync but kept the 0x50 frame and 647-byte positional diff; the casts were rolled back as decompiler-shaped.
// Best retained reconstruction: typed virtual/reference ABI and natural nested scans with named XYPoint ownership; frame remains 0x50 vs 0x54.
// The explicit outer do/while spelling was tested and emitted the same code as
// the clean for-loop source. The source stays with the simpler natural form.
//
// Current pass sa-d3dbc29b-r1:
// - Baseline was 746 bytes, frame 0x50 versus 0x54, 11 aligned calls, diff 647.
// - Scalar-before-point declarations and point declaration permutations were
//   codegen-neutral. Function-scope score and lookup temporaries were neutral.
// - Early best-value initialization worsened the diff to 701 bytes.
// - Explicit while scans were duplicate. Guarded do/while influence scans made
//   the body 754 bytes; the strict diff fell to 613 but CFG and size worsened.
// - A negated in-box conjunction worsened shape and exact-block coverage.
// - Replaced fake object slots with the repository-local RGE_Static_Object
//   surface. Real passableTile and canLinePath slots reduced the diff to 406
//   bytes and restored the 745-byte size and all 11 ordered calls.
// - VC5 selected slot 0x1AC when both old canLinePath overloads had that name.
//   The local six-argument slot name canLinePathByInts keeps the proven 0x1B0
//   XYPoint call without a cast or manual vtable. The same-name and void*
//   overload variants returned to slot 0x1AC.
// - A named collision-distance local, bool blocked, assignment-order changes,
//   and group-sentinel order did not improve the 406-byte canonical basin.
// - A two-variant declaration lab confirmed both point orders emit one 745-byte
//   group with the same 395-byte positional diff and frame 0x50.
// Current clean candidate remains scratch: diff 406 (54.4966%), shape 76.45%,
// frame 0x50 versus 0x54, 11/11 ordered calls, and no policy-valid exact match.
// Review blocker: the four-byte frame gap moves address-taken XYPoint locals
// passed to mapBound, setupInfluenceMap, and line/path calls. This changes
// external pointer values and the ESP context of all 11 calls, so the gap is
// not eligible as private local-home drift.

typedef unsigned char uchar;
struct XYPoint { int x; int y; };
class InfluenceMap { public: int lookupValue(int x, int y); };
extern InfluenceMap iMap;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, void*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, uchar);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, uchar);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(void*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, void*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, void*, float, void*, RGE_Static_Object* = 0);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, uchar);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(void*, uchar, int);
    virtual void unexplore_terrain(void*, uchar, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float y, float x, int one); // vtable slot +0x114
    virtual uchar facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(uchar);
    virtual uchar waitingToMove();
    virtual uchar actionState();
    virtual uchar keepGatheringWhenObjectIsOut(int);
    virtual uchar produceWhenKilledBy(int);
    virtual uchar useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePathByInts(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint* cPosition, XYPoint* from, float distance,
                            XYPoint* linePoint, int one); // vtable slot +0x1B0
    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
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
    XYPoint max;
    XYPoint maxClear;
    XYPoint min;
    XYPoint minClear;
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
    j = min.y;
    if (j <= max.y) do {
        i = minExclude.x;
        if (i <= minClear.x) do {
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
                                if (obj->passableTile((float)yy, (float)xx, 1) == 0) blocked = 1;
                            }
                        }
                        if (blocked != 1) {
                            int val = 0x80;
                            cPosition.y = j;
                            lineCollisionPoint.x = i;
                            if (obj->canLinePath(&cPosition, &p, (float)minDistance,
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
            i++;
        } while (i <= minClear.x);
        j++;
    } while (j <= max.y);
    return bestPointValue != -1;
}
