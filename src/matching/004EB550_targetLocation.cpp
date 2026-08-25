#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint { int data[3]; };
#endif
#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[392];
    Waypoint targetLocation_;

    const Waypoint & targetLocation() const;
};
#endif
const Waypoint & TacticalAIGroup::targetLocation() const { return this->targetLocation_; }
