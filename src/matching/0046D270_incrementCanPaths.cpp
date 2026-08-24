#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_0[0x11DCC4];
    int numCanPathsValue;
    void incrementCanPaths();
};
#endif

void PathingSystem::incrementCanPaths() {
    ++numCanPathsValue;
}
