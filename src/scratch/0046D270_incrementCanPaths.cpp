#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_0[0x11DCC4];
    int field_11DCC4;
    void incrementCanPaths();
};
#endif

void PathingSystem::incrementCanPaths() {
    this->field_11DCC4++;
}
