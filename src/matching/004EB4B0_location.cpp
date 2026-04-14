struct Waypoint { int data[3]; };
class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[364];
    Waypoint location_;

    const Waypoint & location() const;
};
const Waypoint & TacticalAIGroup::location() const { return this->location_; }
