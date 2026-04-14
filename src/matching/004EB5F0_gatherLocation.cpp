struct Waypoint { int data[3]; };
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[408];
    Waypoint gatherLocation_;

    const Waypoint & gatherLocation() const;
};
const Waypoint & TacticalAIGroup::gatherLocation() const { return this->gatherLocation_; }
