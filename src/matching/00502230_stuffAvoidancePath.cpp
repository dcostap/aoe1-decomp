#ifndef TAITACMD_SHARED_CONTEXT
// 00502230 TribeTacticalAIModule::stuffAvoidancePath
// PDB: taitacmd.cpp:12551-12604, 224 bytes
// void __thiscall stuffAvoidancePath(TacticalAIGroup* group, Path* path)
// ret 8 (2 params)
// FLAGS: default
//
// Attempt log:
// - Baseline reconstruction (canonical): divisionLength = length()*0.2f clamped to
//   10.0f; flag tooFew = (numberOfWaypoints() <= 5); loop i=1..count-1 adding an
//   attack waypoint when (tooFew || accumDist >= divisionLength) && (tooFew != 1
//   || accumDist >= 5.0f). The cmp edi,1 in the second clause requires the
//   "tooFew != 1" spelling (nested if/else forms emit no second edi test).
// - addAttackWaypoint takes floats; the call site evaluates currentWaypoint()
//   twice (right-to-left): addAttackWaypoint(currentWaypoint()->x, currentWaypoint()->y).
// - do/while + `int count` local -> tooFew in ebx / i in edi (wrong basin) and
//   VC5 shortened the 2nd fnstsw test to `test bl,ah`; for-loop form fixed the
//   registers AND the mask (tooFew->edi, i->ebx, `test ah,1`) but kept `inc` in
//   the loop-increment slot (after moveToNextWaypoint).
// - EXACT: while (i < numberOfWaypoints()-1) with i++ as a BODY statement placed
//   before moveToNextWaypoint schedules `inc ebx` inside the fadd/fstp gap,
//   matching the original tail exactly. 0.0000% diff.
// - switch(tooFew) case0/1/default fell into jump-table lowering (worse); not kept.

#ifndef TAITACMD_SHARED_CONTEXT
class Waypoint {
public:
    float x;      // +0x00
    float y;      // +0x04
};

class Path {
public:
    float length();
    void initToStart();
    float distanceToNextWaypoint();
    int moveToNextWaypoint();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();
};

class TacticalAIGroup {
public:
    void addAttackWaypoint(float x, float y);
};

class TribeTacticalAIModule {
public:
    void stuffAvoidancePath(TacticalAIGroup* group, Path* path);
};

#endif
void TribeTacticalAIModule::stuffAvoidancePath(TacticalAIGroup* group, Path* path)
{
    float divisionLength = path->length() * 0.2f;
    if (divisionLength < 10.0f)
        divisionLength = 10.0f;

    path->initToStart();
    float accumDist = path->distanceToNextWaypoint();
    path->moveToNextWaypoint();

    int tooFew = 0;
    if (path->numberOfWaypoints() <= 5)
        tooFew = 1;

    int i = 1;
    while (i < path->numberOfWaypoints() - 1) {
        if ((tooFew || accumDist >= divisionLength) &&
            (tooFew != 1 || accumDist >= 5.0f)) {
            group->addAttackWaypoint(path->currentWaypoint()->x,
                                     path->currentWaypoint()->y);
        }

        accumDist += path->distanceToNextWaypoint();
        i++;
        path->moveToNextWaypoint();
    }
}
#else
void TribeTacticalAIModule::stuffAvoidancePath(TacticalAIGroup*, Path*) {}
#endif
