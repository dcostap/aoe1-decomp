struct Waypoint { int data[3]; };
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[424];
    Waypoint retreatLocation_;

    const Waypoint & retreatLocation() const;
};
const Waypoint & TacticalAIGroup::retreatLocation() const { return this->retreatLocation_; }
