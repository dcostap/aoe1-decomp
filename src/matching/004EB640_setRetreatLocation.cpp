#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint { float x; float y; float z; };
class TacticalAIGroup {
public:
    char gap_0[0x1AC];
    Waypoint retreatLocationValue;
    void setRetreatLocation(float a, float b, float c);
};
#endif

void TacticalAIGroup::setRetreatLocation(float a, float b, float c) {
    this->retreatLocationValue.x = a;
    this->retreatLocationValue.y = b;
    this->retreatLocationValue.z = c;
}
