#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    char gap_0[0x94];
    int field_94;
    int field_98;
    int field_9C;
    void setCurrentTargetPosition(float a, float b, float c);
};
#endif

void BaseObject::setCurrentTargetPosition(float a, float b, float c) {
    this->currentTargetXPosition_ = a;
    this->currentTargetYPosition_ = b;
    this->currentTargetZPosition_ = c;
}
