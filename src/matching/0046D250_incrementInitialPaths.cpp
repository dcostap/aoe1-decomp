#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_0[0x11DCBC];
    int numInitialPathsValue;
    void incrementInitialPaths();
};
#endif

void PathingSystem::incrementInitialPaths() {
    ++numInitialPathsValue;
}
