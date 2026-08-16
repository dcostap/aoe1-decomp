// incrementHitPoints (0040A710, 15 bytes, aibobj.cpp)
// this->hitPointValue += value;
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[116];
    int hitPoints_;

    void incrementHitPoints(int);
};

void BaseObject::incrementHitPoints(int value) {
    this->hitPoints_ += value;
}
