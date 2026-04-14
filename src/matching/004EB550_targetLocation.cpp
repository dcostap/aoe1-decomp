struct Waypoint { int data[3]; };
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[392];
    Waypoint targetLocation_;

    const Waypoint & targetLocation() const;
};
const Waypoint & TacticalAIGroup::targetLocation() const { return this->targetLocation_; }
