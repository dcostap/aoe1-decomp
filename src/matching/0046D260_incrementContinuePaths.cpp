#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_0[0x11DCC0];
    int numContinuePathsValue;
    void incrementContinuePaths();
};
#endif

void PathingSystem::incrementContinuePaths() {
    ++numContinuePathsValue;
}
