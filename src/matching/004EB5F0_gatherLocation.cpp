#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint { int data[3]; };
#endif
#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[408];
    Waypoint gatherLocation_;

    const Waypoint & gatherLocation() const;
};
#endif
const Waypoint & TacticalAIGroup::gatherLocation() const { return this->gatherLocation_; }
