#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint { float x; float y; float z; };
class TacticalAIGroup {
public:
    char gap_0[0x19C];
    Waypoint gatherLocationValue;
    void setGatherLocation(float a, float b, float c);
};
#endif

void TacticalAIGroup::setGatherLocation(float a, float b, float c) {
    this->gatherLocationValue.x = a;
    this->gatherLocationValue.y = b;
    this->gatherLocationValue.z = c;
}
