// Function: TacticalAIGroup::addAttackWaypoint
// VA: 004ED060
// Source: taitacmd.cpp lines 1636-1643
// Attempt log:
// - Replaced old cdecl stub with a real C++ member function.  Member functions
//   naturally use ECX=this and ret 8 in VC5; no explicit __thiscall keyword is
//   needed or allowed.

struct Waypoint3D {
    float x;
    float y;
    float z;
    float pad;
};

class TacticalAIGroup {
public:
    char pad_00[0x1D4];
    unsigned char numberAttackWaypointsValue;
    char pad_1D5[3];
    Waypoint3D attackWaypoints[14];

    void addAttackWaypoint(float x, float y);
};

void TacticalAIGroup::addAttackWaypoint(float x, float y)
{
    if (this->numberAttackWaypointsValue < 14) {
        this->attackWaypoints[this->numberAttackWaypointsValue].x = x;
        this->attackWaypoints[this->numberAttackWaypointsValue].y = y;
        this->attackWaypoints[this->numberAttackWaypointsValue].z = 1.0f;
        this->numberAttackWaypointsValue = this->numberAttackWaypointsValue + 1;
    }
}
