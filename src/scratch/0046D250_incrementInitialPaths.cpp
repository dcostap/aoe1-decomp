#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_0[0x11DCBC];
    int field_11DCBC;
    void incrementInitialPaths();
};
#endif

void PathingSystem::incrementInitialPaths() {
    this->field_11DCBC++;
}
