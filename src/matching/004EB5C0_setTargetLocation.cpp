#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint { float x; float y; float z; };
class TacticalAIGroup {
public:
    char gap_0[0x18C];
    Waypoint targetLocationValue;
    void setTargetLocation(float a, float b, float c);
};
#endif

void TacticalAIGroup::setTargetLocation(float a, float b, float c) {
    this->targetLocationValue.x = a;
    this->targetLocationValue.y = b;
    this->targetLocationValue.z = c;
}
