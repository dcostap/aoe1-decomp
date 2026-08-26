// From taitacmd.cpp
// The location fields are Waypoint float members in the canonical class.
// This preserves direct float stores in the grouped wrapper.
// Final grouped audit: MATCH, 0.0000%, 93/93 bytes.

#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char pad_0D[3];
};

class TacticalAIGroup {
public:
    char gap_00[0x170];
    Waypoint locationValue;
    char gap_180[0x1C];
    Waypoint gatherLocationValue;
    Waypoint retreatLocationValue;

    void setAllLocations(float p1, float p2, float p3);
};
#endif

void TacticalAIGroup::setAllLocations(float p1, float p2, float p3) {
    this->locationValue.x = p1;
    this->locationValue.y = p2;
    this->locationValue.z = p3;
    this->gatherLocationValue.x = p1;
    this->gatherLocationValue.y = p2;
    this->gatherLocationValue.z = p3;
    this->retreatLocationValue.x = p1;
    this->retreatLocationValue.y = p2;
    this->retreatLocationValue.z = p3;
}
