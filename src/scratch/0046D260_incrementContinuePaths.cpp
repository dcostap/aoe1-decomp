#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_0[0x11DCC0];
    int field_11DCC0;
    void incrementContinuePaths();
};
#endif

void PathingSystem::incrementContinuePaths() {
    this->field_11DCC0++;
}
