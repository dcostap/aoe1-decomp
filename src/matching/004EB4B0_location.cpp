#ifndef TAITACMD_SHARED_CONTEXT
struct Waypoint { int data[3]; };
#endif
#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[364];
    Waypoint location_;

    const Waypoint & location() const;
};
#endif
const Waypoint & TacticalAIGroup::location() const { return this->location_; }
