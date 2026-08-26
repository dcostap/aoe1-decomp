#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint { float x; float y; float z; };
class TacticalAIGroup {
public:
    char gap_0[0x170];
    Waypoint locationValue;
    void setLocation(float a, float b, float c);
};
#endif

void TacticalAIGroup::setLocation(float a, float b, float c) {
    this->locationValue.x = a;
    this->locationValue.y = b;
    this->locationValue.z = c;
}
