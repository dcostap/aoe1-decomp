#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint { int data[3]; };
#endif
#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[424];
    Waypoint retreatLocation_;

    const Waypoint & retreatLocation() const;
};
#endif
const Waypoint & TacticalAIGroup::retreatLocation() const { return this->retreatLocation_; }
