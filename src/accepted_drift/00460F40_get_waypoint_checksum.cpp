// VA: 00460F40 get_waypoint_checksum
// move_obj.cpp lines 3173-3183, 119 bytes
// RGE_Moving_Object::get_waypoint_checksum()
// Attempt log:
// - Initial scratch inlined Path fields and was wrong-size (96-byte text).
// - Reintroduced Path member calls: now 119/119 bytes with correct call/control flow,
//   stack local, loop shape, and restoration call.
// - Remaining 11-byte diff is register allocation/FPU operand order only: rebuilt uses
//   EBP for saved waypoint index and EBX for the loop waypoint pointer, while original
//   uses EBX for saved index and EBP for waypoint pointer. The inner sum is equivalent
//   (`fld [eax]; fadd [ebx+4]` vs original `fld [ebp+4]; fadd [eax]`). Push/pop and
//   final setCurrentWaypointNumber use the correspondingly swapped saved register.
// - Tried declaration reordering, register savedIndex, expression order, and non-virtual
//   RGE_Moving_Object surface; no register allocation change.
// - Strong accepted_drift candidate: behavior/calls/stack cleanup/control flow match;
//   drift is benign register allocation plus commutative FPU add ordering.
// - 2026-05-10 SpruceGlow Boss-assigned pass: tried 15 variants: plain vs register saved index,
//   expression operand order, two explicit waypoint locals, reverse expression order, count local,
//   for/while loops, split sum statements, volatile/unsigned saved index, volatile waypoint, and
//   extra saved-index temp. No exact. Two-waypoint-local forms improve to 8 positional/8 edit diff:
//   original still uses EBX for saved index and EBP for waypoint pointer, while rebuilt uses EBP for
//   saved index and EBX for waypoint pointer; FPU add order is now otherwise original-equivalent.
// ACCEPTED_DRIFT: reviewed by Boss. Same size, same call sequence/control flow/stack cleanup and same arithmetic result. Remaining byte drift is benign EBX/EBP allocation swap for saved waypoint index vs loop waypoint pointer, with corresponding push/pop and addressing-register encodings only; no predicate, memory-effect, or FPU semantic change.

struct Waypoint {
    float x, y, z;
    unsigned char facet;
    unsigned char pad[3];
};

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    int currentWaypointNumber();
    void initToStart();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();
    int moveToNextWaypoint();
    void setCurrentWaypointNumber(int n);
};

class RGE_Moving_Object {
public:
    void* vptr;
    char gap0[0xA0];
    Path pathValue;          // +0xA4
    
    int get_waypoint_checksum();
};

extern "C" long __cdecl _ftol(void);

int RGE_Moving_Object::get_waypoint_checksum(){ float sum=0.0f; register int savedIndex; Path* path=&this->pathValue; savedIndex=path->currentWaypointNumber(); path->initToStart(); int i=0; if(path->numberOfWaypoints()>0){ do{ Waypoint* wp1=path->currentWaypoint(); Waypoint* wp2=path->currentWaypoint(); sum += wp1->y + wp2->x; i++; path->moveToNextWaypoint(); }while(i<path->numberOfWaypoints()); } path->setCurrentWaypointNumber(savedIndex); return (int)sum;}
