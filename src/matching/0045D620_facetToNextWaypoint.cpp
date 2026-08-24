#ifndef MOVE_OBJ_CANONICAL_TU
class Waypoint {
public:
    char gap_00[0x0C];
    unsigned char facetToNextWaypoint;
};

class Path {
public:
    Waypoint* currentWaypoint();
};

class RGE_Moving_Object {
public:
    char gap_00[0xA4];
    Path pathValue;

    unsigned char facetToNextWaypoint() const;
};
#endif

unsigned char RGE_Moving_Object::facetToNextWaypoint() const {
    Waypoint* waypoint;

    waypoint = ((Path*)&this->pathValue)->currentWaypoint();
    if (waypoint != 0) {
        waypoint = ((Path*)&this->pathValue)->currentWaypoint();
        return waypoint->facetToNextWaypoint;
    }
    return 0xFF;
}
